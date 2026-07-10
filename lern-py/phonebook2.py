import sys
import json

try:
    with open("list.json", 'r') as f_out:
        phonebook = json.load(f_out)
except FileNotFoundError:
    phonebook = {}

print("Commands:")
command = 0
while True:
    try:
        command = int(input("1 - add contact, 2 - find, 3 - show contact list, 4 - delete contact, 5 - exit\n"))
    except ValueError:
        print("Only announced commands are available\n")
        continue
    else:
        if command == 1:
            phonebook[input("Input new contact's name: ")] = input("New contact's number: ")
            print("Contact added")
        elif command == 2:
            request_name = str(input("Input contact's name: "))
            result = [name for name in phonebook if request_name.lower() in name.lower()]
            if result:
                for x in result:
                    print(f"Name: {x}, number: {phonebook[x]}")
            else:
                print("This contact is not exist")
        elif command == 3:
            for name in phonebook:
                print(f"Name: {name} , number: {phonebook[name]}")
        elif command == 4:
            target = input("What contact you wanna delete: ")
            try:
                del phonebook[target]
            except KeyError:
                print("This contact is not exist")
            else:
                print("Contact successfully deleted")
        elif command == 5:
            with open('list.json', 'w') as f_in:
                json.dump(phonebook, f_in, indent=3, separators=(',', ':'))
            print("\nProgram is finished")
            break
        else:
            print("Only announced commands are available\n")