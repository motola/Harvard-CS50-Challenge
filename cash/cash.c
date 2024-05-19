#include <cs50.h>
#include <stdio.h>


int calc_quarters(int passedCents);
int calc_dime(int passedDime);
int calc_nickles(int passedNickels);
int calc_pennies(int passedPennies);

int main(void) {

int cents;


 do {
     cents = get_int("Changed owed? ");
 }

 while (cents < 0);
 /* printf("cent is %d\n", cents ); */


  // Calculate for quarters left
 int quarters = calc_quarters(cents);
 cents = cents - (quarters * 25);
 printf("change left is %d\n", cents );
 printf("quarter is %d\n", quarters);

 // Calculate for dime left
 int dime = calc_dime(cents);
 cents = cents - (dime * 10);
 printf("dime left is %d\n", dime);



 //Calculate for nickles left
 int nickles = calc_nickles(cents);
 cents = cents - (nickles * 5);
 printf("Nickles left is %d\n", nickles);


 //Calculate for Pennies left
 int pennies = calc_pennies(cents);
 cents = cents - (nickles * 1);
 printf("Pennies left is %d\n", pennies);


 printf("total change count is %d\n ", dime + quarters + nickles + pennies);
}

  int calc_quarters(int passedCents) {
    int quarters = 0;

    while (passedCents >= 25) {
        quarters++;
        passedCents = passedCents - 25;
    }
    return quarters;
  }


  int calc_dime(int passedDime) {
    int dime = 0;

    while (passedDime < 25 && passedDime >= 10){
      dime++;
      passedDime = passedDime - 10;
    }

    return dime;
  }


  int calc_nickles(int passedNickles) {
    int nickles = 0;

    while (passedNickles < 10 && passedNickles >= 5) {
      nickles++;

      passedNickles = passedNickles - 5;
    }
    return nickles;
  }

int calc_pennies(int passedPennies){
  int pennies = 0;


  while (passedPennies < 5 && passedPennies >= 1) {
    passedPennies = passedPennies - 1;
    pennies++;
  }
  return pennies;
}
