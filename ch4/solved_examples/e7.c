/*
	insert a string into the main string
*/

#include <stdio.h>
#include <string.h>

void takeUserInput(char* mainStrPtr, char* insertStrPtr, int* insertionIndexPtr);
void insert(char* mainStr, char* insertStr, int insertionIndex);
void shift(char* str, int shiftAmount);
void copy(char* str, int firstIndex, int secondIndex);

const char EMPTY_CHAR = '~';

int main()
{
	//declare variables
	char str[100];
	char insertString[100];
	int insertionIndex;

	//take input from user
	takeUserInput(str, insertString, &insertionIndex);

	//insert the string into the main string
	insert(str, insertString, insertionIndex);

	//print the result
	printf("The final string is: %s\n", str);
}

void takeUserInput(char* mainStrPtr, char* insertStrPtr, int* insertionIndexPtr)
{
	printf("Please enter the main string: \n");
	gets(mainStrPtr);
	printf("Please enter the string you want to insert: \n");
	gets(insertStrPtr);
	printf("Please enter the index where you want to insert your string\n");
	scanf("\n%i", insertionIndexPtr);
}

void insert(char* mainStr, char* insertStr, int insertionIndex)
{
	shift(mainStr + insertionIndex, strlen(insertStr));

	for(int i = 0, j = insertionIndex; i<strlen(insertStr); i++, j++)
	{
		mainStr[j] = insertStr[i];
	}
}

void shift(char* str, int shiftAmount)
{
	const int LAST_CHAR_INDEX = strlen(str) - 1;
	for(int i = LAST_CHAR_INDEX; i>=0; i--)
	{
		copy(str, i, i+shiftAmount);
	}

	printf("the string after the shift is:%s\n", str);

	for(int i = shiftAmount - 1; i>=0; i--)
	{
		str[i] = EMPTY_CHAR;
	}
	
}

void copy(char* str, int firstIndex, int secondIndex)
{
	str[secondIndex] = str[firstIndex];
}