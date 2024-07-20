/*
	Extract a substring from a string
*/

#include <stdio.h>

void inputString(char* strPtr);
void inputStartEnd(int* startPtr, int* endPtr);
int findRealStringLength(char* str, size_t strLength);
void makeSubstr(char* str, size_t strLength, char* substrPtr, size_t substrLength, int substr_start, int substr_end);

int main()
{
	//initialize variables
	char str[100];
	char substr[100]; //substr could be the entire string, that's why it is initialized with same length
	int substr_start;
	int substr_end;

	//input values
	inputString(str);
	inputStartEnd(&substr_start, &substr_end);


	//create the substring
	makeSubstr(str, 100, substr, 100, substr_start, substr_end);

	//print the result
	printf("The substring is: %s", substr);

}

void inputString(char* strPtr)
{
	printf("Please Enter a string\n");
	gets(strPtr);
}

void inputStartEnd(int* startPtr, int* endPtr)
{
	scanf("%i\n", startPtr);
	scanf("\n%i", endPtr);
}


void makeSubstr(char* str, size_t strLength, char* substrPtr, size_t substrLength, int substr_start, int substr_end)
{
	for(int i = substr_start, j = 0; i<=substr_end; i++, j++)
	{
		substrPtr[j] = str[i];
	}
}
