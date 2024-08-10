/*
	Write a program to read, display, add, and subtract two distances. Distance must be defined
	using kms and meters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADD 3
#define SUBTRACT 7

typedef struct{
	int kilometers;
	int meters;
} Distance;

Distance readDistance();
void displayDistance(Distance distance);
Distance addOrSubtractDistances(Distance firstDistance, Distance secondDistance, int flag);

int main()
{
	Distance firstDistance = readDistance();
	Distance secondDistance = readDistance();
	displayDistance(addOrSubtractDistances(firstDistance, secondDistance, ADD));
}

Distance readDistance()
{
	Distance nDistance;
	printf("Please enter the distance in kilometers, meters: \n");
	scanf("%i", &nDistance.kilometers);
	scanf("\n%i", &nDistance.meters);

	return nDistance;
}

void displayDistance(Distance distance)
{
	printf("The distance in kilometers is %i and in meters is %i\n", distance.kilometers, distance.meters);
}

Distance addOrSubtractDistances(Distance firstDistance, Distance secondDistance, int flag)
{
	Distance result;
	switch(flag)
	{
	case ADD:
		result.kilometers = firstDistance.kilometers + secondDistance.kilometers;
		result.meters = firstDistance.meters + secondDistance.meters;
		break;
	case SUBTRACT:
		result.kilometers = firstDistance.kilometers - secondDistance.kilometers;
		result.meters = firstDistance.meters - secondDistance.meters;
		break;
	default:
		printf("INVALID INPUT\n");
	}

	return result;
}