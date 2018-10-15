#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float x1, y1, x2, y2, x3, y3;
  float k, n;

  /* Ucitavaju se koordinate tacaka A, B i C. */
  printf("Unesite koordinate tacke A: ");
  scanf("%f%f", &x1, &y1);

  printf("Unesite koordinate tacke B: ");
  scanf("%f%f", &x2, &y2);

  printf("Unesite koordinate tacke C: ");
  scanf("%f%f", &x3, &y3);

  /* Ako su bilo koje dve tacke jednake, onda se sigurno sve tri
     nalaze na jednoj pravoj. */
  if ((x1 == x2 && y1 == y2) ||
      (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3)) {
    printf("DA\n");
    return 0;
  }

  /* Odredjuju se koeficijent pravca k i odsecak na y osi n, prave
     y = k*x + n koja prolazi kroz tacke A i B. Napomena: u
     slucaju kada je x2 jednako x1, ova prava je paralelna sa y
     osom i k ima vrednost beskonacno, a n ima vrednost 0, tj.
     jednacina prave je x = x1 (sto je isto sto i x = x2). Da bi se 
     izbeglo deljenje nulom (x2-x1), ovaj slucaj se posebno
     obradjuje. */
  if (x2 != x1) {
    k = (y2 - y1) / (x2 - x1);
    n = y1 - k * x1;
    /* Proverava se da li tacka C pripada pravoj y=k*x + n na
       kojoj se vec nalaze tacke A i B. */
    if (y3 == k * x3 + n) {
      printf("DA\n");
    } else {
      printf("NE\n");
    }
  } else {
    /* Proverava se da li se i tacka C nalazi na pravoj x = x2. */
    if (x3 == x2) {
      printf("DA\n");
    } else {
      printf("NE\n");
    }
  }


  /* II nacin: 3 tacke su kolinearne ako je: 
     |x1 y1 1 | 
     |x2 y2 1 | = 0 
     |x3 y3 1 | 
     odnosno, ako je: 
     x1*y2 + y1*x3 + x2*y3 - y1*x2 - x1*y3 - y2*x3 = 0

     if(x1*y2 + y1*x3 + x2*y3 - y1*x2 - x1*y3 - y2*x3 == 0)
       printf("DA\n"); 
     else 
       printf("NE\n"); */

  return 0;
}
