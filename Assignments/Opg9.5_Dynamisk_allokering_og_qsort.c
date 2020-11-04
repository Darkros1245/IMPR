#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc(const void*, const void*);

int main(){
	int i;
	double *p = malloc(sizeof(double) * 100);
	srand(time(0));
	for (i = 0; i < 100; ++i) *(p + i) = rand() % 100;
	for (i = 0; i < 100; ++i) printf("%f\n", *(p + i));
	printf("\n");
	qsort(p, 100, sizeof(double), cmpfunc);
	for (i = 0; i < 100; ++i) printf("%f\n", *(p + i));
	free(p);
	return 0;
}

int cmpfunc(const void *a, const void *b){
	return (*(double*)a - *(double*)b);
}