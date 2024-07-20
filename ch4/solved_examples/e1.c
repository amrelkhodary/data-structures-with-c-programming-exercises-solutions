/*
	Write a program to find the length of a string
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* inputString(char* str);
int findStringLength(char* str);

int main()
{	
	//getting input from user
	char str[100];
	inputString(str);

	//finding the length and returning the result
	printf("The Length of the string is %i", findStringLength(str));
}

char* inputString(char* str)
{
	printf("Please Enter a String\n");
	gets(str);
}

int findStringLength(char* str)
{
	/*
		since every string terminates with \0, we can simply 
		loop through the string until we find \0, and in every iteration 
		increase the length variable by 1

		we can discard the obsolete length variable since the length is just the 
		index + 1
	*/

	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}

	return i;
}