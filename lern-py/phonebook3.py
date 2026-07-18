import json

class Contact:
    def __init__(self, name, number):
        self.name = name
        self.number = number

    def to_dict(self):
        return {self.name:self.number}

class Phonebook:
    def __init__(self, file_name):
        self.contacts = []
        try:
            with open(file_name, "r") as f:
                cont = json.load(f)
        except FileNotFoundError:
            cont =  {}
        else:
            for name in cont:
                self.contacts.append(Contact(name, cont[name]))

    def add_contact(self, name, number):
        self.contacts.append(Contact(name, number))

    def find_contact(self, request_name):
        found = 1
        for c in self.contacts:
            if request_name in c.name:
                print(f"Name: {c.name}, number: {c.number}")
                found = 0
        if found == 1:
            print("This contact does not exist")

    def show_contacts(self):
        for c in self.contacts:
            print(f"Name: {c.name}, number: {c.number}")

    def delete_contact(self, name):
        self.contacts = [c for c in self.contacts if c.name != name]

    def save(self, file_name):
        temp_dict = {}
        for c in self.contacts:
            temp_dict.update(c.to_dict())
        with open(file_name, "w") as f:
            json.dump(temp_dict, f, indent=3, separators=(',', ':'))

def main():
    phonebook = Phonebook("list.json")
    print("Commands:")
    while True:
        try:
            command = int(input("1 - add contact, 2 - find, 3 - show contact list, 4 - delete contact, 5 - exit\n"))
        except ValueError:
            print("Only listed commands are available\n")
            continue
        else:
            if command == 1:
                req_number = input("Input new contact's number: ")
                req_name = input("Input new contact's name: ")
                phonebook.add_contact(req_name, req_number)
                phonebook.save("list.json")
            elif command == 2:
                req_name = input("Input contact's name: ")
                phonebook.find_contact(req_name)
            elif command == 3:
                phonebook.show_contacts()
            elif command == 4:
                req_name = input("Which contact do you want to delete: ")
                phonebook.delete_contact(req_name)
                phonebook.save("list.json")
            elif command == 5:
                phonebook.save("list.json")
                print("\nProgram is finished")
                break
            else:
                print("Only listed commands are available\n")

if __name__ == "__main__":
    main()