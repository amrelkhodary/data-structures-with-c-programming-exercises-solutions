 //this is the solutions file for chapter 3 of the the textbook "Data Structures with C"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	pn, n indicates the number of the programming problem (i.e. p1 = solution to the first problem, p2 = solution to the second
	etc..)
	
	sometimes a problem is too big to be written in a single function so we'll need to use multiple subroutines, those kinds
	of functions will be written as snpn (sn = subroutine number n, pn = problem number n)

	also, there are many functionalities that may be frequently needed throughout the problems, those functions will be named 
	according to their functionality and they will be appended to the end of this file.

	*Sometimes i might skip problems because they are too easy
	*Sometimes i might solve the problem but using different numerical values for whatever reason.
	*Problem 14 is solved in its own file.

	Have Fun :)

*/

//problem functions
void p1(); 
double* s1p1(int marks[3][5]);
double* s2p1(int marks[3][5]);
int s3p1(int marks[3][5]);
void s4p1(int marks[3][5]);
void p2();
void p3(int arr[], size_t arrSize);
void p5();
int p7();
int **p8();
int p9(int (*matrix)[3], size_t numOfRows, size_t numOfCols);
int p10(int (*arr)[], size_t numOfRows, size_t numOfCols);
int (*p11(int (*arr)[], size_t numOfRows, size_t numOfCols))[];
float* p12(float* firstArr, size_t firstArr_size, float* secondArr, size_t secondArr_size);

//general purpose functions
void display1DNumericArray(double* arr, size_t arrSize);
void display1DNumericArray_int(int* arr, size_t arrSize);
void display2DNumericArray(int(*arr)[5] , size_t numOfRows, size_t numOfCols);
void display2DNumericArrayUsingPtrs(int** arr, size_t numOfRows, size_t numOfCols);
int (*dynAllocateMemFor2DArray(size_t numOfRows, size_t numOfCols))[];
void freeDynAllocatedMemoryFor2DArray(int (*ptr)[]);
float* mergeTwoArrays_float(float* firstArr, size_t firstArr_size, float* secondArr, size_t secondArr_size);
void reverseArr_float(float* arr, size_t arr_size);
void swapTwoArrElements_float(float* arr, int firstElement_index, int secondElement_index);

int main()
{
	//choose any problem you want to run and call its function here
	float firstArr[3] = {1.0, 2.0, 3.0};
	float secondArr[3] = {4.0, 5.0, 6.0};

	float* mergedReversedArr = p12(firstArr, 3, secondArr, 3);

	for(int i = 0; i<6; i++)
	{
		printf("%f\n", mergedReversedArr[i]);
	}

	return 0;

}

void p1()
{
	/*
		1. Consider an array MARKS[20][5] which stores the
		   marks obtained by 20 students in 5 subjects. Now write a program to:

			(a) find the average marks obtained in each
				subject.
			(b) find the average marks obtained by every
				student

			(c) find the number of students who have scored
				below 50 in their average. 

				(*orginal says below 50, but i did below 10 because my version has the max mark to be 20, same idea though :) )

			(d) display the scores obtained by every student.

			*The original question asks us to consider the marks of 20 students and 5 subjects, 
			but that will be too long of an array to write out, so i will consider instead a more simple 3
			students and 5 subjects but you get the general idea. 
	*/

	int marks[3][5] = {18, 19, 13, 14, 2,	15, 13, 7, 8, 10,	12, 16, 10, 20, 20};
	double* avgMarkForEverySubject = s1p1(marks);
	double* avgMarkForEveryStudent = s2p1(marks);
	int numberOfStudentsWhoScoredBelow10 = s3p1(marks);

	printf("The average mark for every subject is: \n\n");
	display1DNumericArray(avgMarkForEverySubject, 5);

	printf("The average mark for every student is: \n\n");
	display1DNumericArray(avgMarkForEveryStudent, 3);

	printf("The number of students who scroed below 10 in their avegerage is: %i\n\n", numberOfStudentsWhoScoredBelow10);

	s4p1(marks);


	free(avgMarkForEverySubject); //array was dynamically allocated so the mem has to be freed
	free(avgMarkForEveryStudent); //array was dynamically allocated so the mem has to be freed
}

