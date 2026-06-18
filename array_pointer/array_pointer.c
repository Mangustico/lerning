#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	printf("enter the size:");
	int n;
	scanf("%d", &n);

	int* array;
	array = (int*)malloc(n * sizeof(n));

	srand(time(NULL));
	int mx = 0, mn = 101; 
	int max[2] = { 0, -1 }, min[2] = { 101, -1 };
	for (int i = 0; i < n; i++) {
		*(array+i) = rand()%100 +1;
		if (*(array + i) > *max) {
			*max = *(array + i);
			*(max + 1) = i;
		}
		else if (*(array + i) < *min) {
			*min = *(array + i);
			*(min + 1) = i;
		}
	}

	printf("[");
	for (int i = 0; i < (n-1); i++) {
		printf("%d, ", *(array + i));
	}
	printf("%d]\nmax is: %d with %d index", *(array + n - 1), *max,*(max+1));

	free(array);

	return 0;
}