import sys
import json

def load_phonebook(file_name):
    try:
        with open(file_name, 'r') as f_in:
            return json.load(f_in)
    except FileNotFoundError:
        return {}

def add_contact(phonebook):
    phonebook[input("Input new contact's name: ")] = input("New contact's number: ")
    print("Contact added")

def find_contact(phonebook):
    request_name = str(input("Input contact's name: "))
    result = [name for name in phonebook if request_name.lower() in name.lower()]
    if result:
        for x in result:
            print(f"Name: {x}, number: {phonebook[x]}")
    else:
        print("This contact is not exist")

def show_list(phonebook):
    for name in phonebook:
        print(f"Name: {name} , number: {phonebook[name]}")

def delete_contact(phonebook):
    target = input("What contact you wanna delete: ")
    try:
        del phonebook[target]
    except KeyError:
        print("This contact is not exist")
    else:
        print("Contact successfully deleted")



def main():
    phonebook = load_phonebook("list.json")
    print("Commands:")
    while True:
        try:
            command = int(input("1 - add contact, 2 - find, 3 - show contact list, 4 - delete contact, 5 - exit\n"))
        except ValueError:
            print("Only announced commands are available\n")
            continue
        else:
            if command == 1:
                add_contact(phonebook)
            elif command == 2:
                find_contact(phonebook)
            elif command == 3:
                show_list(phonebook)
            elif command == 4:
                delete_contact(phonebook)
            elif command == 5:
                with open('list.json', 'w') as f_out:
                    json.dump(phonebook, f_out, indent=3, separators=(',', ':'))
                print("\nProgram is finished")
                break
            else:
                print("Only announced commands are available\n")

if __name__ == "__main__":
    main()