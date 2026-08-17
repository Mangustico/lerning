import sqlite3


conn = sqlite3.connect("phonebook.db")
cursor = conn.cursor()

cursor.execute("""CREATE TABLE IF NOT EXISTS contacts(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    number TEXT NOT NULL
)""")
print("1 - show list, 2 - add new contact, 3 - change contact's number, 4 - delete contact, 5 - find contact, 6 - exit")

try:
    while True:
        try:
            command = int(input("input command: "))
        except ValueError as error:
            print(f"Error: {error}")
        else:
            if (command == 1):
                cursor.execute("SELECT name, number FROM contacts")
                rows = cursor.fetchall()
                for row in rows:
                    print(row[0], row[1])
            elif (command == 2):
                rname = input("input name: ")
                rnumber = input("input number: ")
                cursor.execute("INSERT INTO contacts (name, number) VALUES(?, ?)", (rname, rnumber))
                conn.commit()
            elif (command == 3):
                rname = input("input contact's name: ")
                rnumber = input("input new number: ")
                cursor.execute("UPDATE contacts SET number = ? WHERE name LIKE ?", (rnumber, rname))
                conn.commit()
            elif (command == 4):
                rname = input("input name: ")
                cursor.execute("DELETE FROM contacts WHERE name = ?", (rname,))
                conn.commit()
            elif (command == 5):
                rname = input("input name: ")
                cursor.execute("SELECT name, number FROM contacts WHERE name LIKE ?", (f"%{rname}%",))
                print(cursor.fetchone())
            elif (command == 6):
                print("Program finished")
                break
            else:
                print("only listed commands")

except sqlite3.Error as error:
    print(f"Program stopped with {error}")
finally:
    conn.close()