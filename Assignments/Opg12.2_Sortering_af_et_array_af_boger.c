#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOKS 10
#define TITLE_MAX 50
#define AUTHOR_MAX 40
#define PUBLISHER_MAX 20

typedef struct book {
  char title[TITLE_MAX], author[AUTHOR_MAX], publisher[PUBLISHER_MAX];
  int publishing_year;
  int university_text_book;
} book;

book make_book(char *title, char *author, char *publisher, int year, int text_book);
void prnt_book(book b);

void sort_books(book*, int);
void sort_books_by_title(book*, int);
void sort_books_by_type(book*, int);
int cmpfuncTi(const void*, const void*);
int cmpfuncTy(const void*, const void*);

int main(void){
  book shelf[MAX_BOOKS];
  int i;

  shelf[0] =
    make_book("Problem Solving and Program Design in C", "Hanly and Koffman", 
              "Pearson", 2010, 1);   

  shelf[1] =
    make_book("C by Disssection", "Kelley and Pohl", 
              "Addison Wesley", 2001, 1);   

  shelf[2] =
    make_book("The C Programming Language", "Kernighan og Ritchie", 
              "Prentice Hall", 1988, 1);   

  shelf[3] =
    make_book("Pelle Erobreren", "Martin Andersen Nexoe",
              "Gyldendal", 1910, 0);

  shelf[4] = shelf[3];
  strcpy(shelf[4].title, "Ditte Menneskebarn");
  shelf[4].publishing_year = 1917;

  for(i = 0; i <=4; i++)
    prnt_book(shelf[i]);
  
  sort_books(shelf, 5);
  
  return 0;
}

void sort_books(book *shelf, int size){
    sort_books_by_title(shelf, size);
    sort_books_by_type(shelf, size);
}

void sort_books_by_title(book *shelf, int size){
    int i;
    qsort(shelf, size, sizeof(book), cmpfuncTi);
    printf("Now it is sorted\n");
    for(i = 0; i < size; i++) prnt_book(*(shelf + i));
}

void sort_books_by_type(book *shelf, int size){
    int i;
    qsort(shelf, size, sizeof(book), cmpfuncTy);
    qsort(shelf + 3, size - 3, sizeof(book), cmpfuncTi);
    qsort(shelf + 2, size - 2, sizeof(book), cmpfuncTi);
    printf("Now it is sorted\n");
    for(i = 0; i < size; i++) prnt_book(*(shelf + i));
}

int cmpfuncTi(const void *a, const void *b){
    book *A = (book *)a;
    book *B = (book *)b;
    return strcmp(A->title, B->title);
}

int cmpfuncTy(const void *a, const void *b){
    book *A = (book *)a;
    book *B = (book *)b;
    return A->university_text_book - B->university_text_book;
}

book make_book(char *title, char *author, char *publisher, 
               int year, int text_book){
  book result;
  strcpy(result.title, title); strcpy(result.author, author); strcpy(result.publisher, publisher); 
  result.publishing_year = year;
  result.university_text_book = text_book;
 
  return result;
}

void prnt_book(book b){
  char *yes_or_no;

  yes_or_no = (b.university_text_book ? "yes" : "no"); 
  printf("Title: %s\n"
         "Author: %s\n"
         "Publisher: %s\n"
         "Year: %4i\n"
         "University text book: %s\n\n",
         b.title, b.author, b.publisher, 
         b.publishing_year, yes_or_no);
}
