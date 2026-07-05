#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

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
			int n_found = 0;
			if (fgets(new.name, 50, stdin) != NULL) {
				for (int i = 0; *(new.name + i) != '\0'; i++) {
					if (*(new.name + i) == '\n') {
						*(new.name + i) = '\0';
						n_found = 1;
						break;
					}
				if (n_found = 0) {
					while ((c = getchar()) != '\n' && c != EOF);
					}
				}
			}
			


			printf("введите возраст студента: ");
			char c_age[5];
			new.age = atoi(fgets(c_age, 5, stdin));
			n_found = 0;
			for (int i = 0; i < 4; i++) {
				if (c_age[i] == '\n') {
					n_found = 1;
				}
			}
			if (n_found = 0) {
				while ((c = getchar()) != '\n' && c != EOF);
			}
			

			printf("введите среднюю оценку студента: ");
			char c_ag[6];
			new.ag = atof(fgets(c_ag, 6, stdin));
			if (c_ag[4] != '\n') {
				while ((c = getchar()) != '\n' && c != EOF);
			}
			

			FILE* file = fopen("students.txt", "a");
			if (file) {
				fprintf(file, "%s %d %.2f\n", new.name, new.age, new.ag);
				fclose(file);
			}
			else {
				printf("Ошибка подключения файла\n");
				return 1;
			}

		}
		else if (choose == '2') {
			FILE* file = fopen("students.txt", "r");
			if (file != NULL) {
				char str[100];
				while (fgets(str, 100, file)) {
					printf("%s", str);
				}
				fclose(file);
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