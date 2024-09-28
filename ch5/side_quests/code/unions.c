/*
	this file was created to experiement with unions in C
*/

#include <stdio.h>
#include <stdlib.h>

typedef union{
	int integer;
	int decimal;
	char s[20];
} number;

int main()
{
	number a;
	a.integer = 23;

	printf("%i\n", a.integer);
	printf("%i\n", a.decimal);
	printf("%s\n", a.s);
}