#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <clocale>

using namespace std;

bool isSeparator(char c) {
	if (c == '!' || c == '?' || c == '.' || c == ',' || c == ' ' || c == '\n') {
		return true;
	}
	return false;
}

bool isSentEnd(char c) {
	if (c == '!' || c == '?' || c == '.') {
		return true;
	}
	return false;
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	string path = "text.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		cout << "file opening error" << endl;
		return -1;
	}

	char c;

	int in_word = 0;
	int word_count = 0;

	int is_sent = 0;
	int sent_count = 0;


	int w_len = 0;
	int m_len = 0;
	vector<char> m_word;
	vector<char> word;

	while (fin.get(c)) {
		if (isSeparator(c)) {
			if ((in_word == 1) and (w_len > m_len)) {
				m_len = w_len;
				m_word = word;
			}
			if (isSentEnd(c)) {
				is_sent = 0;
			}
			in_word = 0;

			w_len = 0;
		}
		else if (in_word == 0) {
			in_word = 1;
			word_count++;

			if (word.empty()) {
				word.push_back(c);
			}
			else {
				word[0] = c;
			}
			w_len = 1;

			if (is_sent == 0) {
				sent_count++;
			}
			is_sent = 1;
		}
		else if (in_word == 1) {
			w_len++;
			if (word.size() < w_len) {
				word.push_back(c);
			}
			else {
				word[w_len - 1] = c;
			}
		}
	}
	cout << "Amount of words: " << word_count << "\nSentance are " << sent_count << "\nLongest word is: ";
	for (int i = 0; i < m_word.size(); i++) {
		cout << m_word[i];
	}
	cout << "\n";
}