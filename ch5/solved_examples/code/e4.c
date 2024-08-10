/*
	Write a program to read and display the information of all the students in a class. Then
	edit the details of the ith student and redisplay the entire information.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MALE = 13; //random value
const int FEMALE = 17; //random value

typedef struct{
	char name[100];
	int gender;

} Student;

typedef struct{
	char subject[100];
	int grade;
	Student students[5];
} Class;

int main()
{
	//initialize the class
	Student stud_1;
	strcpy(stud_1.name, "Anne");
	stud_1.gender = FEMALE;

	Student stud_2;
	strcpy(stud_2.name, "Sarah");
	stud_2.gender = FEMALE;

	Student stud_3;
	strcpy(stud_3.name, "Jeremy");
	stud_3.gender = MALE;

	Student stud_4;
	strcpy(stud_4.name, "John");
	stud_4.gender = MALE;

	Student stud_5;
	strcpy(stud_5.name, "Mary");
	stud_5.gender = FEMALE;

	Class nClass;
	strcpy(nClass.subject, "Math");
	nClass.grade = 11;
	nClass.students[0] = stud_1;
	nClass.students[1] = stud_2;
	nClass.students[2] = stud_3;
	nClass.students[3] = stud_4;
	nClass.students[4] = stud_5;
}