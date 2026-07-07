import sys
import random

secret_number = random.randint(1, 100)
attempt = 0

res = 1
print("Guess the number from 1 to 100: ")

while res != 0 and attempt != 15:
    try:
        command = int(input("Your guess: "))
        attempt += 1

        if command < secret_number:
            print("its less than secret number")
        elif command > secret_number:
            print("its bigger than secret number")
        elif command == secret_number:
            res = 0
    except ValueError:
        print("Input only integer, try again")

if res == 0:
    sys.exit(f"ouright, the number is {secret_number} and you got it in {attempt} attempts")

else: sys.exit("you lose")