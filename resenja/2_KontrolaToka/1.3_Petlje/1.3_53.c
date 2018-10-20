#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitava se vrednost broja n i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj n: ");
  scanf("%u", &n);
  
  if (n % 2 == 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Iscrtava se znak plus tako sto se na pozicijama koje
     odgovaraju sredisnjoj vrsti i sredisnjoj kolini ispisuje
     +, a na ostalim pozicijama se ispisuje blanko. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      if (i == n / 2 || j == n / 2)
        printf("+");
      else
        printf(" ");
    printf("\n");
  }

  return 0;
}
