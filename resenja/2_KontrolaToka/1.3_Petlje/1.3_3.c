#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int i, n;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n < 0) {
    printf("Greska: pogresan unos broja n.\n");
    return -1;
  }

  /* Inicijalizacija brojaca. */
  i = 0;
  
  /* Posto je potrebno ispisati sve brojeve [0,n], telo petlje
     se izvrsava za svako i <= n. */
  while (i <= n) {
    
    /* Ispisuje se trenutna vrednost brojaca. */
    printf("%d\n", i);
    
    /* Prelazi se na sledeci broj.  */
    i++;
  }

  return 0;
}
