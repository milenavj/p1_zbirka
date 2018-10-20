#include <stdio.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  int suma_kubova;

  /* Ucitava se vrednost broja n i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj n:");
  scanf("%d", &n);
  
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Racuna se suma kubova svih brojeva iz intervala [1,n]
     i u svakoj iteraciji se ispisuje njena vrednost. */
  suma_kubova = 0;
  for (i = 1; i <= n; i++){
    suma_kubova += i * i * i;
    printf("k=%d, suma=%d", i, suma_kubova);
  }

  return 0;
}