double* s1p1(int marks[3][5])
{
	double* avgMarkForEverySubject = (double*) malloc(5 * sizeof(double));
	if(avgMarkForEverySubject == NULL)
	{
		printf("ERROR: failed to allocate memory for avgMarkForEverySubject array in s1p1 function\n");
		return NULL;
	}

	//variable for holding the temporary sum of the marks for each subject
	double temp = 0;
	for(int col = 0; col<5; col++)
	{
		for(int row = 0; row<3; row++)
		{
			temp+= marks[row][col];
		}

		temp/=3; //dividing by the number of students to get the average
		avgMarkForEverySubject[col] = temp;
		temp = 0; //resetting temp for next iteration
	}

	return avgMarkForEverySubject;
}

double* s2p1(int marks[3][5])
{
	double* avgMarkForEveryStudent = (double*) malloc(3 * sizeof(double));
	if(avgMarkForEveryStudent == NULL)
	{
		printf("ERROR: failed to allocate memory for avgMarkForEveryStudent array in s2p1 function\n");
		return NULL;
	}

	double temp;
	for(int row = 0; row<3; row++)
	{
		for(int col = 0; col<5; col++)
		{
			temp+=marks[row][col];
		}

		temp/=5; //dividing by the number of subjects to get the average
		avgMarkForEveryStudent[row] = temp;
		temp = 0; //resetting temp for next iteration
	}

	return avgMarkForEveryStudent;
}

int s3p1(int marks[3][5])
{
	int count = 0; //count variable to store the number of students who scored below 10 in their average
	double* avgMarkForEveryStudent = s2p1(marks);

	for(int i = 0; i<3; i++)
	{
		if(avgMarkForEveryStudent[i] < 10)
		{
			count++;
		}
	}

	return count;
}

void s4p1(int marks[3][5])
{
	printf("The scores of every student is: \n\n");
	display2DNumericArray(marks, 3, 5);
}


void p2()
{
	/*
		Write a program that reads and array of 100 integers. Display all the pairs of elements whose sum is 50
	*/

	//getting input from the user
	int numbers[100] = {};
	printf("Please Enter your numbers" );
	for(int i = 0; i<100; i++)
	{
		scanf("%i\n", &numbers[i]);
	}

	//displaying the pairs of integers whose sum is 50
	/*
		the algorithm will work as following:- 

		for every element i in the numbers array:
			go through all elements after E after i, and for every element e:
				if i + e = 50, display the pair
	*/

	for(int i = 0; i<100; i++)
	{
		for(int j = i+1; j<100; j++)
		{
			if(numbers[i] + numbers[j] == 50)
			{
				printf("%i and %i sum to 50", numbers[i], numbers[j]);
			}
		}
	}
}

void p3(int arr[], size_t arrSize)
{
	int temp = arr[1];
	arr[1] = arr[arrSize - 2];
	arr[arrSize - 2] = temp;



	display1DNumericArray_int(arr, arrSize);
}

void p5()
{
	/*
		write a program to calculate the sum and mean of elements of a 2D array
	*/

	int twoDArr[2][3] = {1,2,3,
				 4,5,6};
	int sum = 0;
	double mean;

	//calculating the sum
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<3; j++)
		{
			sum+= twoDArr[i][j];
		}
	}

	mean = (double)sum / 6; //mean = sum / number of elements (6)

	printf("The sum of the elements is: %i\n", sum);
	printf("The mean of the elements is: %lf\n", mean);
}

int p7()
{
	/*
		Write a program that computes the sum of elements that are stored on the main diagonal of a 
		matrix using pointers

		A 3x3 Matrix is represented by using 2D array of size [3][3]
	*/

	int matrix[3][3] = {4,6,7,
						8,19,2,
						90,10,3};
	/*
		Pointer arithmetic
		lets say that we have a pointer ptr that points to the first element of the matrix
		{x1, x2, x3 ,x4, x5, x6, x7, x8, x9}

		the pointers for the elements that we need to sum:
		1- ptr1 to the first element
		2- ptr2 to the fifth element
		3- ptr3 to the ninth element
	*/

	int* firstElementPtr = &matrix[0][0];
	int* fifthElementPtr = &matrix[1][1];
	int* ninthElementPtr = &matrix[2][2];

	return (*firstElementPtr + *fifthElementPtr + *ninthElementPtr); 
}

