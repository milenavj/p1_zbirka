#include <stdio.h>
#include <stdlib.h>

/* Predprocesorska direktiva kojom se definise maksimalni broj
   elemenata niza. */
#define MAKS 100

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int b[MAKS];
  int n, i, skalarni_proizvod;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite dimenziju vektora: ");
  scanf("%d", &n);
  if (n < 1 || n > 100) {
    printf("Greska: neispravan unos.\n");
    /* Za izlazak iz programa moze da se koristi i funkcija exit.
       Argument EXIT_FAILURE oznacava da je doslo do neke greske
       pri izvrsavanju programa. */
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se koordinate vektora. */
  printf("Unesite koordinate vektora a: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  printf("Unesite koordinate vektora b: ");
  for (i = 0; i < n; i++)
    scanf("%d", &b[i]);

  /* Izracunava se skalarni proizvod po zadatoj formuli. */
  skalarni_proizvod = 0;
  for (i = 0; i < n; i++)
    skalarni_proizvod = skalarni_proizvod + a[i] * b[i];

  /* Ispis rezultata. */
  printf("Skalarni proizvod vektora a i b: %d\n",
         skalarni_proizvod);

  /* Kada se funkciji exit prosledi EXIT_SUCCESS to znaci da se 
     program uspesno zavrsio. Efekat je isti kao i da je navedeno
     return 0; na ovom mestu. */
  exit(EXIT_SUCCESS);
}
