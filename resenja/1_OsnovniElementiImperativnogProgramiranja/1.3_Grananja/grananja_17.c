#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  float xa, ya, xb, yb, xc, yc;
  float k, n;

  /* Ucitavanje koordinata tacaka A, B i C. */
  printf("Unesite koordinate tacke A: ");
  scanf("%f%f", &xa, &ya);

  printf("Unesite koordinate tacke B: ");
  scanf("%f%f", &xb, &yb);

  printf("Unesite koordinate tacke C: ");
  scanf("%f%f", &xc, &yc);

  /* Ako su bilo koje dve tacke jednake, onda se sigurno sve tri
     nalaze na jednoj pravoj. */
  if ((xa == xb && ya == yb) ||
      (xa == xc && ya == yc) || (xb == xc && yb == yc)) {
    printf("Tacke se nalaze na istoj pravoj.\n");
    return 0;
  }

  /* Odredjivanje koeficijenta pravca k i odsecka na y osi n prave
     y = k*x + n koja prolazi kroz tacke A i B. Napomena: U
     slucaju kada je xb jednako xa, ova prava je paralelna sa y
     osom pa k ima vrednost beskonacno, a n vrednost 0, tj.
     jednacina prave je x = xa (sto je isto sto i x = xb). Da bi se 
     izbeglo deljenje nulom (xb-xa), ovaj slucaj se posebno
     obradjuje. */
  if (xb != xa) {
    k = (yb - ya) / (xb - xa);
    n = ya - k * xa;
    /* Provera da li tacka C pripada pravoj y=k*x + n na
       kojoj se vec nalaze tacke A i B. */
    if (yc == k * xc + n)
      printf("Tacke se nalaze na istoj pravoj.\n");
    else
      printf("Tacke se ne nalaze na istoj pravoj.\n");
  } else {
    /* Provera da li se i tacka C nalazi na pravoj x = xb. */
    if (xc == xb)
      printf("Tacke se nalaze na istoj pravoj.\n");
    else
      printf("Tacke se ne nalaze na istoj pravoj.\n");
  }

  /* II nacin: Tacke su kolinearne ako je  
     |xa ya 1 | 
     |xb yb 1 | = 0 
     |xc yc 1 | 
     odnosno, ako je 
     xa*yb + ya*xc + xb*yc - ya*xb - xa*yc - yb*xc = 0

     if(xa*yb + ya*xc + xb*yc - ya*xb - xa*yc - yb*xc == 0)
       printf("Tacke se nalaze na istoj pravoj. \n"); 
     else 
       printf("Tacke se ne nalaze na istoj pravoj. \n"); */

  return 0;
}
