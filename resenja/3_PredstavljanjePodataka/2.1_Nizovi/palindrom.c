#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS 200

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  char niz[MAKS], blanko;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite trenutni broj klijenata: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Nakon unosa dimenzije, korisnik unosi blanko ili znak za novi
     red. Ovaj karakter je potrebno ucitati pre unosa elemenata
     niza, inace ce ovaj karakter biti prvi element niza, sto nije
     zeljeno ponasanje. */
  scanf("%c", &blanko);

  printf("Unesite elemete niza: ");
  for (i = 0; i < n; i++)
    scanf("%c", &niz[i]);

  /* Provera da li je niz palindrom. Uporedjuju se prvi i
     poslednji, drugi i pretposlednji... odnosno i-ti i
     ((n-1)-i)-ti element niza. Ako nisu jednaki, niz nije
     palindrom. Kako se istovremeno posmatraju dva elementa niza
     dovoljno je da brojac u petlji ide do polovine dimenzije niza. */
  for (i = 0; i < n / 2; i++){
    /* Kako se zanemaruje velicina slova, svaki element niza se
       pretvara u malo slovo i potom se vrsi poredjenje. */
    if (tolower(niz[i]) != tolower(niz[n - 1 - i])) {
      printf("Niz nije palindrom.\n");
      /* Ukoliko niz nije palindrom, ispitivanje se moze prekinuti
         i izaci iz programa, dalje ispitivanje nije potrebno. */
      exit(EXIT_SUCCESS);
    }
  }

  /* U sluacju kada je petlja zavrsena, a nije izaslo iz programa,
     niz jeste palindrom jer uslov nikada nije bio ispunjen. */
  printf("Niz jeste palindrom.\n");

  exit(EXIT_SUCCESS);
}
