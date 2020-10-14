#include <stdio.h>

int main(){
	/*Initialization of varibels*/
	int a, b, GCD;
	int i;
	do {
		/*Error handeling, if the input is 0*/
		do {
			printf("Give two numbers, a and b, where a and b are integers greater than 0, to calculate the greatest common divisor: ");
			scanf("%d%d", &a, &b);
		} while (a == 0 || b == 0);		/*The user will be promted until their input numbers is an integer greater than 0*/
		/*Calculation of the greatest common dividor, with a ternary expression in the for loop to evaluate the smallest of the to input numbers*/
		for (i = (a >= b ? b : a); i >= 1; --i) {
			if (a % i == 0 && b % i == 0) {
				GCD = i;
				break;
			}
		}
		/*Printing the result*/
		if (a > 0 && b > 0) printf("The greatest common divisor of %d and %d is %d\n", a, b, GCD);
	} while (a > 0 && b > 0);
	/*Program terminator*/
	return 0;
}