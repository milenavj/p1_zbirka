#include<stdio.h>
#include<math.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int x, i;

  /* Ucitava se vrednost broja x. */
  printf("Unesite broj x: ");
  scanf("%d", &x);

  /* Vrsi se provera ispravnosti ulaza. */
  if (x <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* I nacin: Za svaki broj iz intervala [2, x-1] se proverava da 
     li deli broj x (tj. da li je ostatak pri deljenju sa x jednak
     nuli). Ako je uslov ispunjen, taj broj se ispisuje. 
    for (i = 2; i < x; i++) {
      if (x % i == 0)
        printf("%d ", i);
    }
    printf("\n");
    */
  
  /* II nacin (brzi): Provera se ne vrsi za sve brojeve iz
     intervala [2, x-1], vec se petlja izvrsava dok se ne
     stigne do korena broja. */
  for (i = 2; i <= sqrt(x); i++) {
    /* Ako i deli x, treba razlikovati dva slucaja. */
    if (x % i == 0){
      if (i == x / i) {
        /* I slucaj: kada je i koren broja, npr. 4 za 16,
         ispisuje se samo broj i. */
        printf("%d ", i);
      }
      else {
        /* II slucaj: u suprotnom, ispisuje se taj broj i 
           broj x / i, npr. 2 za 16, ispisuju se i 2 i 8. */
        printf("%d %d ", i, x / i);
      }
    }
  }
  printf("\n");

  return 0;
}
