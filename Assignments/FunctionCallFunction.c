#include <stdio.h>

double half(double);
double multi_apply(double(*)(double), int, double);

int main(){
	int n = 4;
	double s = 32.0;
	double result;
	double (*pf)(double) = &half;
	result = multi_apply(*pf, n, s);
	printf("result: %f\n", result);
	return 0;
}

double multi_apply(double(*p)(double), int i, double call){
	for (i = i; i > 0; --i)
	{
		call = (*p)(call);
	}
	return call;
}

double half(double x){
	return x / 2;
}