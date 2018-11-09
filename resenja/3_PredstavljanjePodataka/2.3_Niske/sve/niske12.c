#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_NISKA 21
#define MAKS_N 10
#define MAKS_REZULTAT (MAKS_NISKA*MAKS_N + 1)

int main()
{
  /* Deklaracija niski. */
  char s[MAKS_NISKA];
  char t[MAKS_REZULTAT];
  int i, n;

  /* Ucitava se niska. */
  printf("Unesite nisku: ");
  scanf("%s", s);
  
  /* Ucitava se broj ponavljanja i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if(n <= 0 || n > MAKS_N)
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Formira se rezultat. Prvi karakter rezultujuce niske se
     postavlja na terminalnu nulu. Ovo se radi jer strcat
     funkcionise tako sto krene od pocetka niske, ide do
     terminalne nule i zatim pocevsi od tog mesta nadovezuje
     nisku koja je prosledjena kao drugi argument. Na ovaj nacin
     je obezbedjeno da ce prvi poziv funkcije strcat krenuti da
     nadovezuje od pocetka niske t.
     U petlji se na t nadovezuje prvo niska s, a zatim niska "-".
     Ovo se ponavlja n-1 puta jer nakon poslednjeg nadovezivanja
     niske s ne treba da se nadje "-". Iz tog razloga se po 
     zavrsetku petlje vrsi jos jedno nadovezivanje niske s, ali ne
     i niske "-". */
  t[0] = '\0';
  for(i=0; i<n-1; i++) {
    strcat(t, s);
    strcat(t, "-");
  }
  strcat(t, s);
  
  /* Ispis rezultata. */
  printf("%s\n", t);

  exit(EXIT_SUCCESS);
}
