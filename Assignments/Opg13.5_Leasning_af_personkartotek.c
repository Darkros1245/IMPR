#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LGT 50
typedef struct person{
	char fornavn[MAX_NAME_LGT];
	char efternavn[MAX_NAME_LGT];
	char vejnavn[MAX_NAME_LGT];
	int vejnummer;
	int postnummer;
	char bynavn[MAX_NAME_LGT];
} person;

void makePersonData(person*, FILE*, int, int*);
void sortPersons(person*, int);
int cmpByLastName(const void*, const void*);

int main(){
	person *persons;
	int lines = 0;
	int *lenghtOfLines;
	char c;
	int i;
	FILE *doc = fopen("adresser.txt", "r");
	
	do{
		c = fgetc(doc);
		if (c == '\n') lines++;
	} while (c != EOF);
	fseek(doc, 0, SEEK_SET);

	lenghtOfLines = malloc(sizeof(int) * lines);
	persons = malloc(sizeof(person) * lines);

	for (i = 0; i < lines; ++i){
		do{
			c = fgetc(doc);
			if (c != '\n') (*(lenghtOfLines + i))++;
		} while (c != EOF && c != '\n');
	}

	fseek(doc, 0, SEEK_SET);

	makePersonData(persons, doc, lines, lenghtOfLines);
	sortPersons(persons, lines);

	for (i = 0; i < lines; i++){
		printf("%s: %s\n", (persons + i)->bynavn, (persons + i)->efternavn);
	}

	fclose(doc);
	free(persons);
	free(lenghtOfLines);
	return 0;	
}

void makePersonData(person *persons, FILE *doc, int lines, int *lenghtOfLines){
	int i, j, k;
	char c;
	int *lenghtOfWords = calloc(6, sizeof(int));
	char *streetNumber, *zipCode;
	for (i = 0; i < lines; i++){
		/*fseek(doc, *(lenghtOfLines + i) * -1, SEEK_CUR);*/

		for (j = 0; j < 6; j++){
			if (j == 3 || j == 4){
				do{
					c = fgetc(doc);
					if (isdigit(c)) (*(lenghtOfWords + j))++;
				} while (isdigit(c) || (*(lenghtOfWords + j)) == 0);
			}

			else if (j == 2) {
				do{
					c = fgetc(doc);
					if (isalpha(c) || c == ' ') (*(lenghtOfWords + j))++;
					else {
						(*(lenghtOfWords + j)) -= 2;
						fseek(doc, -1, SEEK_CUR);
					}
				} while (isalpha(c) || (*(lenghtOfWords + j)) == 0 || c == ' ');
			}
			else do{
				c = fgetc(doc);
				if (isalpha(c)) (*(lenghtOfWords + j))++;
			} while (isalpha(c) || (*(lenghtOfWords + j)) == 0);
		}

		streetNumber = malloc(sizeof(char) * (*(lenghtOfWords + 3)));
		zipCode = malloc(sizeof(char) * (*(lenghtOfWords + 4)));

		fseek(doc, *(lenghtOfLines + i) * -1, SEEK_CUR);

		for (j = 0; j < 6; j++){
			switch (j){
				case 0:
					for (k = 0; k < *(lenghtOfWords + j); k++){
						do{
							c = fgetc(doc);
						} while (!isalpha(c));
						(persons + i)->fornavn[k] = c;
					}
					break;
				case 1:
					for (k = 0; k < *(lenghtOfWords + j); k++){
						do{
							c = fgetc(doc);
						} while (!isalpha(c));
						(persons + i)->efternavn[k] = c;
					}
					break;
				case 2:
					fseek(doc, 2, SEEK_CUR);
					for (k = 0; k < *(lenghtOfWords + j); k++){
						do{
							c = fgetc(doc);
							if (c == ' '){
								(persons + i)->vejnavn[k] = c;
								k++;
							}
						} while (!isalpha(c));
						(persons + i)->vejnavn[k] = c;
					}
					break;
				case 3:
					for (k = 0; k < *(lenghtOfWords + j); k++){
						do{
							c = fgetc(doc);
						} while (!isdigit(c));
						streetNumber[k] = c;
					}
					(persons + i)->vejnummer = atoi(streetNumber);
					break;
				case 4:
					for (k = 0; k < *(lenghtOfWords + j); k++){
						do{
							c = fgetc(doc);
						} while (!isdigit(c));
						zipCode[k] = c;
					}
					(persons + i)->postnummer = atoi(zipCode);;
					break;
				case 5:
					for (k = 0; k < *(lenghtOfWords + j); k++){
						do{
							c = fgetc(doc);
						} while (!isalpha(c));
						(persons + i)->bynavn[k] = c;
					}
					break;
			}
		}
		for (j = 0; j < 6; j++) (*(lenghtOfWords + j)) = 0;
		free(streetNumber);
		free(zipCode);
	}
	free(lenghtOfWords);
}

void sortPersons(person *persons, int lenght){
	qsort(persons, lenght, sizeof(person), cmpByLastName);
}

int cmpByLastName(const void *a, const void *b){
	person *A = (person *)a;
	person *B = (person *)b;

	return (strcmp(A->efternavn, B->efternavn));
}