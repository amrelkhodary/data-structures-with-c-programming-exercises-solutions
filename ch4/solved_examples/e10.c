/*
	replace one pattern with another in a string
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void takeUserInput(char* strPtr, char* r_patternPtr, char* i_patternPtr);
void replaceAllPatterns(char* str, char* r_pattern, char* i_pattern);
void replaceSinglePattern(char* str, char* i_pattern, int start_index);
bool isPattern(char* str, char* pattern, int start_index, int end_index);
void shift_left(char* str, int amount);
void shift_right(char* str, int amount);
void copy(char* str, int first_index, int second_index);


int main()
{
	char str[100], r_pattern[100], i_pattern[100];
	takeUserInput(str, r_pattern, i_pattern);

	replaceAllPatterns(str, r_pattern, i_pattern);

	printf("The final string is: \n%s", str);

	//shift_test();

}






void takeUserInput(char* strPtr, char* r_patternPtr, char* i_patternPtr)
{
	printf("please enter the main string\n");
	gets(strPtr);
	printf("please enter the pattern to be removed\n");
	gets(r_patternPtr);
	printf("please enter the pattern to be inserted\n");
	gets(i_patternPtr);
}

void replaceSinglePattern(char* str, char* i_pattern, int start_index)
{
	for(int i = start_index; i < (start_index + (strlen(i_pattern))); i++)
	{
		str[i] = i_pattern[i - start_index];
	}
}

void replaceAllPatterns(char* str, char* r_pattern, char* i_pattern)
{
	const int R_PATTERN_LENGTH = strlen(r_pattern);
	const int I_PATTERN_LENGTH = strlen(i_pattern);

	for(int i = 0, j = strlen(r_pattern) - 1; i<strlen(str); i++, j++)
	{
		if(isPattern(str, r_pattern, i, j))
		{
			if(I_PATTERN_LENGTH < R_PATTERN_LENGTH){
				shift_left(str+i, (R_PATTERN_LENGTH - I_PATTERN_LENGTH));
			}
			else if(I_PATTERN_LENGTH > R_PATTERN_LENGTH){
				shift_right(str+i, (I_PATTERN_LENGTH - R_PATTERN_LENGTH));
			}
			replaceSinglePattern(str, i_pattern, i);
		}
	}
}

bool isPattern(char* str, char* pattern, int start_index, int end_index)
{
	if(strlen(pattern) != (end_index-start_index+1))
	{
		return false;
	}

	for(int i = start_index; i<=end_index; i++)
	{
		if(str[i] != pattern[i - start_index])
		{
			return false;
		}
	}

	return true;
}

void shift_left(char* str, int amount)
{
	const int AFTER_FIRST_INDEX = 1;

	for(int i = AFTER_FIRST_INDEX; i<=strlen(str); i++)
	{
		copy(str, i, i-amount);
	}
}

void shift_right(char* str, int amount)
{
	const int BEFORE_LAST_INDEX = strlen(str);

	for(int i = BEFORE_LAST_INDEX; i >= 0; i--)
	{
		copy(str, i, i+amount);
	}

}

void copy(char* str, int first_index, int second_index)
{
	if(second_index >=0)
	{
		str[second_index] = str[first_index];
	}

}