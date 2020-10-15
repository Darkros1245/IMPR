#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "primes.h"

int main(){
	int n = 1;
	int i = 2;
	while (n <= 100){
		if (is_prime(i)){
			printf("prime %d: %d\n", n, i);
			n++;
		}
		i++;
	}

	return 0;
}