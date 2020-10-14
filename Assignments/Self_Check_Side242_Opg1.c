#include <stdio.h>

int main(){
	char color = 'R';
	switch (color) { /* break statements missing */
		case 'R':
			printf("red\n");
		case 'B':
			printf("blue\n");
		case 'Y':
			printf("yellow\n");
	}
}