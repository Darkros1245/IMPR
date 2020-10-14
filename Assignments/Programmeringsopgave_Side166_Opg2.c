#include <stdio.h>

int DepatureTime(int, int, int);

int main(){
	int distance, speed, arrivalTime, depatureTime;

	printf("How long is the travel, (km)? ");
	scanf("%d", &distance);
	printf("At what speed are you traveling, (km/h)? ");
	scanf("%d", &speed);
	printf("When do you need to arrive, (xxxx)? ");
	scanf("%d", &arrivalTime);

	depatureTime = DepatureTime(distance, speed, arrivalTime);
	printf("Then you should depart at %d o'clock\n", depatureTime);

	return 0;
}

int DepatureTime(int distance, int speed, int arrivalTime){
	int travelTime = 60 * distance / speed;
	return (arrivalTime - travelTime);
}