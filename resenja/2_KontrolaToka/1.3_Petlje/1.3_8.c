#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, i;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* I nacin: Za svaki broj iz intervala [2, n-1] se proverava da
     li deli broj n (tj. da li je ostatak pri deljenju sa n jednak
     nuli). Ako je uslov ispunjen, taj broj se ispisuje. 
     for (i = 2; i < n; i++) 
       if (n % i == 0) 
         printf("%d ", i); 
       
     printf("\n"); */

  /* II nacin (brzi): Provera se ne vrsi za sve brojeve iz
     intervala [2, n-1], vec za brojeve iz intervala [2, sqrt(n)],
     tj. za sve brojeve k za koje vazi da je k*k <= n. */
  for (i = 2; i * i <= n; i++) {
    /* Ako i deli n, treba razlikovati dva slucaja. */
    if (n % i == 0) {
      if (i == n / i) {
        /* I slucaj: kada je i koren broja, npr. 4 za 16, ispisuje
           se samo broj i. */
        printf("%d ", i);
      } else {
        /* II slucaj: u suprotnom, ispisuje se taj broj i broj n / 
           i, npr. 2 za 16, ispisuju se i 2 i 8. */
        printf("%d %d ", i, n / i);
      }
    }
  }
  printf("\n");

  return 0;
}
