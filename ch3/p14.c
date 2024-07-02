/*
	This file is dedicated specifically to solving problem 14 in ch3
	of the Data Strutures Using C Textbook
*/

/*
	Problem Statement:
	Write a menu driven program to read and display a p x q x r matrix.
	also, find the sum, transpose and the product of the p x q x r matrix.
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printOptions();
void print3DArray_int(int*** arr, size_t first_dimension, size_t second_dimension, size_t third_dimension);
int*** dynamicallyAllocateMemFor3DArr(size_t first_dimension, size_t second_dimension, size_t third_dimension);
void freeDynAllocatedMemFor3DArr(int*** arr,size_t first_dimension, size_t second_dimension);
void inputValuesToArr(int*** arr, size_t first_dimension, size_t second_dimension, size_t third_dimension);
int*** createMatrix(size_t first_dimension, size_t second_dimension, size_t third_dimension);
int*** transpose(int*** matrix, size_t first_dimension, size_t second_dimension, size_t third_dimension);

int main()
{
	char option_input;

	while(option_input != '!')
	{
		printf("Welcome to P14!, choose one of the options below, or press ! to exit\n");
		printOptions();

		scanf("\n%c", &option_input);
		switch(option_input)
		{
			case 'a':
				//read and display p x q x r matrix
				int first_dimension, second_dimension, third_dimension;

				printf("Please Enter the Dimensions of the matrix: \n");
				scanf("\n%i", &first_dimension);
				scanf("\n%i", &second_dimension);
				scanf("\n%i", &third_dimension);

				int*** matrix = createMatrix(first_dimension, second_dimension, third_dimension);
				print3DArray_int(matrix, first_dimension, second_dimension, third_dimension);
				freeDynAllocatedMemFor3DArr(matrix, first_dimension, second_dimension);
				break;
			case 'b':
				//find the transpose of a p x q x r matrix

				break;
			case 'c':
				//find the sum of two p x q x r matricies

				break;
			case 'd':
				//find the product of two p x q x r matricies

				break;
			case '!':
				exit(-1);
			default:
				printf("ERROR: Invalid Input.\n");
		}
	}

}

void printOptions()
{
	printf(" (a) Read and Display a p x q x r matrix\n");
	printf(" (b) Find the transpose of a p x q x r matrix\n");
	printf(" (c) Find the sum of two p x q x r matricies\n");
	printf(" (d) Find the product of two p x q x r matricies\n\n");
}

int*** dynamicallyAllocateMemFor3DArr(size_t first_dimension, size_t second_dimension, size_t third_dimension)
{
	int ***ptr = (int***) calloc(first_dimension, sizeof(int**));
	if(ptr == NULL)
	{
		printf("ERROR: failed to allocate memory for ***ptr in dynamicallyAllocateMemFor3DArr()");
		exit(-1);
	}

	for(int i = 0; i<first_dimension; i++)
	{
		ptr[i] = (int**) calloc(second_dimension, sizeof(int*));
		if(ptr[i] == NULL)
		{
			printf("ERROR: failed to allocate memory for ptr[i] in dynamicallyAllocateMemFor3DArr()");
		}

		for(int j = 0; j<third_dimension; j++)
		{
			ptr[i][j] = (int*) calloc(third_dimension, sizeof(int));
		}
	}


	return ptr;
}

void print3DArray_int(int*** arr, size_t first_dimension, size_t second_dimension, size_t third_dimension)
{
	for(int i = 0; i<first_dimension; i++)
	{
		for(int j = 0; j<second_dimension; j++)
		{
			for(int k = 0; k<third_dimension; k++)
			{
				printf("Element (%i, %i, %i) is %i\n", i+1, j+1, k+1, arr[i][j][k]); /* adding 1 to i, k, j to make numbering start from 1*/
			}
		}

	}

	printf("\n\n");
}

void freeDynAllocatedMemFor3DArr(int*** arr,size_t first_dimension, size_t second_dimension)
{
	//start by freeing the lowest level, then go up
	for(int i = 0; i<first_dimension; i++)
	{
		for(int j = 0; j<second_dimension; j++)
		{
			free(arr[i][j]);
		}

		free(arr[i]);
	}

	free(arr);
}

void inputValuesToArr(int*** arr, size_t first_dimension, size_t second_dimension, size_t third_dimension)
{
	for(int i = 0; i<first_dimension; i++)
	{
		for(int j = 0; j<second_dimension; j++)
		{
			for(int k = 0; k<third_dimension; k++)
			{
				printf("Enter the value for element (%i, %i, %i)\n", i+1, j+1, k+1);
				scanf("\n%i", &arr[i][j][k]); /* adding 1 to i, k, j to make numbering start from 1*/
			}
		}

	}
}

int*** createMatrix(size_t first_dimension, size_t second_dimension, size_t third_dimension)
{
	int*** ptrToMatrix;

	//allocate memory for the matrix
	ptrToMatrix = dynamicallyAllocateMemFor3DArr(first_dimension, second_dimension, third_dimension);

	//input values for the array
	inputValuesToArr(ptrToMatrix, first_dimension, second_dimension, third_dimension);

	return ptrToMatrix;
}	