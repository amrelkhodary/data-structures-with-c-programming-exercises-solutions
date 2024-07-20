/*
	write a C program to delete a substring from a main string
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void takeUserInput(char* str, int* start, int* amount);
bool shouldBeDeleted(int index, int start, int amount);

int main()
{
	//declaring variables
	char str[100], new_text[100];
	int start, amount;

	//taking input from user
	takeUserInput(str, &start, &amount);

	for(int i = 0, j = 0; i<strlen(str); i++)
	{
		if(!shouldBeDeleted(i, start, amount)){
			new_text[j] = str[i];
			j++;
		}
	}

	printf("The new text is: \n%s\n", new_text);
}

void takeUserInput(char* str, int* start, int* amount)
{
	printf("Please enter the main string\n");
	gets(str);

	printf("Please enter where you want to start deleting\n");
	scanf("\n%i", start);

	printf("Please enter the amount you want to delete\n");
	scanf("\n%i", amount);

}

bool shouldBeDeleted(int index, int start, int amount)
{
	if(index >= start && index <= (start + (amount-1)))
	{
		return true;
	}

	return false;
}