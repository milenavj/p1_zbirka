#include <stdio.h>
#include <stdlib.h>

#define MAKS_NISKA 21

/* Funkcija poredi dve niske i vraca nulu ukoliko su jednake, neku
   pozitivnu vrednost ukoliko je niska s1 leksikografski iza s2, 
   a neku negativnu vrednost inace.

   Trazeni rezultat moze se dobiti koriscenjem funkcije strcmp cija 
   se deklaracija nalazi u zaglavlju string.h. Funkcija
   strcmp_klon predstavlja jednu mogucu implementaciju ove
   funkcije. */
int strcmp_klon(char s1[], char s2[]) {
  int i;

  /* Prolazi se kroz obe niske dok god se odgovarajuci karakteri
     poklapaju. Ako se u ovom prolasku desi da je petlja dosla do
     kraja obe niske, onda su one jednake i kao povratna vrednost
     funkcije se vraca 0. */
  for (i = 0; s1[i] == s2[i]; i++)
    if (s1[i] == '\0')
      return 0;

  /* Ako niske nisu jednake, znaci da je brojac i stao na prvom
     mestu gde se niske s1 i s2 razlikuju. Posto funkcija treba da
     vrati pozitivnu vrednost ako je niska s1 laksikografski iza
     s2, a negativnu u suprotnom, ovo moze biti realizovano
     vracanjem razlike ASCII kodova. Na primer: s1 = "pero", s2 =
     "program" Nakon petlje, brojac i ima vrednost 1 (jer je tu
     prva razlika). Kao povratna vrednost se vraca s1[1] - s2[1] =
     'e' - 'r' = -13 sto kao negativna vrednost govori da se s1
     nalazi leksikografski ispred s2. */
  return s1[i] - s2[i];
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  char s[MAKS_NISKA], t[MAKS_NISKA];
  int rezultat;

  /* Ucitavanje niski s i t. */
  printf("Unesite nisku s: ");
  scanf("%s", s);
  printf("Unesite nisku t: ");
  scanf("%s", t);

  /* Poredjenje niski i ispis rezultata. */
  rezultat = strcmp_klon(s, t);

  /* II nacin: Koriscenjem funkcije strcmp cija se deklaracija
     nalazi u zaglavlju string.g: rezultat = strcmp(s, t); */

  /* Ispis rezultata. */
  printf("Rezultat:\n");
  if (rezultat == 0)
    printf("%s\n", s);
  else if (rezultat < 0)
    printf("%s\n%s\n", s, t);
  else
    printf("%s\n%s\n", t, s);

  exit(EXIT_SUCCESS);
}
