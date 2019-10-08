/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Predprocesorska direktiva kojom se definise maksimalan broj
   elemenata niza. */
#define MAKS 100

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS];
  int n, i;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza:\n");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    /* Za izlazak iz programa moze da se koristi i funkcija exit.
       Argument EXIT_FAILURE oznacava da je doslo do neke greske
       pri izvrsavanju programa. Deklaracija ove funkcije se nalazi
       u zaglavlju stdlib.h. */
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  printf("Unesite elemente niza:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  /* Ispis elemenata niza na parnim pozicijama. */
  printf("Elementi niza na parnim pozicijama:\n");
  for (i = 0; i < n; i += 2)
    printf("%d ", a[i]);
  printf("\n");

  /* Ispis parnih elemenata niza. */
  printf("Parni elementi niza:\n");
  for (i = 0; i < n; i++)
    if (a[i] % 2 == 0)
      printf("%d ", a[i]);
  printf("\n");

  /* Kada se funkciji exit prosledi EXIT_SUCCESS to znaci da se
     program uspesno zavrsio. Efekat je isti navodjenju return 0;
     naredbe na ovom mestu. */
  exit(EXIT_SUCCESS);
}
