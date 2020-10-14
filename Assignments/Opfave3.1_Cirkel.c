#include <stdio.h>
#include <math.h>

int main(){
	double r, x, y, l;
	printf("What is the radius of the cirkel? ");
	scanf("%lf", &r);
	printf("What is the coordinates of the coordinate? Not including a \",\" or in parenthesis: ");
	scanf("%lf %lf", &x, &y);
	l = sqrt(pow(x, 2) + pow(y, 2));
	if (l > r) printf("The coordinate (%f, %f) is outside of the cirkel\n", x, y);
	else if (l == r) printf("The coordinate (%f, %f) is on the cirkel\n", x, y);
	else printf("The coordinate (%f, %f) is in the cirkel\n", x, y);
	return 0;
}