/*
	write a program to compare two strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inputString(char* str);
int compareTwoStrings(char* firstStr, size_t firstStrLength, char* secondStr, size_t secondStrLength);
int findWhereStringActuallyEnds(char* str, size_t strLength);
void convertStrToLowercase(char* str, size_t strLength);
bool isUppercase(char c);

const int FIRST_STR_LARGER = 1200; //random value
const int SECOND_STR_LARGER = 1400; //random value
const int BOTH_STR_EQUAL = 1600; //random value

int main()
{
	//take input from user
	char firstStr[100];
	char secondStr[100];
	inputString(firstStr);
	inputString(secondStr);

	//compare the two strings 
	int result = compareTwoStrings(firstStr, 100, secondStr, 100);

	//print the result
	if(result == FIRST_STR_LARGER){
		printf("The first string is larger than the second one\n");
	}
	else if(result == SECOND_STR_LARGER){
		printf("The second string is larger than the first one\n");
	}
	else{
		printf("Both strings are equal.\n");
	}
}






void inputString(char* str)
{
	printf("Please Enter a string\n");
	gets(str);
}

int compareTwoStrings(char* firstStr, size_t firstStrLength, char* secondStr, size_t secondStrLength)
{
	//converting both strings to lowercase
	convertStrToLowercase(firstStr, firstStrLength);
	convertStrToLowercase(secondStr, secondStrLength);

	//getting the real length of both strings 
	int firstStrRealLength = findWhereStringActuallyEnds(firstStr, firstStrLength);
	int secondStrRealLength = findWhereStringActuallyEnds(secondStr, secondStrLength);

	if(firstStrRealLength < secondStrRealLength)
	{
		for(int i = 0; i < firstStrRealLength; i++)
		{
			if(firstStr[i]+0 > secondStr[i]+0)
			{
				return SECOND_STR_LARGER;
			}
			else if(firstStr[i]+0 < secondStr[i]+0)
			{
				return FIRST_STR_LARGER;
			}
		}
	}
	else
	{
		for(int i = 0; i<secondStrRealLength; i++)
		{
			if(secondStr[i]+0 > firstStr[i]+0)
			{

				return FIRST_STR_LARGER;
			}
			else if(secondStr[i]+0 < firstStr[i]+0)
			{
				return SECOND_STR_LARGER;
			}
		}
	}


	return BOTH_STR_EQUAL;
}

int findWhereStringActuallyEnds(char* str, size_t strLength)
{
	/*
		keep going through the string until you find either NULL or '\0'
	*/


	int i = 0; //i is the index, but also can be used as length of the string
	while((str[i] != NULL || str[i] != '\0') && i<strLength)
	{
		i++;
	}
	return i;
}

void convertStrToLowercase(char* str, size_t strLength)
{
	for(int i = 0; i<strLength; i++)
	{
		if(isUppercase(str[i]))
		{
			str[i] = str[i] + 32; //using ASCII to convert to lowercase
		}
	}
}

bool isUppercase(char c)
{
	if((c+0) >= 65 && (c+0) <=90)
	{
		return true;
	}

	return false;
}