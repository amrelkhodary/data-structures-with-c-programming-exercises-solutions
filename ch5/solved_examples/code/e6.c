/*
	write a program to initialize a structure using a pointer to the structure
*/

#include <stdio.h>
#include <string.h>

typedef struct{
	char name[25];
	int age;
} Student;

void init(Student* ptr);
void printstruc(Student* ptr);

int main()
{
	Student stud;
	Student* ptr = &stud;
	init(ptr);
	printstruc(ptr);
}

void init(Student* ptr)
{
	strcpy(ptr -> name, "Ahmed");
	ptr -> age = 19;
}

void printstruc(Student* ptr)
{
	printf("the name of the student is: \n");
	int i = 0;
	while((ptr -> name)[i] != '\0')
	{
		printf("%c", (ptr -> name)[i]);
		i++;
	}
	printf("\nthe age of the student is: %i\n", ptr -> age);
}