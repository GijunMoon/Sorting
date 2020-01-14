//2019.11.16
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Bubble_string(char** inputstr, int n);

int main(void) {
	char** str;
	int n, i;
	printf("출력 횟수: ");
	scanf("%d\n", &n);

	//1차원 형태 할당
	str = (char**)calloc(n, sizeof(char*));

	for (i = 0; i < n; i++)
	{
		str[i] = (char*)calloc(30, sizeof(char)); //2차원 형태 할당
		scanf("%s", str[i]);
	}

	printf("\n정렬 전: ");
	for (i = 0; i < n; i++)
		printf("%s ", str[i]);

	Bubble_string(str, n); //Sort

	printf("\n정렬 후: ");
	for (i = 0; i < n; i++)
		printf("%s ", str[i]);

	return 0;
}

void Bubble_string(char** inputstr, int n) 
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (strcmp(inputstr[j], inputstr[j + 1]) > 0) {
				char* temp; //TODO : 포인터로 바꾸기
				temp = (char*)calloc(30, sizeof(char));
				strcpy(temp, inputstr[j]);
				strcpy(inputstr[j], inputstr[j + 1]);
				strcpy(inputstr[j + 1], temp);
			}
		}
	}
}
