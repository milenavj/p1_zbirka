#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_NISKA 21

void kopiraj_n(char t[], char s[], int n)
{
  int i;
  /* Kopiranje se vrsi ili dok se ne dodje do terminalne nule u s
     ili dok se ne prekopira n karaktera. */
  for (i = 0; i < n && s[i] != '\0'; i++) {
    t[i] = s[i];
  }

  /* Na kraju rezultujuce niske se upisuje terminalna nula. */
  t[i] = '\0';
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int n;
  char s[MAKS_NISKA], t[MAKS_NISKA];

  /* Ucitava se niska. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Ucitava se broj n i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if (n < 0 || n > MAKS_NISKA-1) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Formira se rezultat. */
  kopiraj_n(t, s, n);

  /* II nacin:
     Koriscenjem funkcije strncpy(t, s, n), cija se deklaracija
     nalazi u zaglavlju string.h, kopira najvise n karaktera niske
     s u nisku t. 
     
     strncpy(t,s,n);
     */
  
  /* Ispis rezultata. */
  printf("%s\n", t);

  exit(EXIT_SUCCESS);
}
