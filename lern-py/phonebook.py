import sys

phonebook = {}

print("Commands:\n")
command = 0
while True:
    try:
        command = int(input("1 - add contact, 2 - found, 3 - show contact list, 4 - delete contact, 5 - exit\n"))
    except ValueError:
        print("Only announced commands is available\n")
        continue
    else:
        if command == 1:
            phonebook[str(input("Input new contact's name: "))] = str(input("New contact's number: "))
            print("Contact added")
        elif command == 2:
            request_name = str(input("Input contact's name: "))
            if request_name in phonebook:
                print(f"Name: {request_name}, number: {phonebook[request_name]}")
            else:
                print("There is no contact with this name")
        elif command == 3:
            for name in phonebook:
                print(f"Name: {name} , number: {phonebook[name]}")
        elif command == 4:
            target = str(input("What contact you wanna delete: "))
            try:
                del phonebook[target]
            except KeyError:
                print("Contact with this name is not exist")
            else:
                print("Contact successfully deleted")
        elif command == 5:
            sys.exit("\nProgram is end")
        else:
            print("Only announced commands is available\n")

