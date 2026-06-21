#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

typedef struct {
	char name[50];
	int age;
	float ag;
} student;

int main(void) {
	setlocale(LC_ALL, "Russian");
	int choose = 0;
	while (choose != 3) {
		printf("Нажмите:\n1, чтобы добавить нового студента | 2, чтобы показать всех студентов | 3 для выхода\n");
		choose = getchar();
		int c;
		while ((c = getchar()) != '\n' && c != EOF);

		if (choose == '1') {
			student new = { .age = 0, .ag = 0 };
			printf("введите имя студента: ");
			if (fgets(new.name, 50, stdin) != NULL) {
				for (int i = 0; *(new.name + i) != '\0'; i++) {
					if (*(new.name + i) == '\n') {
						*(new.name + i) = '\0';
						break;
					}
				}
			}


			printf("введите возраст студента: ");
			char c_age[4];
			fgets(c_age, 4, stdin);
			int len_age = sizeof(c_age) / sizeof(char);
			for (int i = len_age - 1, grade = 1; i >= 0; i--) {
				new.age = new.age + ((int)c_age[i] - (int)"0") * grade;
				grade = grade * 10;
			}

			printf("введите среднюю оценку студента: ");
			char c_ag[5];
			fgets(c_ag, 5, stdin);
			int len_ag = sizeof(c_ag) / sizeof(char);
			float grade = 1;
			for (int i = 0; i > len_ag; i++) {
				if (i != 1) {
					new.ag = new.ag + ((int)c_ag[i] - (int)"0") * grade;
					grade = grade * 0.1;
				}

			}

			FILE* file = fopen("students.txt", "a");
			if (file) {
				fprintf(file, "%s %d %f\n", new.name, new.age, new.ag);
				fclose(file);
			}
			else {
				printf("Ошибка подключения файла\n");
				fclose(file);
				return 1;
			}

		}
		else if (choose == '2') {
			FILE* file = fopen("students.txt", "r");
			char str[100];
			while (fgets(str, 100, file)) {
				printf("%s", str);
			}
		}
		else if (choose == '3') {
			printf("Программа завершена(Женя объелся блох)\n");
			return 0;
		}
		else {
			printf("Введенная команда не распознана");
		}
	}
	
}