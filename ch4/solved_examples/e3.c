/*
	append a source string to a destination string
*/

#include <stdio.h>

int findFirstNullInString(char* str, size_t strLength);
void copyFromSrcStringToDestinationString(char* srcStr, char* dstStr, int dst_first_null, int src_first_null);
void copySingleCharacter(char* srcStr, char* dstStr, int src_index, int dst_index);

int main()
{
	char src[100] = "Ahmed";
	char destination[100] = "I love the man named ";

	copyFromSrcStringToDestinationString(src, destination, findFirstNullInString(destination, 100), findFirstNullInString(src, 100));
	printf("the final string is: \n%s", destination);

}

int findFirstNullInString(char* str, size_t strLength)
{
	/*
		When defining an array, empty elements are filled with NULL,
		a destination array, by definition should have more space than its
		current elements, so it must have NULL elements, of course there is a case 
		where the destination array might not have more space, which I do not cover here
	*/

	for(int i = 0; i<strLength; i++)
	{
		if(str[i] == NULL)
		{
			return i;
		}
	}

	return -1;
}

void copyFromSrcStringToDestinationString(char* srcStr, char* dstStr, int dst_first_null, int src_first_null)
{
	//determining indexes that we will work with so things are easier
	const int DST_FIRST_INDEX = dst_first_null;
	const int SRC_LAST_INDEX = src_first_null - 1; 

	int i = 0;
	while(i <= SRC_LAST_INDEX)
	{
		copySingleCharacter(srcStr, dstStr, i, DST_FIRST_INDEX + i);
		i++;
	}
}	

void copySingleCharacter(char* srcStr, char* dstStr, int src_index, int dst_index)
{
	dstStr[dst_index] = srcStr[src_index];
}

