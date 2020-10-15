#include <stdio.h>
#include <math.h>

int CalculateDiscriminant(int, int, int);
int CalculateFirstRoot(int, int, int);
int CalculateSecondRoot(int, int, int);

int main(){
	int a, b, c, d, x1, x2;
	printf("What is the constant a, b and c of the quadratic equation? ");
	scanf("%d%d%d", &a, &b, &c);
	d = CalculateDiscriminant(a, b, c);
	if (d < 0) printf("There are no roots to that quadratic equation\n");
	else if (d == 0){
		x1 = CalculateFirstRoot(a, b, d);
		printf("There is only one root to this quadratic equation, which is x = %d\n", x1);
	}
	else{
		x1 = CalculateFirstRoot(a, b, d);
		x2 = CalculateSecondRoot(a, b, d);
		printf("The first root is x1 = %d and the second root is x2 = %d\n", x1, x2);
	}

	return 0;
}

int CalculateDiscriminant(int a, int b, int c){
	return (pow(b, 2) - 4 * a * c);
}

int CalculateFirstRoot(int a, int b, int d){
	return ((-b + sqrt(d))/(2 * a));
}

int CalculateSecondRoot(int a, int b, int d){
	return ((-b - sqrt(d))/(2 * a));
}