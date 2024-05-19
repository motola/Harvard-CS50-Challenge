from cs50 import get_int

while True:
     height = get_int("Height: ")
     if (height > 0 and height < 9):
        break

for hash in range (height):
    print((height - hash - 1) * " ", end="")
    print((hash + 1) * "#")
