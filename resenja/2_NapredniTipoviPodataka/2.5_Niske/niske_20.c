#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAKS_RECENICA 81

/* Funkcija ucitava recenicu maksimalne duzine n. */
int ucitaj_recenicu(char s[], int n) {
  int i = 0, c;

  /* Preskacu se beline sa pocetka ako ih ima. Po zavrsetku ove
     petlje u c se nalazi prvi sledeci karakter koji nije belina. */
  do {
    c = getchar();
  } while (isspace(c));

  /* Ako je taj karakter EOF, zavrsava se ucitavanje. */
  if (c == EOF)
    return 0;

  /* U nisku se smesta karakter, prelazi se na sledeci karakter i
     postupak se ponavlja sve dok se ne unese tacka, EOF ili dok se 
     ne popuni maksimalan broj karaktera koje recenica moze da
     sadrzi. */
  do {
    s[i] = c;
    i++;
    c = getchar();
  } while (c != '.' && i < n - 2 && c != EOF);

  /* Ako je poslednji uneti karakter EOF, zavrsava se ucitavanje. */
  if (c == EOF)
    return 0;

  /* Na kraju svake recenice stoji tacka za kojom sledi '\0'. */
  s[i] = '.';
  s[i + 1] = '\0';

  return i + 1;
}

/* Funkcija prebrojava mala i velika slova. */
void prebroj(char s[], int *broj_malih, int *broj_velikih) {
  int i, mala = 0, velika = 0;

  for (i = 0; s[i]; i++) {
    if (islower(s[i]))
      mala++;
    else if (isupper(s[i]))
      velika++;
  }

  *broj_malih = mala;
  *broj_velikih = velika;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  char recenica[MAKS_RECENICA];
  char rezultujuca_recenica[MAKS_RECENICA];
  int najveca_razlika = -1, trenutna_razlika;
  int mala, velika;
  int ucitana_bar_jedna = 0;

  /* U petlji se ucitavaju recenice sve dok se ne unese EOF. */
  while (ucitaj_recenicu(recenica, MAKS_RECENICA) > 0) {
    /* Prebrojavanje malih i velikih slova. */
    prebroj(recenica, &mala, &velika);

    /* Racunanje njihove apsolutne razlike. */
    trenutna_razlika = abs(mala - velika);

    /* Ako je razlika veca od trenutno najvece, azurira se vrednost
       najvece razlike i pamti se trenutna recenica. */
    if (trenutna_razlika > najveca_razlika) {
      najveca_razlika = trenutna_razlika;
      strcpy(rezultujuca_recenica, recenica);
    }

    /* Indikator koji oznacava da se petlja bar jednom izvrsila,
       tj. da korisnik nije odmah zadao EOF. */
    ucitana_bar_jedna = 1;
  }

  /* Ispis rezultata. */
  if (ucitana_bar_jedna)
    printf("Rezultujuca recenica:\n%s\n", rezultujuca_recenica);
  else
    printf("Nije uneta nijedna recenica. ");

  exit(EXIT_SUCCESS);
}
