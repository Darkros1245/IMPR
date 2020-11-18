#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum suits{clubs, diamonds, hearts, spades, snon} suits;
typedef enum values{two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, aes, vnon} values;

typedef struct card{
	suits suit;
	values value;
	int isJoker;
} card;

void makeCards(card*, int);
void shuffleCards(card*, int, int);
void swapTwoCards(card*, int, int);
void printCards(card*, int);
void sortCards(card*, int);
int sortCardsBySuit(const void*, const void*);
int sortCardsNumerically(const void*, const void*);

int main(void){
	int deckLenght = 55;
	int amountOfShuffeling = deckLenght * deckLenght;
	card *cards = malloc(sizeof(card) * 55);
	srand(time(NULL));

	makeCards(cards, deckLenght);
	shuffleCards(cards, deckLenght, amountOfShuffeling);
	printf("\n\nSHUFFLED CARDS!!!\n\n");
	printCards(cards, deckLenght);

	sortCards(cards, deckLenght);
	printf("\n\nSORTED CARDS!!!\n\n");
	printCards(cards, deckLenght);

	free(cards);
	return 0;
}

void makeCards(card *cards, int deckLenght){
	int i;
	int currentSuit = clubs;
	for (i = 0; i < deckLenght; ++i){
		if (i % 14 != 13){
			(cards + i)->suit = currentSuit;
			(cards + i)->value = i % 14;
			(cards + i)->isJoker = 0;
		}
		else{
			(cards + i)->suit = snon;
			(cards + i)->value = vnon;
			(cards + i)->isJoker = 1;
			currentSuit++;
		}
	}
}

void shuffleCards(card *cards, int deckLenght, int amountOfShuffeling){
	int i;
	for (i = 0; i < amountOfShuffeling; ++i){
		swapTwoCards(cards, rand() % deckLenght, rand() % deckLenght);
	}

}

void swapTwoCards(card *cards, int pos1, int pos2){
	card tempCard = *(cards + pos1);
	*(cards + pos1) = *(cards + pos2);
	*(cards + pos2) = tempCard;
}

void printCards(card *cards, int deckLenght){
	int i;
	char* suit = "";
	char* value = "";
	int isJoker;
	for (i = 0; i < deckLenght; i++){
		isJoker = !((cards + i)->isJoker);
		if (isJoker){
			switch ((cards + i)->suit){
				case 0:
					suit = "clubs";
					break;
				case 1:
					suit = "diamonds";
					break;
				case 2:
					suit = "hearts";
					break;
				case 3:
					suit = "spades";
					break;
				default:
					break;
			}
			switch ((cards + i)->value){
				case 0:
					value = "two";
					break;
				case 1:
					value = "three";
					break;
				case 2:
					value = "four";
					break;
				case 3:
					value = "five";
					break;
				case 4:
					value = "six";
					break;
				case 5:
					value = "seven";
					break;
				case 6:
					value = "eight";
					break;
				case 7:
					value = "nine";
					break;
				case 8:
					value = "ten";
					break;
				case 9:
					value = "jack";
					break;
				case 10:
					value = "queen";
					break;
				case 11:
					value = "king";
					break;
				case 12:
					value = "aes";
					break;
				default:
					break;
			}
			printf("Card %d has suit %s and value %s\n", i, suit, value);
		}
		else{
			printf("Card %d is a joker\n", i);
		}
	}
}

void sortCards(card *cards, int deckLenght){
	int i;
	int amountOfSuits = 4;
	int suitLenght = 13;
	qsort(cards, deckLenght, sizeof(card), sortCardsBySuit);
	for (i = 0; i < amountOfSuits; i++)
	{
		qsort(cards + (i * suitLenght), suitLenght, sizeof(card), sortCardsNumerically);
	}
}

int sortCardsBySuit(const void *a, const void *b){
	card *A = (card*) a;
	card *B = (card*) b;
	return(A->suit - B->suit);
}

int sortCardsNumerically(const void *a, const void *b){
	card *A = (card*) a;
	card *B = (card*) b;
	return(A->value - B->value);
}