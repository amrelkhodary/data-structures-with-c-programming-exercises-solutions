/*
	write a program that copies a string into another string
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copy(char* firstStr, char* secondStr);
char* allocateMemoryForString(size_t length);

int main()
{
	char firstStr[20] = "Hello";
	char secondStr[20] = "Hello_2";

	copy(firstStr, secondStr);
}

void copy(char* firstStr, char* secondStr)
{
	const int longerStringLength = (strlen(firstStr) >= strlen(secondStr)) ? strlen(firstStr) : strlen(secondStr);
	const int longerString = (strlen(firstStr) >= strlen(secondStr)) ? 1 : 2; //1 for firstStr, 2 for secondStr

	char* newText = allocateMemoryForString(longerStringLength);
	newText = firstStr;

	if(longerString == 1){
		//means that secondStr is the shorter string, copy it into newText
		for(int i = 0; i<strlen(secondStr); i++)
		{
			newText[i] = secondStr[i];
		}
	} else if(longerString == 2){
		//means that firstStr is the shorter string, copy it into newText
		for(int i = 0; i<strlen(firstStr); i++)
		{
			newText[i] = firstStr[i];
		}
	}

	for(int i = 0; i<longerStringLength; i++)
	{
		if(longerString == 1)
		{
			firstStr[i] = newText[i];
		}
		else if(longerString == 2)
		{
			newText[i] = secondStr[i];
		}
	}
}

char* allocateMemoryForString(size_t length)
{
	return (char*) malloc(length * sizeof(char));
}