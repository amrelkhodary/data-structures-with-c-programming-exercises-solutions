/*
	in this C file I expierement with the C dynamic memory allocation functions, 
	malloc(), calloc(), free(), realloc()

	There're three types of memory allocation in C:-
	1- Static Allocation: Used for global variables
	2- Automatic Allocation: Used for local function variables
	3- Dynamic Allocation: We manually allocate and free memory oursevles

	In the context of computer science, memory is divided into two parts:-
	1- Program Memory: Includes the main function and any other declared functions.
	2- Data Memory: Divided into 3 parts:_
		2.1: Global -> Used for global variables
		2.2: Stack -> Used for function parameters and variables
		2.3: Heap -> Used for dynamically allocated variables
	
	Here's what each function does:-
	malloc(): Allocates memory and returns a pointer to the first byte of allo-
			  cated space
	calloc(): Allocates space for an array of elements, initializes them to zero
			  and returns a pointer to the memory

	free():	  Frees previously allocated memory

	realloc(): Alters the size of previously allocated memory
*/

#include <stdio.h>
#include <stdlib.h> //necessary for accessing dynamic memory allocation functions
#include <string.h>
#include <stdbool.h>
#include <math.h>

void printDynAllocatedInt();
void printDynAllocatedArrUsingMalloc();
void printDynALlcoatedArrUsingCalloc();
void printDynAllocated2DArr();
void sum();
bool isNumber(char* str);
int transformInputToInt(char* str);
int transformIndividualCharacterToInt(char digit);

int main()
{
	sum();
}

void printDynAllocatedInt()
{
	//allocating space to an integer
	int* ptr = (int*) malloc(sizeof(int));

	//if malloc() returned NULL, that means that it failed to allocate memory
	if(ptr == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY TO POINTER\n");
		exit(-1);
	}

	//assigning a value to the allocated memory
	*ptr = 7;
	printf("The value of the integer is: %i\n", *ptr);

	//freeing the memory
	free(ptr);
}

void printDynAllocatedArrUsingMalloc()
{
	//dynamically allocate memory for an array of 3 integers
	int* ptr = (int*) malloc(3 * sizeof(int));

	//again, if malloc returned NULL that means that it failed
	if(ptr == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY TO POINTER\n");
		exit(-1);
	}

	//assign values to the array
	ptr[0] = 12;
	ptr[1] = 13;
	ptr[2] = 14;

	//printing the values inside the array
	printf("The first element of the array is %i\n", ptr[0]);
	printf("The second element of the array is %i\n", ptr[1]);
	printf("The third element of the array is %i\n", ptr[2]);

	//freeing the memory
	free(ptr);
}

void printDynALlcoatedArrUsingCalloc()
{
	//allocates an array of 3 integers
	int* ptr = (int*) calloc(3, sizeof(int));

	if(ptr == NULL)
	{
		printf("FAILED TO ALLOCATE MEMORY TO POINTER\n");
		exit(-1);
	}

		//assign values to the array
	ptr[0] = 12;
	ptr[1] = 13;
	ptr[2] = 14;

	//printing the values inside the array
	printf("The first element of the array is %i\n", ptr[0]);
	printf("The second element of the array is %i\n", ptr[1]);
	printf("The third element of the array is %i\n", ptr[2]);

	//freeing the memory
	free(ptr);
}

void printDynAllocated2DArr()
{
	/*
		we will dynamically allocate memory for a 2D array with 2 rows and 3 columns
	*/

	int** rows = (int**) calloc(3, sizeof(int*));
	if(rows == NULL)
	{
		printf("Failed to allocate memory for rows\n");
		exit(-1);
	}

	for(int i = 0; i<2 /*because we are going through 2 rows*/; i++)
	{
		rows[i] = (int*) calloc(3, sizeof(int));
		if(rows[i] == NULL)
		{
			printf("Failed to allocate memory for column\n");
			exit(-1);
		}
	}

	rows[0][0] = 23;
	rows[0][1] = 34;
	rows[0][2] = 62;

	rows[1][0] = 12;
	rows[1][1] = 87;
	rows[1][2] = 44;

	printf("%i\n",  rows[0][0]);
	printf("%i\n",  rows[0][1]);
	printf("%i\n",  rows[0][2]);
	printf("%i\n",  rows[1][0]);
	printf("%i\n",  rows[1][1]);
	printf("%i\n",  rows[1][2]);


}

void sum()
{
	char* input; 
	int sum = 0;
	printf("Enter the numbers you want to add, press ! to exit: \n");

	scanf("%s", input);
	while(input != "!" && isNumber(input))
	{
		sum+= transformInputToInt(input);
	}
}

bool isNumber(char* str)
{
	for(int i = 0; i<strlen(str); i++)
	{
		if(str[i] + 0 < 48 || str[i] + 0 >57) //ASCII for digits is between 48 and 57
		{
			return false;
		}
	}

	return true;
}

int transformInputToInt(char* str)
{
	/*
		183:
		str[0] = 1; --> 1 * 10^2
		str[1] = 8;	--> 8 * 10^1
		str[2] = 3; --> 3 * 10^0

		numvalue = 10^abs((index - (length - 1)))
	*/

	int sum = 0;
	for(int i = 0; i<strlen(str); i++)
	{
		sum+= transformIndividualCharacterToInt(str[i]) * pow(10, abs(i-strlen(str)+1));
	}

	return sum;
}

int transformIndividualCharacterToInt(char digit)
{

/*	switch(digit){
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9': 
		return 9;
	}*/

	return digit - 48; //only realised i could just do this after-the-fact
					   // i'm as dumb as a door knob lol
}	

