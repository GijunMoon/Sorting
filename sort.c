#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

int convert_string(const void* one, const void* other)
{
	return (strcmp(*(char**)one, *(char**)other));
}

input_name(char** arr) {
	char string[200];
	char* token;
	int arr_size;

	gets(string);

	token = strtok(string, " "); //문자열 분리용(스페이스 기준으로 단어 분리하기 위함)
	arr[0] = _strdup(token); //입력값
	arr_size = 1;

	do {
		token = strtok(NULL, " "); 
		if (token == NULL) //NULL
			break;
		arr[arr_size++] = _strdup(token);
	} while (1);

	return arr_size;
}

int main()
{
	char** name; //2차원 배열
	int name_size;
	int i;

	name = (char**)malloc(sizeof(char*) * MAX_SIZE);
	name_size = input_name(name);

	qsort((void*)name, name_size, sizeof(name[0]), convert_string); //qsort 함수 이용

	printf("정렬 결과 ----> ");
	for (i = 0; i < name_size; i++)
		printf("%s ", name[i]);
	
	/*입력 예시
	   apple kiwi banana grape*/
	/*출력 예시
	   apple banana grape kiwi*/

	free(name);

	return 0;
}