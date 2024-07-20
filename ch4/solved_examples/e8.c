/*
	return the position in a string where a specified
	pattern first occurs
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void takeUserInput(char* str, char* pattern);
int findPattern(char* str, char* pattern);
bool isPattern(char* str, char* pattern, int start, int end);

int main()
{
	//declaring necessary variables
	char str[100];
	char pattern[100]; //pattern could be the entire string, so length could also be 100

	//taking input from user
	takeUserInput(str, pattern);

	//find the pattern
	int result = findPattern(str, pattern);

	//print result
	printf("%i\n", result);

}

void takeUserInput(char* str, char *pattern)
{
	printf("Enter the string you want to search for patterns in: \n");
	gets(str);
	printf("Enter the pattern you want to search for: \n");
	gets(pattern);
}

int findPattern(char* str, char* pattern)
{
	const int PATTERN_LENGTH = strlen(pattern);

	for(int i = 0; i< strlen(str); i+=PATTERN_LENGTH)
	{
		if(isPattern(str, pattern, i, i+(PATTERN_LENGTH-1)))
		{
			return i;
		}
	}

	return -1;
}


bool isPattern(char* str, char* pattern, int start, int end)
{
	for(int i = start; i<=end; i++)
	{
		if(str[i] != pattern[i-start])
		{
			return false;
		}
	}

	return true;
}