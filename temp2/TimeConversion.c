#include <stdio.h>

int main()
{
	/*Calculation of the time constants, seconds in some bigger time*/
	const int SecondsInMin = 60;
	const int SecondsInHour = SecondsInMin * 60;

	/*Initializing of time variabels*/
	int hours, min, sec;
	/*Initializing of the temporary variabel for calculation*/
	int startSec, tempSec;
	int howMany = 0;

	printf("How many seconds has to be converted? ");
	/*Looking for an integer, and saving it to the address of tempSec, so tempSec now equals that integer*/
	scanf("%d", &startSec);
	tempSec = startSec;

	/*Division tells how many of it, is in the tempSec*/
	/*Modulos tells what is left, so it can be used for further calculation*/
	/*Convertion of the seconds to different types of time, and getting the remainder*/
	hours = tempSec / SecondsInHour;
	tempSec %= SecondsInHour;
	min = tempSec / SecondsInMin;
	/*This may be redaundant, could be 1 line*/
	tempSec %= SecondsInMin;
	sec = tempSec;

	/*Prints the first part of the string in correct time*/
	if (startSec == 0 || startSec > 1) printf("%d sekunder svarer til ", startSec);
	else printf("%d sekund svarer til ", startSec);

	/*Calculates how many there has to be printed*/
	if (hours > 0) howMany++;
	if (min > 0) howMany++;
	if (sec > 0) howMany++;

	/*If 0 has to be printed, then the input is 0, and it prints like that*/
	if (howMany == 0) printf("%d sekunder", sec);
	/*If one has to be printed, it checks if it should print in singular or pluralis, using nested ternary expresions*/
	else if (howMany == 1){
		hours == 0 ? 0 : hours == 1 ? printf("%d time", hours) : printf("%d timer", hours);
		min == 0 ? 0 : min == 1 ? printf("%d minut", min) : printf("%d minutter", min);
		sec == 0 ? 0 : sec == 1 ? printf("%d sekund", sec) : printf("%d sekunder", sec);
	}
	/*If two has to be printed, it checks if it should print in singular or pluralis, and where to place an "and", using nested ternary expresions*/
	else if (howMany == 2){
		if (hours > 0){
			hours == 0 ? 0 : hours == 1 ? printf("%d time og ", hours) : printf("%d timer og ", hours);
			min == 0 ? 0 : min == 1 ? printf("%d minut", min) : printf("%d minutter", min);
			sec == 0 ? 0 : sec == 1 ? printf("%d sekund", sec) : printf("%d sekunder", sec);
		}
		else{
			min == 0 ? 0 : min == 1 ? printf("%d minut og ", min) : printf("%d minutter og ", min);
			sec == 0 ? 0 : sec == 1 ? printf("%d sekund", sec) : printf("%d sekunder", sec);
		}
	}
	/*If all three has to be printed, it checks if it should print in singular or pluralis, and adds an "," and an "and" the correct place, using nested ternary expresions*/
	else if (howMany == 3){
		hours == 0 ? 0 : hours == 1 ? printf("%d time, ", hours) : printf("%d timer, ", hours);
		min == 0 ? 0 : min == 1 ? printf("%d minut og ", min) : printf("%d minutter og ", min);
		sec == 0 ? 0 : sec == 1 ? printf("%d sekund", sec) : printf("%d sekunder", sec);
	}

	/*Prints newline*/
	printf("\n");

	/*Program terminator*/
	return 0;
}