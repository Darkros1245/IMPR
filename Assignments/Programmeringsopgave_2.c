#include <stdio.h>
#define PI 3.14159

int main() {
	int First, Second, Third;
	int n = 5;
	int side = 5, size = 25;
	int radius;

	printf("Type 3 integers: ");
	scanf("%d%d%d", &First, &Second, &Third);
	printf("First = %d\nSecond = %d\nThird = %d\n", First, Second, Third);

	printf("The value of n is %d.\n", n);
	printf("The area of a square whose side length is %d cm is %d square cm.\n", side, size);

	printf("What is the radius of the cirkel? ");
	scanf("%d", &radius);
	printf("The area of the cirkel is then: %f\n", PI*radius*radius);
	
	return 0;
}