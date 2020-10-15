#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "primes.h"

int NextUnevenPrime(int);

int main(){
	int i;
	int Prime = 3;
	for (i = 8; i <= 2000000; i += 2){
		while (!is_prime(i-Prime)) Prime = NextUnevenPrime(Prime);
		printf("%d = %d + %d\n", i, Prime, i - Prime);
		Prime = 3;
	}

	return 0;
}

int NextUnevenPrime(int num){
	num++;
	while (!(is_prime(num) && num % 2 == 1)) num++;
	return num;
}