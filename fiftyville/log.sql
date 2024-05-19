-- Keep a log of any SQL queries you execute as you solve the mystery.
-- The sql code text, based on assumptions from the day the event occured, The underlying is used to find more data that can be helpful
-- as to what happened on that day and see if any direction points to the missing cs50


-- 1. Answer found is that Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery and Interviews with three witnesses


SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Humphery Street';

-- 2. Since we know the event took place at a Bakery
-- Best approach is to look at security logs of the bakery to get any information about the crime activity that took place
-- Answer found is that they were two vehicle entrances made before the crime at 10:15 however the vehicle that made exit where different from the ones that came in


SELECT activity, license_plate, year month, day, hour , minute
FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute = 15;


-- 3. From the interview logs filtering anyting regarding bakery
-- Vital information where obtained about the crime scene after the departure of the crime scene, which was about 10 mins after crime
-- Someone recognized the thief early in the morning at an ATM point which would likey have a camera
-- They made call after a minute of the robbery to leave the airport on the earliest schedule tomorrow


SELECT name, transcript
FROM interviews
WHERE year = 2023 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';


-- 4. Probing to see other vehicle that must have left from the time of the first entrance about 10:08 till 10 minutes after the incident happened which is about 10:25pm
-- SIX vehicles where found within that duration of 8 minutes after crime
-- 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE


SELECT activity, license_plate, year month, day, hour , minute
FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute > 8 AND minute < 26;

-- 5. Also futher probe into atm withdrawal transaction that happened early hours in the morning at Leggett Street
-- Result shows 8 withdrawals while ruling out the deposits.
-- 28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199


SELECT account_number, transaction_type, amount FROM atm_transactions
WHERE year = 2023 AND month = 7 AND DAY = 28 AND atm_location = "Leggett Street";

-- 6. Also futher probe into atm withdrawal transaction that happened early hours in the morning at Leggett Street and
-- comparing those details to vehicles seen at the bakery at time of the crime exit,
-- This five name have been consistent with existing data provided from plate number and account numbers
-- Bruce  | 49610011       | 94KL13X
-- Luca   | 28500762       | 4328GD8
-- Iman   | 25506511       | L93JTIZ
-- Diana  | 26013199       | 322W7JE
-- Taylor | 76054385       | 1106N58



SELECT name, atm_transactions.account_number, bakery_security_logs.license_plate bakery_security_logs.hour, bakery_security_logs.minute FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE atm_transactions.year = 2023 AND atm_transactions.month = 7
AND atm_transactions.day = 28 AND atm_transactions.atm_location = 'Leggett Street' AND
bakery_security_logs.hour > 9 AND bakery_security_logs.hour < 11 AND bakery_security_logs.minute > 9 AND bakery_security_logs.hour < 25
ORDER BY bakery_security_logs.minute;

-- Find Passenger Names for the flight
-- Three names have been shorlited while Taylor is eliminated as it doesnt support findings from the plate no. found at the ATM
-- | Bruce  |
-- | Taylor | It won't  be taylor because plate number not found at the ATM
-- | Luca   |

SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.origin_airport_id = airports.id
WHERE airports.city = 'Fiftyville'
AND flights.year = 2023 AND flights.month = 7 AND flights.day = 29 AND flights.hour = 8 AND flights.minute = 20;






-- Trying to further confirm who the thief is between Bruce and Taylor by identifying calls from the crime event.
-- Find the Names of the Callers - Bruce is the only consistent name across queries, so (Bruce is the killer.)
SELECT people.name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2023 AND phone_calls.month = 7 AND phone_calls.day = 28
AND phone_calls.duration <= 60;



-- Earliest Flight from Fiftyville Regional airport from next day after the crime took place is on 8th hour and 20th minutes

SELECT full_name, day, hour, minute FROM airports JOIN flights ON airports.id = flights.origin_airport_id
WHERE airports.city = 'Fiftyville' AND flights.year = 2023 AND flights.month = 7 AND flights.day = 29;

-- Using the above information to get details from the Destination City of the crime offenders (which is New York)
SELECT airports.city FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id = 8
AND flights.year = 2023 AND flights.month = 7 AND flights.day = 29 AND flights.hour = 8 AND flights.minute = 20;


-- Find out Bruce's number to help track the receiver of the call the crime event day.
SELECT phone_number FROM people
WHERE name = 'Bruce';

-- Run a search on the receiver of Bruce's Call to find out who the accomplice
SELECT people.name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2023 AND phone_calls.month = 7 AND phone_calls.day = 28
AND phone_calls.duration <= 60 AND phone_calls.caller = '(367) 555-5533';
