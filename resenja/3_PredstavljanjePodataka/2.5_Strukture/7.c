#include <stdio.h>
#include <stdlib.h>

#define MAKS_DECE 200

typedef struct {
  char pol;
  int broj_godina;
  int ocena;
} Dete;

/* Funkcija ucitava podatke o deci i proverava ispravnost unetih
   podataka. */
void ucitaj(Dete niz[], int n) {
  char blanko;
  int i;
  printf("Unesite podatke za svako dete, pol, broj godina i "
         "ocenu:\n");
  for (i = 0; i < n; i++) {
    scanf("%c%c%d%d", &blanko, &niz[i].pol, &niz[i].broj_godina,
          &niz[i].ocena);

    /* Provera ispravnosti unosa. */
    if (niz[i].pol != 'm' && niz[i].pol != 'z') {
      printf("Greska: neispravan pol.\n");
      exit(EXIT_FAILURE);
    }
    if (niz[i].broj_godina > 6 || niz[i].broj_godina < 3) {
      printf("Greska: neispravan broj godina.\n");
      exit(EXIT_FAILURE);
    }
    if (niz[i].ocena < 1 || niz[i].ocena > 5) {
      printf("Greska: neispravna ocena.\n");
      exit(EXIT_FAILURE);
    }
  }
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, i, broj_godina;
  Dete niz[MAKS_DECE];
  char blanko, pol;
  int suma, broj_dece;

  /* Ucitavanje broja dece i provera ispravnosti ulaza. */
  printf("Unesite broj dece: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS_DECE) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje podataka o deci. */
  ucitaj(niz, n);

  /* Ucitavanje trazenih podataka. */
  printf("Unesite pol i broj godina: ");
  scanf("%c%c%d", &blanko, &pol, &broj_godina);

  /* Ispitivanje ispravnosti unetih podataka. */
  if (pol != 'm' && pol != 'z') {
    printf("Greska: neispravan pol.\n");
    exit(EXIT_FAILURE);
  }
  if (broj_godina > 6 || broj_godina < 3) {
    printf("Greska: neispravan broj godina.\n");
    exit(EXIT_FAILURE);
  }

  /* Racunanje prosecna ocena dece ciji se pol i broj godina
     poklapaju sa unetim. */
  suma = 0;
  broj_dece = 0;
  for (i = 0; i < n; i++)
    if (niz[i].pol == pol && niz[i].broj_godina == broj_godina) {
      suma += niz[i].ocena;
      broj_dece++;
    }

  /* Ispis rezultata. */
  if (broj_dece == 0)
    printf("Ne postoje deca sa takvim karakteristikama.\n");
  else
    printf("Prosecna ocena je: %.3lf.\n",
           (double) suma / broj_dece);

  return 0;
}
