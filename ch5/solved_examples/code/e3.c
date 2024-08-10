/* write a program to display the information of student using a nested structure*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[100];
	int yearFounded;
} School;

typedef struct{
	char name[100];
	int age;
	School school;
} Student;

Student initializeStudent();

int main()
{
	Student nStudent = initializeStudent();
	printf("*************************************************\n");
	printf("The student's name is: %s\n", nStudent.name);
	printf("The student's age is: %i\n", nStudent.age);
	printf("The studnet' school is: %s\n", nStudent.school.name);
	printf("The student's school was founded in: %i\n", nStudent.school.yearFounded);
	printf("*************************************************\n");
}

Student initializeStudent()
{
	Student nStudent;

	printf("Please enter the name of the student:\n");
	gets(nStudent.name);

	printf("Please enter the age of the student:\n");
	scanf("%i", &nStudent.age);
	getchar(); //removes the newline character that scanf inserts into the input buffer

	printf("Please enter the name of the school that the student studied in: \n");
	gets(nStudent.school.name);

	printf("Please enter the year that the school was founded in: \n");
	scanf("%i", &nStudent.school.yearFounded);

	return nStudent;
}