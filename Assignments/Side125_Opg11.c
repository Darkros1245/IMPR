#include <stdio.h>

int main()
{
	int m, n;
	int side1, side2, hyp;
	printf("Give two integers m and n, to calculate an pythagorean triple: ");
	scanf("%d%d", &n, &m);
	if (m > n) side1 = m * m - n * n;
	else side1 = n * n - m * m;
	side2 = 2 * m * n;
	hyp = m * m + n * n;
	printf("The pythagorean triple is:\nSide 1: %d\nSide 2: %d\nHyp.: %d\n", side1, side2, hyp);
	return 0;
}