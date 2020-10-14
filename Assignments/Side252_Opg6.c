#include <stdio.h>

int main(){
	int x, y;
	printf("What is the coordinates of the coordinate? Not seperated by a \",\" or in parenteties ");
	scanf("%d%d", &x, &y);
	if (x == 0 && y == 0) printf("The coordinate (%d,%d) is on the origin\n", x, y);
	else if (x == 0) printf("The coordinate (%d,%d) is on the y-axis\n", x, y);
	else if (y == 0) printf("The coordinate (%d,%d) is on the x-axis\n", x, y);
	else if (x > 0 && y > 0) printf("The coordinate (%d,%d) is in the first quadrant\n", x, y);
	else if (x > 0 && y < 0) printf("The coordinate (%d,%d) is in the fourth quadrant\n", x, y);
	else if (x < 0 && y > 0) printf("The coordinate (%d,%d) is in the second quadrant\n", x, y);
	else if (x < 0 && y < 0) printf("The coordinate (%d,%d) is in the third quadrant\n", x, y);
	return 0;
}