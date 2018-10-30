#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija koja vraca broj pojavljivanja broja x u nizu. */
int broj_pojavljivanja(int niz[], int n, int x)
{
  int i;
  int brojac_pojavljivanja = 0;

  for (i = 0; i < n; i++) {
    if (niz[i] == x) {
      brojac_pojavljivanja++;
    }
  }

  return brojac_pojavljivanja;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS], rezultujuci_niz[MAKS];
  int i, n, j, duzina_rezultujuceg_niza;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if (n < 1 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza a: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  /* Parametar j je brojac elemenata rezultujuceg niza. */
  j = 0;

  /* Obilazi se element po element niza a. */
  for (i = 0; i < n; i++) {
    /* Ukoliko se tekuci element pojavljuje vise od dva puta u nizu 
       a i nije upisan u rezultujuci niz koji trenutno ima j
       elemenata, dodaje se u rezultujuci niz na poziciju j i 
       uvecava se broj elemenata rezultujuceg niza. */
    if (broj_pojavljivanja(a, n, a[i]) >= 3
        && broj_pojavljivanja(rezultujuci_niz, j, a[i]) == 0) {
      rezultujuci_niz[j] = a[i];
      j++;
    }
  }

  /* Ispis rezultata. */
  duzina_rezultujuceg_niza = j;
  for (i = 0; i < duzina_rezultujuceg_niza; i++)
    printf("%d ", rezultujuci_niz[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
