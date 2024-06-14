
//solutions to the programming exercises of chapter 1 in Data Structures with C

 
//include statements
 #include <stdio.h>
 #include <string.h>
 #include <math.h>

//function declarations
void read_10_integers();
void even_numbers();
void vowels();
void address();
void shiftStr(char* str, int start);
void three_numbers();
void rightmost_digit();
void interest();
void compound_interest();
void salary();
void grocery_bill();
void print_bill(char* name1, char* name2, char* name3, int qty1, int qty2, int qty3
	, double price1, double price2, double price3);
void octalAndHexadecimal();

int main()
{
	octalAndHexadecimal();
return 0;
}

void read_10_integers()
{
	int a,b,c,d,e,f,g,h,i,j;
	scanf("%i \n %i \n %i \n %i \n %i \n %i \n %i \n %i \n %i \n %i \n", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
	printf("\n %i, %i, %i, \n %i, %i, %i, \n, %i, %i, %i, \n, %i", a ,b, c, d, e, f, g, h, i ,j);
}

void even_numbers()
{
	int sum = 0;
	int evenCount = 0;
	for(int i = 1; i<=200; i++)
	{
		if(i % 2 == 0)
		{
			evenCount++;
			sum+= i;

		}
	}

	printf("The count of even numbers is %i and their sum is %i", evenCount, sum);
}

void vowels()
{
	char text[100] = "This is a text that you can use to count the number of chars in it";
	int vowelCount = 0;
	for(int i = 0; i< strlen(text); i++)
	{
		if(text[i] == 'a' || text[i] == 'A' || text[i] == 'e' || text[i] == 'E' || text[i] == 'i' || 
			text[i] == 'I' || text[i] == 'o' || text[i] == 'O'|| text[i] == 'u' || text[i] == 'U')
		{
			vowelCount++;
		}
	}

	printf("The number of vowles in the text is %i", vowelCount);
}

void address()
{
	//e.g.: Building No. 9,Sawaf Street,Gharbia Governorate,Egypt        
	char address[100];
	printf("Please Enter Your Address: \n");
	scanf("%[^\n]s" /* the scanset [^\n] allows the scanf function to read whitespaces */, address);

	//formatting the address so that each part is displayed on its own line
	for(int i = 0; i<strlen(address); i++)
	{
		if(address[i] == ',')
		{
			shiftStr(address, i+1);
		}
	}

	printf("%s", address);
}

void shiftStr(char* str, int start)
{
	for(int i = strlen(str) - 2; i == start; i--)
	{
		str[i+1] = str[i];
		str[i] = ' ';
	}

	str[start] = '\n';
}

void three_numbers()
{
	float firstNum, secondNum;
	int sum;

	printf("Enter the two floating point numbers \n");
	scanf("%f %f", &firstNum, &secondNum);

	sum = firstNum + secondNum;

	printf("The first number is %f, \n the second number is %f \n and the integer sum is %i", firstNum, secondNum, sum);
}

//supposed to calculate the rightmostd digit but calculated the leftmost digit by mistake :)
void rightmost_digit()
{
	float f;
	int i, logValue;


	printf("Enter the floating point number: \n");
	scanf("%f", &f);

	//assigning f to i to truncate the decimal part
	i = f;

	//mathematical manipulations to get the leftmost digit
	logValue = log10(i);
	i /= pow(10, logValue);

	printf("The leftmost digit of the number is %i", i);
}

void interest()
{
	double base, rate, yrs; 
	printf("Enter the base amount, the rate (e.g. 0.56), and the number of years\n");
	scanf("%lf %lf %lf", &base, &rate, &yrs);

	base+= (rate * base) * yrs;
	printf("The result is : %lf", base);
}

void compound_interest()
{
	double base, rate, yrs, frequency, result;
	printf("Enter the base amount, the rate (e.g. 0.56), the number of years and how often the rate is applied per year\n");
	scanf("%lf %lf %lf %lf", &base, &rate, &yrs, &frequency);

	result = base * pow(1 + (rate/frequency), frequency * yrs);
	printf("The result is: %lf", result);
}

void salary()
{
	const double TA = 0.05;
	const double HRA = 0.1;
	double salary;

	printf("Please Enter your Base Salary: \n");
	scanf("%lf", &salary);

	salary += (salary * TA) + (salary * HRA);
	printf("%lf", salary);
}

void grocery_bill()
{
	//lets suppose that there are 3 grocery items
	char name1[50], name2[50], name3[50];
	int qty1, qty2, qty3;
	double price1, price2, price3;

	for(int i = 1; i<=3; i++)
	{
		switch(i)
		{
		case 1:
			printf("Enter the name of item 1 \n");
			scanf("%s", name1);
			printf("Enter the quantity of item 1 \n");
			scanf("%i",&qty1);
			printf("Enter the price of item 1 \n");
			scanf("%lf", &price1);
			break;
		case 2:
			printf("Enter the name of item 2 \n");
			scanf("%s", name2);
			printf("Enter the quantity of item 2 \n");
			scanf("%i", &qty2);
			printf("Enter the price of item 2 \n");
			scanf("%lf", &price2);
			break;
		case 3:
			printf("Enter the name of item 3 \n");
			scanf("%s", name3);
			printf("Enter the quantity of item 3 \n");
			scanf("%i", &qty3);
			printf("Enter the price of item 3 \n");
			scanf("%lf", &price3);
			break;
		default:
			break;+++++++
		}
	}

	print_bill(name1, name2, name3, qty1, qty2, qty3, price1, price2, price3);
}

void print_bill(char* name1, char* name2, char* name3, int qty1, int qty2, int qty3, double price1, double price2, double price3)
{
	printf("*********************BILL***************************** \n");
	printf("Item	Quantity	Price    Amount\n");
	printf("__________________________________________________________\n");
	printf("%s 		%i 			%f 		 %lf", name1, qty1, price1, (qty1 * price1));
	printf("%s 		%i 			%f 		 %lf", name2, qty2, price2, (qty2 * price2));
	printf("%s 		%i 			%f 		 %lf", name3, qty3, price3, (qty3 * price3));
}

void octalAndHexadecimal()
{
	int integer;
	printf("Enter the number you want to convert to octal and hexadecimal: \n");
	scanf("%i", &integer);
	//converting to hexa
	printf("The number in hexa is %#x", integer);

	//converting to octal
	printf("The number in octal is %#o", integer);
}


void exponentialFormat()
{
	-++
}