int **p8()
{
	int first_matrix[3][3] =  {4,6,7,
							   8,19,2,
							   90,10,3};

	int second_matrix[3][3] = {4,6,7,
							   8,19,2,
							   90,10,3};


	//allocating the memory for the sum_matrix
	int** sum_matrix = (int**) malloc(3 * sizeof(int*));
	if(sum_matrix == NULL)
	{
		printf("ERROR: Failed to allocate memory to sum_matrix in function p8\n");
		exit(-1);
	}

	for(int i = 0; i<3; i++)
	{
		sum_matrix[i] = (int*) malloc(3 * sizeof(int));
		if(sum_matrix[i] == NULL)
		{
			printf("ERROR: Failed to allocate memory to sum_matrix[%i] in function p8\n", i);
			exit(-1);
		}
	}


	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			sum_matrix[i][j] = first_matrix[i][j] + second_matrix[i][j];
		}
	}
	display2DNumericArrayUsingPtrs(sum_matrix, 3, 3);
	return sum_matrix;
}

int p9(int (*matrix)[3], size_t numOfRows, size_t numOfCols)
{
	/*
		Write a program that computes the product of the elements that are stored
		on the diagonal about the main diagonal

		Note that the elements on the diagonal are the elements where i = j, an element
		is considered above the diagonal if it is to the left of a diagonal element.

		The algorithm: 
		(pardon my horrible psuedocode, was too lazy to learn the syntax of psuedocode in algos class :) )

		product = 1
		for all diagonal elements D:
			for every element e to the left of a diagonal element d:
				product*=e


	*/

	int product = 1;
	for(int i = 0; i<numOfRows /* could have used numOfCols too since matrix is symmetrical*/; i++)
	{
		for(int j = i+1; j<numOfRows /*could've also used numOfCols here too*/; j++)
		{
			product *= matrix[i][j];
		}
	}

	return product;
}

int p10(int (*arr)[], size_t numOfRows, size_t numOfCols)
{
	/*
		Write a program to count the total number of non-zero elements in a two-dimensional 
		array
	*/

	int count = 0;

	//make arr have a specifc size
	int (*arr_specific_size)[numOfCols] = (int (*)[numOfCols]) arr;

	//count the number of non-zero elements using nested for loop
	for(int i = 0; i<numOfRows; i++)
	{
		for(int j = 0; j<numOfCols; j++)
		{
			if(arr_specific_size[i][j] != 0)
			{
				count++;
			}
		}
	}
	return count;
}

int (*p11(int (*arr)[], size_t numOfRows, size_t numOfCols))[]
{
	/*
		Write a program to input the elements of a two-dimensional array.
		Then from this array, make two arrays --one that stores all the odd 
		elements of the array and othe other that stores all even elements of the array

		Algorithm:
		1- Dynamically allocate a 2D array, with 2 rows and numOfRows * numOfColumns columns
		2- Loop through the input 2D array, and add even elements in first row of our dyn alloc. 2D
		   and add odd elements in second row of our dyn alloc. 2D array
		3- Return the 2D array the we dynamically allocated
		4- Free the memory allocated for the 2D array

		we will need 2 general functions, one to dynamically allocate memory for our 2D array
		and another to free this memory
	*/

	//giving the input array a specific size
	int (*arr_specific_size)[numOfCols] = (int (*)[numOfCols]) arr;
	
	/*
		the size of the column in our 2D dynamically allocate array is 
		numOfRows * numOfCols because the number of odd/even elements can't 
		exceed the total number of elements in the input array
		(total number of elements in a 2D array = number of rows * number of columns)
	*/
	int (*result)[numOfRows * numOfCols] = dynAllocateMemFor2DArray(2, numOfRows * numOfCols); 

	for(int i = 0, index_odd = 0, index_even = 0; i<numOfRows; i++)
	{
		for(int j = 0; j<numOfCols; j++)
		{
			if(arr_specific_size[i][j] % 2 == 0)
			{
				//element is even
				result[0][index_even] = arr_specific_size[i][j];
				index_even++;
			}
			else
			{
				//element is odd
				result[1][index_odd] = arr_specific_size[i][j];
				index_odd++;
			}
		}
	}

	return result;
}

