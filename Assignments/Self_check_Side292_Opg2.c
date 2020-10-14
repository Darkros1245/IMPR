#include <stdio.h>

int main(){
	int i, j, k;
	for (i = 0; i < 3; ++i)
	{
		printf("Outer%4d\n", i);
		for (j = 0; j < 2; ++j)
		{
			printf(" Inner%3d%3d\n", i, j);
		}
		for (k = 2; k > 0; --k)
		{
			printf(" Inner%3d%3d\n", i, k);		
		}
	}
	return 0;
}