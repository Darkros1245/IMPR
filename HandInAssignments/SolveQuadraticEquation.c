#include <stdio.h>
#include <math.h>

/*Initialization of funktions*/
float CalculateDiscriminant(float, float, float);
float CalculateFirstRoot(float, float, float);
float CalculateSecondRoot(float ,float, float);

int main(){
	/*Initialzaition of varibels*/
	float a, b, c, d, x1, x2;

	/*Start of loop*/
	while (1) {
		/*Getting the constants a, b and c*/
		printf("What is the constant a, b and c of the quadratic equation? ");
		scanf("%f%f%f", &a, &b, &c);

		/*If certain conditions are met, the loop will stop*/
		if (a == 0 && b == 0 && c == 0) break;

		/*Calculation of discriminant*/
		d = CalculateDiscriminant(a, b, c);

		/*Printing the roots*/
		if (d < 0) printf("There are no roots to that quadratic equation\n");

		else if (d == 0){
			/*Calculation of the root*/
			x1 = CalculateFirstRoot(a, b, d);
			printf("There is only one root to this quadratic equation, which is x = %f\n", x1);
		}

		else{
			/*Calculation of the two root*/
			x1 = CalculateFirstRoot(a, b, d);
			x2 = CalculateSecondRoot(a, b, d);
			printf("The first root is x1 = %f and the second root is x2 = %f\n", x1, x2);
		}
	}

	/*Program terminator*/
	return 0;
}

/*Formular for calculating the discriminant*/
float CalculateDiscriminant(float a, float b, float c){
	return (pow(b, 2) - 4 * a * c);
}

/*Formular for calculating the first root*/
float CalculateFirstRoot(float a, float b, float d){
	return ((-b + sqrt(d))/(2 * a));
}

/*Formular for calculating the second root*/
float CalculateSecondRoot(float a, float b, float d){
	return ((-b - sqrt(d))/(2 * a));
}