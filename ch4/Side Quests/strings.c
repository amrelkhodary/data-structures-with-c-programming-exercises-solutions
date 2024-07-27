/*
	In this file, I expirement wtih strings
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void readStringWithScanf();
void readStringWithGets();
void printAStringUsingPrintf(char* str);
void printAStringUsingPuts(char* str);
void testStrlen();

int main()
{
/*	//initializing a string
	char str[] = "Hello";
	char str[6] = "Hello"; //notice here the size has to be 6 to make room for the final null character

	//intializing a string as an array of charaters 
	char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};*/

	 testStrlen();
}


void readStringWithScanf()
{
	char strInput[100];
	printf("Please enter a string that does not contain a whitespace\n");
	scanf("%s", strInput);

	printf("You just entered \"%s\"", strInput);
}

void readStringWithGets()
{
	char strInput[100];
	printf("Please enter a string\n");
	gets(strInput);

	printf("You just entered \"%s\"", strInput);
}

void printAStringUsingPrintf(char* str)
{
	printf("%s", str);
}

void printAStringUsingPuts(char* str)
{
	puts(str);
}

void testStrlen()
{
	char str[100] = "hello";
	printf("%i", strlen(str));
}