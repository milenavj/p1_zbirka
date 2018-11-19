#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_NISKA 21

/* Funkcija rotira nisku za jedno mesto ulevo. */
void rotiraj1(char s[], int n)
{
  int i;
  /* Pamti se prvi karakter. */
  char prvi = s[0];
  
  /* Svaki sledeci karakter se pomera za jedno mesto ulevo. */
  for(i=0; i<n-1; i++)
    s[i] = s[i+1];
  
  /* Prvi karakter se upisuje na kraj niske. */
  s[n-1] = prvi;
}

/* Funkcija rotira nisku s za k mesta ulevo. */
void rotiraj(char s[], int k){
  int i;
  int n = strlen(s);
  
  for(i=0; i<k; i++)
    rotiraj1(s, n);
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  char s[MAKS_NISKA];
  int k;
  
  /* Ucitavaju se niska i vrednost k. */
  printf("Unesite nisku: ");
  scanf("%s", s);
  printf("Unesite k: ");
  scanf("%d", &k);
  
  /* Vrsi se provera ispravnosti ulaza. */
  if(k < 0)
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Racunanje i ispis rezultata. */
  rotiraj(s, k);
  printf("%s\n", s);  
  
  exit(EXIT_SUCCESS);
}