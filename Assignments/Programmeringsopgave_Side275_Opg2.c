#include <stdio.h>
#define CI 0.3937

int main(){
	int i;
	for (i = 0; i < 10; ++i)
	{
		printf("%d cm equals %f inches\n", i * 10, CI * i * 10);
	}
	return 0;
}