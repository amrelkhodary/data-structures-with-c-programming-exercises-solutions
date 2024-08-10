/*
	this C file was created to expirement with structures in C
*/

#include <stdio.h>
#include <string.h>

void declareStruct();
void usetypedef();
void initializeStruct();
void accessStructMembers();

typedef struct{
	int value; 
	struct node* next;
}	node;

int main()
{
	accessStructMembers();
}

void declareStruct()
{	
	struct student
	{
		char name[20];
		int age;
		int gender;	
	};

	//instance of student
	struct student mohammed;


	//second way of initializaing a struct

	struct student_2
	{
		char name[20];
		int age;
		int gender;
	}mohammmed, jack;

}

void usetypedef()
{
	//using typedef to give an alternative name to a data type
	typedef int number;
	number a = 23;

	//using typedef with structs (first way)
	typedef struct{
		char name[20];
		int age;
		int gender;
	} student;

	//using typedef with structs (second way)
	struct a{
		char name[20];
		int age;
		int gender;
	};

	typedef struct a stud;
}

void initializeStruct()
{
	typedef struct{
		char name[20];
		int age;
		int salary;
	} employee;

	employee ahmed = {"Ahmed", 29, 30000};
}

void accessStructMembers()
{
	typedef struct{
		char name[20];
		int age;
		int salary;
	} employee;

	//changing values of the struct
	employee test_1 = {"Amr", 23, 10000};
	strcpy(test_1.name, "Homer");
	test_1.age = 45;
	test_1.salary = 40000;

	//printing values of a struct
	employee test_2 = {"Sarah", 32, 35000};
	printf("The name of the test_2 employee is %s\n", test_2.name);
	printf("The age of the test_2 employee is %i\n", test_2.age);
	printf("The salary of the test_2 employee is %i\n", test_2.salary);

	//taking input to the struct
	employee test_3;
	printf("Input the name of test_3 employee\n");
	gets(test_3);
	printf("Input the age of the test_3 employee\n");
	scanf("%i\n", &test_3.age);
	printf("Input the salary of the test_3 employee\n");
	scanf("\n%i", &test_3.salary);
}