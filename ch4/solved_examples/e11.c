/*
	write a program to sort the names of students 
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void takeUserInput(char (*names)[20]);
int compareStrings(char* firstStr, char* secondStr);
void tolowercase(char* str);
int findIndexOfSmallestString(char (*names)[20], size_t namesLength);
void swap(char (*names)[20], int firstIndex, int secondIndex);
void copy(char* copyToStrPtr, char* copyFromStrPtr, size_t length);
void sort(char (*names)[20], size_t namesLength);
void printNames(char (*names)[20], size_t namesLength);

void copy_test();
void swap_test();
void sort_test();

const int STRINGS_EQUAL = 1200; //random value
const int FIRST_STRING_LARGER = 1300; //random value
const int SECOND_STRING_LARGER = 1400; //random value

int main()
{
	/*char names[5][20];
	
	takeUserInput(names);
	sort(names, 5);
	printNames(names, 5);*/

	sort_test();

}

void takeUserInput(char (*names)[20])
{
	printf("Please enter the names of every stduent followed by enter:\n");
	gets(names[0]);
	gets(names[1]);
	gets(names[2]);
	gets(names[3]);
	gets(names[4]);
}

int compareStrings(char* firstStr, char* secondStr)
{
	tolowercase(firstStr);
	tolowercase(secondStr);


	for(int i = 0; firstStr[i] != '\0' && secondStr[i] != '\0'; i++)
	{
		if(firstStr[i] > secondStr[i]){
			return FIRST_STRING_LARGER;
		}
		else if(firstStr[i] < secondStr[i]){
			return SECOND_STRING_LARGER;
		}
		else{
			continue;
		}
	}

	return (strlen(firstStr) == strlen(secondStr)) ? 
			STRINGS_EQUAL : 
				(strlen(firstStr) > strlen(secondStr)) ? 
					FIRST_STRING_LARGER : SECOND_STRING_LARGER;
}

void tolowercase(char* str)
{
	for(int i = 0; i<strlen(str); i++)
	{
		if(str[i] + 0 >= 65 && str[i] + 0 <=90)
		{
			//char is uppercase
			str[i] = str[i] + 32;
		}
	}
}

int findIndexOfSmallestString(char (*names)[20], size_t namesLength)
{
	int smallestStringIndex = 0;

	for(int i = 0; i<namesLength; i++)
	{
		if(compareStrings(names[i], names[smallestStringIndex]) == FIRST_STRING_LARGER)
		{
			smallestStringIndex = i;
		}
	}

	return smallestStringIndex;
}

void swap(char (*names)[20], int firstIndex, int secondIndex)
{
	char temp[20];

	copy(temp, names[firstIndex], 20);
	copy(names[firstIndex], names[secondIndex], 20);
	copy(names[secondIndex], temp, 20);
}

void copy(char* copyToStrPtr, char* copyFromStrPtr, size_t length)
{
	for(int i = 0; i<length; i++)
	{
		copyToStrPtr[i] = copyFromStrPtr[i]; 
	}
}

void sort(char (*names)[20], size_t namesLength)
{
	for(int i = 0; i<namesLength; i++)
	{
		swap(names, i, findIndexOfSmallestString(names+i, namesLength-i));
	}
}

void printNames(char (*names)[20], size_t namesLength)
{
	for(int i = 0; i<namesLength; i++)
	{
		printf("The name no. %i is %s\n", i, names[i]);
	}
}

void copy_test()
{
	char a[20] = "Hello";
	char b[20] = "Hello_b";
	copy(a, b, 20);

	printf("the string a is now %s", a);
}

void swap_test()
{
	char test[2][20] = {"First Str", "Second Str"};
	swap(test, 0, 1);

	printNames(test, 2);
}

void sort_test()
{
	char test[4][20] = {"b", "a", "c", "z"};
	sort(test, 4);

	printNames(test, 4);
}