float* p12(float* firstArr, size_t firstArr_size, float* secondArr, size_t secondArr_size)
{

	float* arr = mergeTwoArrays_float(firstArr, firstArr_size, secondArr, secondArr_size);
	reverseArr_float(arr, firstArr_size + secondArr_size);
	return arr;
}



//general functions defined below here
void display1DNumericArray(double* arr, size_t arrSize)
{
	for(int i = 0; i<arrSize; i++)
	{
		//printing an integer if the array is of type int* and double if arr is double*
		printf("%lf\n", arr[i]);

	printf("----------------------------------------------------------------------------------");
	printf("\n\n");
	}

}

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

void display2DNumericArray(int(*arr)[5] , size_t numOfRows, size_t numOfCols)
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

	printf("\t\t");

	for(int i = 0; i<numOfCols; i++)
	{	
		printf("col%i\t", i+1);
	}

	printf("\n");
	for(int i = 0; i<numOfRows; i++)
	{
		printf("row%i\t\t", i+1);
		for(int j = 0; j<numOfCols; j++)
		{
			printf("%i\t", arr[i][j]);
		}

		printf("\n\n");
	}
}

void display2DNumericArrayUsingPtrs(int** arr, size_t numOfRows, size_t numOfCols)
{
		/*
			This is the EXACT SAME FUNCTION as display2DNumericArray but it takes in
			for its first argument int** arr instead of int (*arr)[5], i had to do this because 
			C is a horrible programming language :)
		*/


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

	printf("\t\t");

	for(int i = 0; i<numOfCols; i++)
	{	
		printf("col%i\t", i+1);
	}

	printf("\n");
	for(int i = 0; i<numOfRows; i++)
	{
		printf("row%i\t\t", i+1);
		for(int j = 0; j<numOfCols; j++)
		{
			printf("%i\t", arr[i][j]);
		}

		printf("\n\n");
	}
}

int (*dynAllocateMemFor2DArray(size_t numOfRows, size_t numOfCols))[]
{
	int (*ptr)[numOfCols] = (int (*)[numOfCols]) calloc(numOfRows, numOfCols * sizeof(int));
	return ptr;
}

void freeDynAllocatedMemoryFor2DArray(int (*ptr)[])
{
	free(ptr);
}

float* mergeTwoArrays_float(float* firstArr, size_t firstArr_size, float* secondArr, size_t secondArr_size)
{
	float* mergedArr = (float*) calloc(firstArr_size + secondArr_size, sizeof(float));
	if(mergedArr == NULL)
	{
		printf("ERROR: failed to allocate memeory for mergedArr in mergeTwoArrays_float()");
		exit(-1);
	}

	//add the first array
	for(int i = 0; i<firstArr_size; i++)
	{
		mergedArr[i] = firstArr[i];
	}

	//add the second array
	for(int i = firstArr_size; i<firstArr_size + secondArr_size; i++)
	{
		mergedArr[i] = secondArr[i-firstArr_size];
	}

	return mergedArr;
}

void reverseArr_float(float* arr, size_t arr_size)
{
	/*
		The Algorithm:
		1- We'll have a pointer i pointing to the beginning of the array
		   and a pointer j pointing to the end of the array
		2- As long as i<j, keep swapping the values of arr[i] and arr[j]
	*/
	for(int i = 0, j = arr_size - 1; (i<j); i++, j--)
	{
		swapTwoArrElements_float(arr, i, j);
	}
}

void swapTwoArrElements_float(float* arr, int firstElement_index, int secondElement_index)
{
	float temp = arr[firstElement_index];
	arr[firstElement_index] = arr[secondElement_index];
	arr[secondElement_index] = temp;
}