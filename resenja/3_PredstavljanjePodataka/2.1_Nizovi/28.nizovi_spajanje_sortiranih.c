#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija koja ucitava dimenziju i elemente nizova.
   Kao povratnu vrednost vraca ucitanu dimenziju. */
int ucitaj(int niz1[], int niz2[])
{
  int i, n;
  
  /* Ucitava se dimenzija niza i vrsi se provera 
     ispravnosti ulaza. */
  printf("Unesite dimenziju nizova: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Ucitavaju se elementi prvog niza. */
  printf("Unesite elemente sortiranog niza:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &niz1[i]);
  
  /* Ucitavaju se elementi drugog niza. */
  printf("Unesite elemente sortiranog niza:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &niz2[i]);
  
  return n;
}

/* Funkcija za ispis niza. */
void ispisi(int niz[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS], b[MAKS], c[2 * MAKS];
  int n;
  /* Brojac u petlji za elemente niza a. */
  int i = 0;
  /* Brojac u petlji za elemente niza b. */
  int j = 0;
  /* Brojac u petlji za elemente niza c. */
  int k = 0;

  /* Ucitavaju se dimenzija i elementi nizova. */
  n = ucitaj(a, b);

  /* Vrsi se spajanje nizova. */
  while (i < n && j < n) 
  {
    /* Porede se elementi nizova a i b i u niz c upisuje se samo
       onaj koji je manji. Ako je upisan element iz niza a, onda se
       vrsi i uvecavanje brojaca i (prelazak na sledeci element
       niza a), a ako je upisan element iz niza b, onda se vrsi
       uvecavanje brojaca j (prelazak na sledeci element niza b). */
    if (a[i] < b[j]) 
    {
      c[k] = a[i];
      i++;
    } 
    else 
    {
      c[k] = b[j];
      j++;
    }

    /* U nizu c na poziciju k je upisan ili a[i] ili b[j]. Brojac k 
       se uvecava. */
    k++;
  }

  /* Ukoliko je ostalo elemenata u nizu a, upisuju se u niz c. */
  while (i < n) 
  {
    c[k] = a[i];
    k++;
    i++;
  }

  /* Ukoliko je ostalo elemenata u nizu b, upisuju se u niz c. */
  while (j < n) 
  {
    c[k] = b[j];
    k++;
    j++;
  }

  /* Ispis elemenata niza c cija dimenzija je zbir dimenzija nizova 
     a i b. */
  ispisi(c, 2 * n);

  exit(EXIT_SUCCESS);
}
