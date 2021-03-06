#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAKS_LINIJA 81
#define MAKS_NISKA 21

/* Funkcija prebrojava koliko linija datoteke ulaz se zavrsava
   niskom s. */
int broj_linija(FILE *ulaz, char *s) {
  char linija[MAKS_LINIJA];
  int brojac = 0, duzina_linije;
  int duzina_s = strlen(s);

  /* Citanje linija iz datoteke sve do kraja datoteke. */
  while (fgets(linija, MAKS_LINIJA, ulaz) != NULL) {
    /* Racunanje duzine procitane linije. */
    duzina_linije = strlen(linija);

    /* Uklanjanje znaka za novi red sa kraja linije. */
    if (linija[duzina_linije - 1] == '\n') {
      linija[duzina_linije - 1] = '\0';
      duzina_linije--;
    }

    /* Poredjenje kraja linije sa niskom s. Kraj linije se moze
       dobiti tako sto se izvrsi 'pomeranje' u desno do kraja
       linije, a zatim 'pomeranje' u levo onoliko mesta koliko je
       dugacka niska s. 
       Na primer, ako je linija "abcdefghijk", a niska s "ab", 
       onda se sa linija + duzina_linije vrsi pomeranje na karakter 
       iza karaktera 'k' (odnosno null-terminator), a sa 
       linija + duzina_linije - duzina_s 
       na karakter 'j'. Ukoliko se funkcija strcmp pozove sa 
       strcmp(linija + duzina_linije - duzina_s, s), 
       vrsice se poredjenje niske "jk" i "ab", sto je i bio cilj. */
    if (strcmp(linija + duzina_linije - duzina_s, s) == 0)
      brojac++;
  }

  return brojac;
}


int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz;
  char s[MAKS_NISKA];

  /* Otvaranje datoteke ulaz.txt za citanje i provera uspeha. */   
  ulaz = fopen("ulaz.txt", "r");
  if (ulaz == NULL) {
    fprintf(stderr, "Greska: neuspesno otvaranje ulazne "
            "datoteke.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje niske s. */
  printf("Unesite nisku s: ");
  scanf("%s", s);

  /* Ispis rezultata. */
  printf("Broj linija: %d\n", broj_linija(ulaz, s));

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}