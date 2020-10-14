#include <stdio.h>

int main()
{
	const float FM = 0.3048;
	int tempHouseX, tempHouseY;
	float houseX, houseY;
	int tempYardX, tempYardY;
	float yardX, yardY;
	float sizeOfField;
	float timeToLawnMow; 
	printf("What is the length and height of the yard, in meters? ");
	scanf("%d%d", &tempYardX, &tempYardY);
	printf("What is the length and height of the house, in meters? ");
	scanf("%d%d", &tempHouseX, &tempHouseY);
	yardX = tempYardX / FM;
	yardY = tempYardY / FM;
	houseX = tempHouseX / FM;
	houseY = tempHouseY / FM;
	sizeOfField = yardX * yardY - houseX * houseY;
	timeToLawnMow = sizeOfField / 2;
	printf("It will take %f seconds to mow the lawn\n", timeToLawnMow);
	return 0;
}