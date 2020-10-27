#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Decleration of functions*/
void trap(double, double, int, char);
double fg(double);
double fh(double);

int main(){
    /*Declaration and initilitation of array, to store n*/
    int n[7] = {2, 4, 8, 16, 32, 64, 128};
    int i;
    double hc = (2 * 2 * 3.14159) / 2;

    /*Calling the function trap() ones for each n for both function*/
    for (i = 0; i < 7; i++) trap(0, 3.14159, n[i], 'g');    
    printf("\n");
    for (i = 0; i < 7; i++) trap(-2, 2, n[i], 'h');
    printf("\n");

    /*Comparing the aproximation of the area under the function h(x), to an actual half cirkel, since that is what it represents*/
    printf("Actual area of a half cirkel with a raius of 2 is: %f\n", hc);
    printf("Comparison: The approximation of the area under h(x) for n = 128, is very close to the actual area of the half cirkel\n");

    /*Program terminator*/
    return 0;
}

void trap(double a, double b, int n, char f){
    int i;
    /*Calculating h*/
    double h = (b - a) / n;
    double area = 0;
    /*Since array would not be an option, since n is not a constant, i have just allocated some memory, equal to the the size of an double in bytes times n
    and stored it to a pointer, so we can dynamiclly chagnes x and y for every call to this function depending on n*/
    double *x = malloc(sizeof(double) * n);
    double *y = malloc(sizeof(double) * n);
    
    /*Calculating each x accordingly to n, we can store it to x, like it was an array, since that is the same as derefrencing it like *(x + i)*/
    for (i = 0; i < n; i++) x[i] = a + i * h;
    /*If the function there needs to be called is g, we callculate each g(x), and then we calculate the area and prints it*/
    if (f == 'g'){
        for (i = 0; i < n; i++) y[i] = fg(x[i]); 
        for (i = 0; i < n - 1; i++) area += (((y[i] + y[i + 1])) / 2) * h;
        printf("The area under the curve %c(x) = x * x * sin(x) from %f to %f is %f for n = %d\n", f, a, b, area, n);
    }
    /*If the function there needs to be called is h, we callculate each h(x), and then we calculate the area and prints it*/
    else if (f == 'h'){
        for (i = 0; i < n; i++) y[i] = fh(x[i]);
        for (i = 0; i < n - 1; i++) area += (((y[i] + y[i + 1])) / 2) * h;
        printf("The area under the curve %c(x) = sqrt(4 - x * x) from %f to %f is %f for n = %d\n", f, a, b, area, n);
    }
    
    /*Here I free up the space occupied by x and y*/
    free(x);
    free(y);
}

/*Implementation of the function g(x), which returns a double*/
double fg(double x){
    return pow(x, 2) * sin(x);
}

/*Implementation of the function h(x), which returns a double*/
double fh(double x){
    return sqrt(4 - pow(x, 2));
}
