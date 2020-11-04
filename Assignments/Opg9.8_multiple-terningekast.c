#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_multiple_dies(int, int*);

int main(){
	int n, i, j;
	int *p;
	srand(time(0));

	for (i = 0; i < 10; ++i)
	{
		printf("How many times should the die be thrown? ");
		scanf(" %d", &n);
		p = malloc(sizeof(int) * n);
		roll_multiple_dies(n, p);
		for (j = 1; j <= n; ++j) printf("Throw %d: %d\n", j, *(p + j -1));
		free(p);
	}

	return 0;
}

void roll_multiple_dies(int n, int *p){
	int i;
	for (i = 0; i < n; ++i) *(p + i) = (rand() % 6) + 1;
}