#include <fstream>
#include <clocale>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class student {
private:
	string name;
	int age;
	float ag;
public:

	student() {
		name = "N/A";
		age = 0;
		ag = 0;
	}

	string getName(void) {
		return name;
	}
	int getAge(void) {
		return age;
	}
	float getAg(void) {
		return ag;
	}

	void setName(string new_name) {
		name = new_name;
	}
	void setAge(int new_age) {
		age = new_age;
	}
	void setAg(float new_ag) {
		ag = new_ag;
	}
};

int main(void) {
	setlocale(LC_ALL, "Russian");
	vector<student> db;
	
	string path = "student_db.txt";
	int input = 0;
	while (input != 3) {
		cout << "Введите команду:\n1 - добавить студента, 2 - вывести базу список студентов, 3 - завершить программу" << endl;
		cin >> input;
		cin.ignore();

		if (input == 1) {
			student nStudent;

			cout << "Введите имя студента:" << endl;
			string nName;
			getline(cin, nName);
			nStudent.setName(nName);

			cout << "Введите возраст студента:" << endl;
			int nAge;
			cin >> nAge;
			cin.ignore();
			nStudent.setAge(nAge);

			cout << "Введите средний балл студента:" << endl;
			float nAg;
			cin >> nAg;
			cin.ignore();
			nStudent.setAg(nAg);

			ofstream fout;
			fout.open(path, fstream::app);
			if (!fout.is_open()) {
				cout << "Ошибка открытия файла" << endl;
				return -1;
			}

			db.push_back(nStudent);
			fout << db.back().getName()<< ' ' << db.back().getAge() << ' ' << db.back().getAg() << '\n';
			fout.close();
		}

		else if (input == 2) {
			ifstream fin;
			fin.open(path, fstream::app);
			if (!fin.is_open()) {
				cout << "Ошибка открытия файла" << endl;
				return -1;
			}
			if (db.empty()) {
				student curr;
				string str;
				int act = 1;
				cout << "\t | Список студентов| ";
				while (!fin.eof()) {
					str = "";
					if (act == 1) {
						fin >> str;
						cout << '\n' << str;
						act = 2;
						curr.setName(str);
					}
					else if (act == 2) {
						fin >> str;
						cout << ' ' << str;
						act = 3;
						curr.setAge(stoi(str));
					}
					else {
						fin >> str;
						cout << ' ' << str;
						act = 1;
						curr.setAg(stof(str));
						db.push_back(curr);
					}
					
				}
			}
			string str;
			int act = 1;
			while (!fin.eof()) {
				str = "";
				if (act == 1) {
					fin >> str;
					cout << str << ' ';
					act = 2;
				}
				else if (act == 2) {
					fin >> str;
					cout << str << ' ';
					act = 3;
				}
				else {
					fin >> str;
					cout << str << '\n';
					act = 1;
				}
			}
		}
		else if (input == 3) {
			return 0;
		}
		else {
			cout << "Команда не распознана\n";
		}
	}
	
}