#include <fstream>
#include <clocale>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <iomanip>

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

	string getName(void) const{
		return name;
	}
	int getAge(void) const {
		return age;
	}
	float getAg(void) const {
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
		cout << "Введите команду:\n1 - добавить студента, 2 - вывести базу список студентов, 3 - завершить программу,\n4 - поиск студента по имени, 5 - сортировка по убыванию ag" << endl;
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
			fin.open(path);
			if (!fin.is_open()) {
				cout << "Файл пустой\n" << endl;
				continue;
			}
			if (db.empty()) {
				student curr;
				string str;
				int degr;
				float dot;
				cout << "\t | Список студентов| \n";
				while (fin >> str >> degr >> dot) {
					cout << str << ' ';
					curr.setName(str);
					cout << degr << ' ';
					curr.setAge(degr);
					cout << dot << '\n';
					curr.setAg(dot);
					
					db.push_back(curr);
				}
			}
			else {
				string str;
				int degr;
				float dot;
				cout << "\t | Список студентов| \n";
				while (fin >> str >> degr >> dot) {
					cout << str << ' ';
					cout << degr << ' ';
					cout << dot << '\n';
				}
			}
		}
		else if (input == 3) {
			return 0;
		}
		else if (input == 4) {
			cout << "Введите имя студента: " << endl;
			string search;
			cin >> search;
			cin.ignore();

			if (db.empty()) {
				ifstream fin;
				fin.open(path);
				if (!fin.is_open()) {
					cout << "Ошибка открытия файла" << endl;
					return -1;
				}
				student curr;
				string str;
				int degr;
				float dot;
				while (fin >> str >> degr >> dot) {
					curr.setName(str);
					curr.setAge(degr);
					curr.setAg(dot);

					db.push_back(curr);
				}
			}

			auto it = find_if(db.begin(), db.end(), [search](const student& s) {
				return s.getName() == search;
				});
			if (it != db.end()) {
				cout << it->getName() << ' ' << it->getAge() << ' ' << fixed << setprecision(2) << it->getAg() << endl;
			}

		}
		else if (input == 5) {
			cout << "Отсортированный список: " << endl;

			if (db.empty()) {
				ifstream fin;
				fin.open(path);
				if (!fin.is_open()) {
					cout << "Ошибка открытия файла" << endl;
					return -1;
				}
				student curr;
				string str;
				int degr;
				float dot;
				while (fin >> str >> degr >> dot) {
					curr.setName(str);
					curr.setAge(degr);
					curr.setAg(dot);

					db.push_back(curr);
				}
			}

			sort(db.begin(), db.end(), [](const student& a, const student& b) {
				return a.getAg() > b.getAg();
				});
			for (int i = 0; i < db.size(); i++) {
				cout << db[i].getName() << ' ' << db[i].getAge() << ' ' << db[i].getAg() << endl;
			}
		}
		else {
			cout << "Команда не распознана\n";
			input = 3;
		}
	}
	
}