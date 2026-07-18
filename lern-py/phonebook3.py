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
        for c in self.contacts:
            if request_name in c.name:
                print(f"Name: {c.name}, number: {c.number}")

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
