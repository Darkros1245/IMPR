#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double combine_right(const double*, int, double(*)(double, double));
double combine_left(const double*, int, double(*)(double, double));
double max(double, double);
double min(double, double);
double plus(double, double);
double minus(double, double);

int main(){
	int i;
	double result;
	int l = 7;
	double *a = malloc(sizeof(double) * l);
	srand(time(0));
	for (i = 0; i < l; ++i) *(a + i) = (double)(rand() % 100);
	for (i = 0; i < l; ++i) printf("%f ", *(a + i));
	printf("\n");

	result = combine_right(a, l, &minus);  /* minus(5, minus(7, minus(8, 11))) = 5 - (7 - (8 - 11)) = -5 */
	printf("Minus combination result: %f\n", result);

	result = combine_right(a, l, &plus);
	printf("Plus combination result: %f\n", result);

	result = combine_right(a, l, &min);
	printf("Min combination result: %f\n", result);

	result = combine_right(a, l, &max);
	printf("Max combination result: %f\n", result);

	result = combine_left(a, l, &minus);  /* minus(5, minus(7, minus(8, 11))) = 5 - (7 - (8 - 11)) = -5 */
	printf("Minus combination result: %f\n", result);

	result = combine_left(a, l, &plus);
	printf("Plus combination result: %f\n", result);

	result = combine_left(a, l, &min);
	printf("Min combination result: %f\n", result);

	result = combine_left(a, l, &max);
	printf("Max combination result: %f\n", result);

	return 0;
}

double combine_right(const double *a, int n, double (*combiner)(double, double)){
	int i;
	double res = a[n - 1];
	for (i = n - 2; i >= 0; i--) res = combiner(*(a + i), res);
	return res;
}

double combine_left(const double *a, int n, double (*combiner)(double, double)){
	int i;
	double res = a[0];
	for (i = 1; i < n; i++) res = combiner(res, *(a + i));
	return res;
}

double max (double a, double b){
  return a > b ? a : b;
}

double min (double a, double b){
  return a > b ? b : a;
}

double plus(double a, double b){
  return a + b;
}

double minus(double a, double b){
  return a - b;
}