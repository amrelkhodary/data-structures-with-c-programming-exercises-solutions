/*
	write a program that displays the data of students using an array
	of pointers to structures
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[25];
	int age;
} Person;

void PopulatePersonsArray(Person** persons);
void initpersons(Person** persons);
void printpersons(Person** persons);

int main()
{
	Person* persons[10];
	PopulatePersonsArray(persons);
	initpersons(persons);
	printpersons(persons);

	for(int i = 0; i<10; i++)
	{
		free(persons[i]);
	}
}

void PopulatePersonsArray(Person** persons)
{
	for(int i = 0; i<10; i++)
	{
		//allocate memory for a person strucutre
		Person* pptr = (Person*) malloc(sizeof(Person));
		persons[i] = pptr;
	}
}

void initpersons(Person** persons)
{
	int temp = 1; //random age value

	for(int i = 0; i<10; i++)
	{
		strcpy(persons[i] -> name, "person");
		persons[i] -> age = temp;
		temp++;
	}
}

void printpersons(Person** persons)
{
	for(int i = 0; i<10; i++)
	{
		printf("Person %i data\n", i);
		printf("name: ");
		for(int j = 0; j<10 && (persons[i] -> name)[j] != '\0'; j++)
		{
			printf("%c", (persons[i] -> name)[j]);
		}
		printf("\n age: %i\n\n", persons[i] -> age);
	}
}