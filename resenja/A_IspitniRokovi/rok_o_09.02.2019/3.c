#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 21

/* Funkcija ispisuje odgovarajucu poruku na standardni izlaz za greske i prekida izvrsavanje programa. */
void greska() {
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

/* Funkcija koja proverava da li je niska s zapisana samo pomocu cifara. Povratna vrednost funkcije je 1 ako je uslov ispunjen, 
dok je u suprotnom 0. */
int sve_cifre(const char *s) {
  int i; 

  /* Provera da je pocetni karakter niske znak -. */
  if (s[0] == '-')
  {
    if (strlen(s) == 1)
      return 0;
    else
      s += 1;
  }

  /* Provera da li su karakteri niske cifre: cim se pronadje karakter koji nije cifra, izvrsavanje funkcije se prekida. */
  i = 0;
  while (s[i])
  {
    if (!isdigit(s[i]))
      return 0;

    i++;
  }

  return 1;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz = NULL;
  char s[MAX];

  /* Otvaranje datoteke za citanje i proverava uspesnosti otvaranja. */
  if ((ulaz = fopen("ulaz.txt", "r")) == NULL)
    greska();

  /* Citaju se niske datoteke sve do kraja ulaza. */
  while (fscanf(ulaz, "%s", s) != EOF)
    /* Ako se procitana niska sastoji samo od brojeva, ispisuje se na standardni izlaz. */
    if (sve_cifre(s))
      printf("%s ", s);

  putchar('\n');

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}
