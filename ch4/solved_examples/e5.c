/*
	write a C program to reverse a string
*/

#include <stdio.h>

void inputString(char* strPtr);
void reverseString(char* str, size_t realStrLength);
void swap(char* str, int first_index, int second_index);
int findRealStringLength(char* str, size_t strLength);

int main()
{
	//initializing variables
	char str[100];

	//take input from user
	inputString(str);

	//reverse the string
	reverseString(str, findRealStringLength(str, 100));

	//print result
	printf("The reversed string is: %s", str);

}

void inputString(char* strPtr)
{
	printf("please enter a string: \n");
	gets(strPtr);
}

void reverseString(char* str, size_t realStrLength)
{
	for(int i = 0, j = realStrLength - 1; i<j; i++, j--)
	{
		swap(str, i, j);
	}
}

void swap(char* str, int first_index, int second_index)
{
	int temp = str[first_index];
	str[first_index] = str[second_index];
	str[second_index] = temp;
}

int findRealStringLength(char* str, size_t strLength)
{
	/*
		go through the string until you find a NULL or a '\0'
	*/

	int i = 0;
	while(i<strLength && (str[i] != NULL || str[i] != '\0'))
	{
		i++;
	}

	printf("real length is: %i\n", i);

	return i;
}