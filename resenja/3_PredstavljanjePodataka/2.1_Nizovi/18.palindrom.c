#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS 200

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(char niz[], int n)
{
  int i;
  /* Ucitava se niz od n karaktera. */
  printf("Unesite elemete niza: ");
  for (i = 0; i < n; i++)
    scanf("%c", &niz[i]);
}

/* Funkcija proverava da li je niz karaktera palindrom. */
int je_palindrom(char niz[], int n)
{
  int i;
  /* U petlji se porede niz[0] i niz[n-1], zatim niz[1] i niz[n-2]
     itd. Ako se naidje na par koji se razlikuje - niz nije 
     palindrom. */
  for (i = 0; i < n / 2; i++)
  {
    if (tolower(niz[i]) != tolower(niz[n - 1 - i]))
      return 0;
  }
  
  /* Izvrsila se cela petlja => niz je palindrom. */
  return 1;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  char niz[MAKS];
  int n;
  
  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Preskace se novi red nakon unosa dimenzije. Ovo se radi
     jer sledi ucitavanje karaktera i bez ove linije, prvi
     karakter koji bi se upisao u niz bi bio novi red. */
  getchar();

  /* Ucitavaju se elementi niza. */
  ucitaj(niz, n);

  /* Ispis rezultata. */
  if(je_palindrom(niz, n))
    printf("Niz jeste palindrom.\n");
  else
    printf("Niz nije palindrom.\n");
  
  exit(EXIT_SUCCESS);
}
