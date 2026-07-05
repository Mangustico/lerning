import sys
import random

secret_number = random.randint(1, 100)
attempt = 0

res = 1
command = int(input("Guess the number from 1 to 100: "))
attempt +=1
if command < secret_number:
    print("its less than secret number")
elif command > secret_number:
    print("its bigger than secret number")
else:
    print("ugadamnright")
    sys.exit()

while res != 0 and attempt != 15:
    command = int(input("New guess: "))
    attempt += 1

    if command < secret_number:
        print("its less than secret number")
    elif command > secret_number:
        print("its bigger than secret number")
    elif command == secret_number:
        res = 0
    else:
        print("only integer")
if res == 0:
    sys.exit(f"ouright, the number is {secret_number} and you got it in {attempt} attempts")

else: print("you lose")