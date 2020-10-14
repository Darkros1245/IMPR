#include <stdio.h>

int main(){
	int n, i;
	int sum = 0;
	printf("Write a number: ");
	scanf("%d", &n);

	if (n >= 0) for (i = n; i < 2 * n; ++i) sum += i;
	else for (i = 2 * n; i < n; ++i) sum += i;
	printf("the sum is %d\n", sum);
	return 0;
}