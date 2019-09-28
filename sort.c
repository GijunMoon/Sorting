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

	token = strtok(string, " "); //���ڿ� �и���(�����̽� �������� �ܾ� �и��ϱ� ����)
	arr[0] = _strdup(token); //�Է°�
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
	char** name; //2���� �迭
	int name_size;
	int i;

	name = (char**)malloc(sizeof(char*) * MAX_SIZE);
	name_size = input_name(name);

	qsort((void*)name, name_size, sizeof(name[0]), convert_string); //qsort �Լ� �̿�

	printf("���� ��� ----> ");
	for (i = 0; i < name_size; i++)
		printf("%s ", name[i]);
	
	/*�Է� ����
	   apple kiwi banana grape*/
	/*��� ����
	   apple banana grape kiwi*/

	free(name);

	return 0;
}