#include <stdio.h>
#include <stdlib.h>

#define MAKS_NISKA 21

/* Funkcija vraca adresu prvog pojavljivanja karaktera c u niski s
   ili NULL ukoliko se c ne pojavljuje u s.

   Trazeni rezultat se moze dobiti koriscenjem funkcije strchr cija 
   se deklaracija nalazi u zaglavlju string.h. Funkcija
   strchr_klon predstavlja jednu mogucu implementaciju ove
   funkcije. */
char *strchr_klon(char s[], char c) {
  int i;

  /* Za svaki karakter se proverava da li je jednak karakteru c.
     Ako se naidje na takav karakter, kao povratna vrednost
     funkcije se vraca njegova adresa (&s[i]). */
  for (i = 0; s[i]; i++)
    if (s[i] == c)
      return &s[i];

  /* Ako je petlja zavrsena, znaci da nije pronadjen karakter koji
     je jednak karakteru c pa se kao povratna vrednost funkcije
     vraca NULL pokazivac. */
  return NULL;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  char s[MAKS_NISKA];
  char c;

  /* Ucitavanje niske s. */
  printf("Unesite nisku s: ");
  scanf("%s", s);

  /* Preskace se novi red koji je unet nakon niske s i ucitava se
     karakter c. */
  getchar();
  printf("Unesite karakter c: ");
  scanf("%c", &c);

  /* Racunanje i ispis rezultata. */
  char *p = strchr_klon(s, c);
  if (p == NULL)
    printf("Pozicija: -1\n");
  else
    printf("Pozicija: %ld\n", p - s);

  exit(EXIT_SUCCESS);
}
