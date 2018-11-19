#include <stdio.h>
#include <stdlib.h>

/* Predprocesorska direktiva kojom se definise maksimalan broj
   elemenata niza. */
#define MAKS 100

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS];
  int n, i;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite dimenziju niza:\n");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    /* Za izlazak iz programa moze da se koristi i funkcija exit.
       Argument EXIT_FAILURE oznacava da je doslo do neke greske
       pri izvrsavanju programa. Deklaracija ove funkcije se nalazi
       u zaglavlju stdlib.h. */    
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  /* Ispisuju se elementi niza na parnim pozicijama. */
  printf("Elementi niza na parnim pozicijama:\n");
  for (i = 0; i < n; i += 2)
    printf("%d ", a[i]);
  printf("\n");

  /* Ispisuju se parni elementi niza. */
  printf("Parni elementi niza:\n");
  for (i = 0; i < n; i++)
    if (a[i] % 2 == 0)
      printf("%d ", a[i]);
  printf("\n");
  
  /* Kada se funkciji exit prosledi EXIT_SUCCESS to znaci da se 
     program uspesno zavrsio. Efekat je isti kao i da je navedeno
     return 0; na ovom mestu. */
  exit(EXIT_SUCCESS);
}
