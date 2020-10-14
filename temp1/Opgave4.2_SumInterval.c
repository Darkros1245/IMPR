#include <stdio.h>

int main(){
	int m, n, k, sum = 0, i;
	do {
	printf("Give three numbers, m, n and k, where k > 0: ");
	scanf("%d%d%d", &m, &n, &k);
	} while (k < 1);
	for (i = (m >= n ? n : m); i <= (m >= n ? m : n); ++i) if (i % k == 0) sum += i;
	printf("The sum is: %d\n", sum);
	return 0;
}