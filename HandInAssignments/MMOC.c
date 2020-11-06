#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void getInfo(char*, char*, char*, char*);

int main(int argc, char **argv)
{
	char warehouse[50];
	char id[50];
	char qaulifiers[50];
	char* productCode = *(argv + 1);

	getInfo(productCode, warehouse, id, qaulifiers);

	printf("productCode: %s\nWarehouse: %s\nid: %s\nQaulifiers: %s\n", productCode, warehouse, id, qaulifiers);

	return 0;
}

void getInfo(char *productCode, char *warehouse, char *id, char *qaulifiers){
	int i, j;
	int lenghtProductCode = strlen(productCode);
	int lenght[3] = {0, 0, 0};
	for (i = 0; i < 3; i++){
		if (i == 0){
			for (j = 0; isalpha(productCode[j]); j++){
				lenght[i]++;
			}
		}
		else if (i == 1){
			for (j = lenght[0]; isdigit(productCode[j]); j++){
				lenght[i]++;
			}
		}
		else lenght[i] = lenghtProductCode - lenght[0] - lenght[1];
	}

	strncpy(warehouse, productCode, lenght[0]);
	strncpy(id, (productCode + lenght[0]), lenght[1]);
	strncpy(qaulifiers, (productCode + lenght[0] + lenght[1]), lenght[2] + 1);
}