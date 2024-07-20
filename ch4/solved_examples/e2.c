/*
	Convert characters of a string to upper- or lowercase
*/

#include <stdio.h>
#include <stdbool.h>

void inputString(char* strPtr);
void convertStr(char* strPtr, size_t strLength);
bool isUpperCase(char character);
bool isLowerCase(char character);

int main()
{
	//getting input from user
	char str[100];
	inputString(str);

	//converting string charcters from upper- to lowercase and printing the result
	convertStr(str, 100);
	printf("The Converted String is: %s\n", str);
}

void inputString(char* strPtr)
{	
	printf("Please enter the string you want to convert\n");
	gets(strPtr);
}

void convertStr(char* strPtr, size_t strLength)
{
	/*
		this function manipulates ASCII code to convert from upper to lower case
		and vice versa

		the difference between the ASCII code of the first lowercase letter and the 
		ASCII code of the first uppercase letter is 32.

		add/subtract that value from the character to convert
	*/
	for(int i = 0; i<strLength; i++)
	{	
		if(isUpperCase(strPtr[i]))
		{
			strPtr[i] = strPtr[i] + 32;
			continue;	
		}

		if(isLowerCase(strPtr[i]))
		{
			strPtr[i] = strPtr[i] - 32;
			continue;	
		}
	}
}

bool isUpperCase(char character)
{
	return (character >= 65 && character <=90) ? true : false;
}

bool isLowerCase(char character)
{
	return (character >= 97 && character <= 122) ? true : false;
}