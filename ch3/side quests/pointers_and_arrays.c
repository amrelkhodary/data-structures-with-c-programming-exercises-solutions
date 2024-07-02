/*
	In this C file, I expierement with pointers, arrays and the relationship between them 
	in the C programming language.

	For me personally, there are lots of things about pointers and arrays in C that are super 
	confusing, especially about the notation and how the C compilers understands it in different
	contexts.

	Of course, as any other file in the side quests folder, you may read it if you're curious, but it
	strictly doesn't have anything to do with the main problems themselves, they are just there so I 
	expieremnt with concepts and improve my understanding of the C programming language.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testIfArrayVarReducesToPtrToFirstElement();
void subscriptNotationArrays();
void subscriptNotationPtrs();
/*int[5] tryToReturnAnArray();*/ //failed as expected
void passArrToFunAndEditIt(int arr[], size_t arrlength);
void passArrToFunAndEditItPtrs(int *arr, size_t arrlength);
void arrWithoutSize();

int* return1DArrayUsingPtrs1();


//general functions
void display1DNumericArray_int(int* arr, size_t arrSize);
void display2DNumericArray(int (*arr)[], size_t rows, size_t cols);
int main()
{	
	printf("%i", *return1DArrayUsingPtrs1());
}

bool testIfArrayVarReducesToPtrToFirstElement()
{
	int arr[10];
	int *ptr = &arr[0];

	if(ptr == arr)
	{
		return true;
	}

	return false;
}

void subscriptNotationArrays()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};

	for(int i = 0; i<10; i++)
	{
		printf("Element %i of the array is %i\n", i, *(arr+i));
	}
}

void subscriptNotationPtrs()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int *ptr = arr;

	printf("the first element of this array is: %i\n", ptr[0]);

	for(int i = 1; i<10; i++)
	{
		printf("The %ith element of this array is %i\n", i+1, ptr[i]);
	}
}

//failed as expected
/*int[5] tryToReturnAnArray()
{
	int martrix[5];
	return martrix;
}*/

void passArrToFunAndEditIt(int arr[], size_t arrlength)
{
	//add 1 to all arr elements
	for(int i = 0; i<arrlength; i++)
	{
		arr[i] += 1;
	}
}

void passArrToFunAndEditItPtrs(int* arr, size_t arrlength)
{
	//multiply all arr elements by 10
	for(int i = 0; i<arrlength; i++)
	{
		arr[i] *= 10;
	}
}

void arrWithoutSize()
{
	int* ptr;
	ptr[0] = 1; //*(ptr + 0) = 1
	ptr[1] = 2; //*(ptr + 1) = 2
}

int* return1DArrayUsingPtrs1()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int *ptr = arr;

	for(int i = 0; i<10; i++)
	{
		printf("element %i of the array\n", i);
	}

	return ptr;
}

//general functions
void display1DNumericArray_int(int* arr, size_t arrSize)
{
		for(int i = 0; i<arrSize; i++)
	{
		//printing an integer if the array is of type int* and double if arr is double*
		printf("%i\n", arr[i]);

	printf("----------------------------------------------------------------------------------");
	printf("\n\n");
	}

}

void display2DNumericArray(int (*arr)[], size_t rows, size_t cols)
{
		/*
		Desired Output:

				col1	col2	col3
		row1       

		row2

		row3

		Notes: (1): cols has 2 tabs inserted before it
			   (2): between rows there are 2 new lines
			   (3): the space between each value is a tab

	*/
	int (*arr_specific_size)[cols];
	arr_specific_size = (int (*)[cols]) arr;

	printf("\t\t");

	for(int i = 0; i<rows; i++)
	{	
		printf("col%i\t", i+1);
	}

	printf("\n");
	for(int i = 0; i<rows; i++)
	{
		printf("row%i\t\t", i+1);
		for(int j = 0; j<cols; j++)
		{
			printf("%i\t", arr_specific_size[i][j]);
		}

		printf("\n\n");
	}
}