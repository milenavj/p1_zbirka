/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAKS_NISKA 21

/* Funkcija rotira nisku s duzine n za jedno mesto u levo. */
void rotiraj_za_1(char *s, int n) {
  int i;
  char c = s[0];

  for (i = 0; i < n - 1; i++)
    s[i] = s[i + 1];

  s[n - 1] = c;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  char s[MAKS_NISKA];
  int n, i;
  FILE *izlaz;

  /* Otvaranje datoteke rotacije.txt za pisanje i provera uspeha. */
  izlaz = fopen("rotacije.txt", "w");
  if (izlaz == NULL) {
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke.");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje reci koju je potrebno rotirati. */
  printf("Unesite rec: ");
  scanf("%s", s);

  /* Racunanje duzine reci. */
  n = strlen(s);

  /* U petlji se uneta rec rotira za 1 i upisuje u datoteku.
     Postupak se ponavlja n puta. */
  for (i = 0; i < n; i++) {
    fprintf(izlaz, "%s\n", s);
    rotiraj_za_1(s, n);
  }

  /* Zatvaranje datoteke. */
  fclose(izlaz);

  exit(EXIT_SUCCESS);
}
