#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void getInfo(char*, char**, char**, char**);

int main(int argc, char **argv)
{
	/*Declaration of pointers, and initializing them to NULL*/
	char *warehouse = NULL;
	char *id = NULL;
	char *qaulifiers = NULL;
  	
	/*Declaring and initializing productcode pointer to the productcode argument given at cli*/
	char *productCode = *(argv + 1);

	/*Checking if an product code was given*/
	if (argc != 2){
		printf("MMOC.c only accepts 1 input parameter, ex. ./a.out \"product code\"\n");
		return 0;
	}

	/*Calling getInfo, with alle the pointers as parameters*/
	getInfo(productCode, &warehouse, &id, &qaulifiers);

	/*Printing the splited productcode*/
	printf("productCode: %s\nWarehouse: %s\nid: %s\nQaulifiers: %s\n", productCode, warehouse, id, qaulifiers);

	/*Program terminator*/
	return 0;
}

/*Function to spilt the productcode into the warehouse, id and qaulifier*/
void getInfo(char *productCode, char **warehouse, char **id, char **qaulifiers){
	int i, j;
	/*Getting the lenght of the string/char-array productCode*/
	int lenghtProductCode = strlen(productCode);
	int lenght[3] = {0, 0, 0};
	/*Lopping 3 times, to determine the lenght of the 3 different parts of productCode*/
	for (i = 0; i < 3; i++){
		/*Since warehouse only consists of letters, and is the first part, I'll count the lenght first*/
		if (i == 0){
			for (j = 0; isalpha(productCode[j]); j++){
				lenght[i]++;
			}
		}
		/*Secondly the id only consists nummbers, so I'll count that from where the letters ended, aka, the warehouse signature*/
		else if (i == 1){
			for (j = lenght[0]; isdigit(productCode[j]); j++){
				lenght[i]++;
			}
		}
		/*Lastly, the qaulifiers, since that is the last part, I can just calculate the lengt of that*/
		else lenght[i] = lenghtProductCode - lenght[0] - lenght[1];
	}

	/*Now that the lenght of the 3 different parts of the productCode is known, I can allocate the needed memory to store them*/
	*warehouse = malloc(sizeof(char) * lenght[0]);
	*id = malloc(sizeof(char) * lenght[1]);
	*qaulifiers = malloc(sizeof(char) * lenght[2]);

	/*Then I copy the part of productCode, into each of its parts, determined by its length, and placement in productCode*/
	strncpy(*warehouse, productCode, lenght[0]);
	strncpy(*id, (productCode + lenght[0]), lenght[1]);
	strncpy(*qaulifiers, (productCode + lenght[0] + lenght[1]), lenght[2]);
}