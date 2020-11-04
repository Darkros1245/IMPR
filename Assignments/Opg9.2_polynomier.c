#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getPolynomium(double **, int *);
void getPolynomiumDegree(int *);
void getCoefficients(double *, int);
double evalPolynomium(double *, int, int);

int main(){
	double *pc = NULL;
	int c;
	int x = 2;
	double y;
	getPolynomium(&pc, &c);
	y = evalPolynomium(pc, c + 1, x);
	printf("%f\n", y);
	
	free(pc);
	return 0;
}

void getPolynomium(double **pc, int *c){
	getPolynomiumDegree(c);
	*pc = malloc(sizeof(double) * (*c + 1));
	getCoefficients(*pc, *c);
}

void getPolynomiumDegree(int *c){
	printf("What degree is the polynomium? Min. is 0 and max. is 8. ");
	scanf(" %d", c);
}

void getCoefficients(double *pc, int c){
	printf("What are the coefficients? ");
	switch(c){
		case 0:
			scanf(" %lf", pc + 0);
			break;
		case 1:
			scanf(" %lf %lf", pc + 0, pc + 1);
			break;
		case 2:
			scanf(" %lf %lf %lf", pc + 0, pc + 1, pc + 2);
			break;
		case 3:
			scanf(" %lf %lf %lf %lf", pc + 0, pc + 1, pc + 2, pc + 3);
			break;
		case 4:
			scanf(" %lf %lf %lf %lf %lf", pc + 0, pc + 1, pc + 2, pc + 3, pc + 4);
			break;
		case 5:
			scanf(" %lf %lf %lf %lf %lf %lf", pc + 0, pc + 1, pc + 2, pc + 3, pc + 4, pc + 5);
			break;
		case 6:
			scanf(" %lf %lf %lf %lf %lf %lf %lf", pc + 0, pc + 1, pc + 2, pc + 3, pc + 4, pc + 5, pc + 6);
			break;
		case 7:
			scanf(" %lf %lf %lf %lf %lf %lf %lf %lf", pc + 0, pc + 1, pc + 2, pc + 3, pc + 4, pc + 5, pc + 6, pc + 7);
			break;
		case 8:
			scanf(" %lf %lf %lf %lf %lf %lf %lf %lf %lf", pc + 0, pc + 1, pc + 2, pc + 3, pc + 4, pc + 5, pc + 6, pc + 7, pc + 8);
			break;
		default:
			break;
	}
}

double evalPolynomium(double *pc, int l, int x){
	double sum;
	int i;
	for (i = 0; i < l; ++i) sum += (*(pc + i)) * pow(x, i);
	return sum;
}