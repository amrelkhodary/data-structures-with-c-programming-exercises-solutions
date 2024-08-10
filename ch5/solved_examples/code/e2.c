/*
	write a program to read, display, add and substract two complex numbers
*/

#include <stdio.h>

typedef struct{
	float realPart;
	float imaginaryPart;
} ComplexNumber;

ComplexNumber readComplexNumber();
void displayComplexNumber(float realPart, float imaginaryPart);
ComplexNumber addTwoComplexNumbers(float firstRealPart, float firstImaginaryPart, float secondRealPart, float secondImaginaryPart);
ComplexNumber subtractTwoComplexNumbers(float firstRealPart, float firstImaginaryPart, float secondRealPart, float secondImaginaryPart);
void displayMenu();



int main()
{
	char input = '\0';


	ComplexNumber firstComplexNumber;
	ComplexNumber secondComplexNumber;
	ComplexNumber result;
	while(input != '!')
	{
		//TODO: write program logic
		displayMenu();
		scanf("\n%c", &input);

		switch(input)
		{
		case 'a':
			 firstComplexNumber = readComplexNumber();
			 secondComplexNumber = readComplexNumber();
			 result = addTwoComplexNumbers(firstComplexNumber.realPart, firstComplexNumber.imaginaryPart, 
														secondComplexNumber.realPart, secondComplexNumber.imaginaryPart);
			displayComplexNumber(result.realPart, result.imaginaryPart);
			break;
		case 'b':
			 firstComplexNumber = readComplexNumber();
			 secondComplexNumber = readComplexNumber();
			 result = subtractTwoComplexNumbers(firstComplexNumber.realPart, firstComplexNumber.imaginaryPart, 
														secondComplexNumber.realPart, secondComplexNumber.imaginaryPart);			
			displayComplexNumber(result.realPart, result.imaginaryPart);
		case '!':
			break;
		default:
			printf("INVALID INPUT.");
		}
	}
}



void displayMenu()
{
	printf("Hi! Welcome to the complex numbers C program, please choose one of the following options or press ! to exit.\n");
	printf("(a) add two complex numbers\n");
	printf("(b) subtract two complex numbers\n");
	printf("(!) exit\n");
}

ComplexNumber readComplexNumber()
{
	ComplexNumber nComplexNumber;

	printf("Please Enter the Real Part of the Complex Number");
	scanf("%f", &nComplexNumber.realPart);

	printf("Please Enter the Imaginary Part of the Complex Number");
	scanf("\n%f", &nComplexNumber.imaginaryPart);

	return nComplexNumber;
}

void displayComplexNumber(float realPart, float imaginaryPart)
{
	printf("The real part of the complex number is %f, and the imginary part of the complex number is %f\n", realPart, imaginaryPart);
}

ComplexNumber addTwoComplexNumbers(float firstRealPart, float firstImaginaryPart, float secondRealPart, float secondImaginaryPart)
{
	ComplexNumber nComplexNumber;

	nComplexNumber.realPart = firstRealPart + secondRealPart;
	nComplexNumber.imaginaryPart = firstImaginaryPart + secondImaginaryPart;

	return nComplexNumber;
}

ComplexNumber subtractTwoComplexNumbers(float firstRealPart, float firstImaginaryPart, float secondRealPart, float secondImaginaryPart)
{
	ComplexNumber nComplexNumber;

	nComplexNumber.realPart = firstRealPart - secondRealPart;
	nComplexNumber.imaginaryPart = firstImaginaryPart - secondImaginaryPart;

	return nComplexNumber;
}
