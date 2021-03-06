/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

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
    return 1;
  }

  printf("Pravi delioci:\n");
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
        /* I slucaj: Kada je i koren broja, ispisuje se samo broj i,
           npr. za n = 16, i = 4, ispisuje se samo 4. */
        printf("%d ", i);
      } else {
        /* II slucaj: Kada i nije koren broja, ispisuje se i broj  
           i i broj n/i, npr. za n = 16, i = 2 ispisuju se i 2 i 8.
           */
        printf("%d %d ", i, n / i);
      }
    }
  }
  printf("\n");

  return 0;
}
