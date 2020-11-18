#include <stdio.h>
#include <stdlib.h>

typedef struct fraction{
    unsigned int numerator;
    unsigned int denominator;
} fraction;

void makeFractions(fraction*, char*, int*);
void multiplyFraction(fraction*, int);
void addFraction(fraction*);
void getCommonDenominator(fraction*, fraction*);
void shortenFraction(fraction*);
unsigned int gcd(fraction*);
void printFraction(fraction);

int main (void){
    fraction *fracs = malloc(sizeof(fraction) * 3);
    char operator;
    int scale;
    makeFractions(fracs, &operator, &scale);
    if (operator == '*') multiplyFraction(fracs, scale);
    else if (operator == '+') addFraction(fracs);
    shortenFraction((fracs + 0));
    printFraction(*(fracs + 0));
    
    free (fracs);

    return 0;
}

void makeFractions(fraction *fracs, char *op, int *scale){
    int i;
    char sORf;
    printf("Type '+' for addition and '*' for multiplication: ");
    scanf(" %c", op);
    if (*op == '+'){
        for (i = 1; i < 3; i++){
            printf("Numerator and denominator for fraction #%d: ", i);
            scanf(" %u%u", &(fracs + i)->numerator, &(fracs + i)->denominator);
        }
    }
    else if (*op == '*'){
        printf("Multiply by a scale, type s, multiply by another fraction, type f: ");
        scanf(" %c", &sORf);
        if (sORf == 's'){
            printf("Numerator and denominator for the fraction: ");
            scanf(" %u%u", &(fracs + 1)->numerator, &(fracs + 1)->denominator);
            printf("What is the scale? ");
            scanf(" %d", scale);
            (fracs + 2)->numerator = 1;
            (fracs + 2)->denominator = 1;
            
        }
        else if (sORf == 'f'){
            for (i = 1; i < 3; i++){
                printf("Numerator and denominator for fraction #%d: ", i);
                scanf(" %u%u", &(fracs + i)->numerator, &(fracs + i)->denominator);
            }
            *scale = -1;
        }
    }
    (fracs + 0)->numerator = 1;
    (fracs + 0)->denominator = 1;
}

void multiplyFraction(fraction *fracs, int scale){
    if (scale >= 0){
        (fracs + 0)->numerator = (fracs + 1)->numerator * scale;
        (fracs + 0)->denominator = (fracs + 1)->denominator * scale;
    }
    else{
        (fracs + 0)->numerator = (fracs + 1)->numerator * (fracs + 2)->numerator;
        (fracs + 0)->denominator = (fracs + 1)->denominator * (fracs + 2)->denominator;
    }
}

void addFraction(fraction *fracs){
    getCommonDenominator((fracs + 1), (fracs + 2));
    (fracs + 0)->numerator = (fracs + 1)->numerator + (fracs + 2)->numerator;
    (fracs + 0)->denominator = (fracs + 1)->denominator;
}

void getCommonDenominator(fraction *frac1, fraction *frac2){
    int commonDenominator = frac1->denominator * frac2->denominator;
    frac1->numerator *= frac2->denominator;
    frac2->numerator *= frac1->denominator;
    frac1->denominator = commonDenominator;
    frac2->denominator = commonDenominator;
}

void shortenFraction(fraction *frac){
    unsigned int decreaser = gcd(frac);
    
    frac->numerator /= decreaser;
    frac->denominator /= decreaser;
}

unsigned int gcd(fraction *frac){
    unsigned int remainder;
    unsigned int small = frac->numerator;
    unsigned int large = frac->denominator;
    
    while(small > 0){
        remainder = large % small;
        large = small;
        small = remainder;
    }
    
    return large;
}

void printFraction(fraction frac){
    printf("Resulting fraction: %u / %u\n", frac.numerator, frac.denominator);
}
