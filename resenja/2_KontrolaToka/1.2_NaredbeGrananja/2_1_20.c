#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float a, b, c;
  float D;

  /* Ucitavaju se koeficijenti kvadratne jednacine. */
  printf("Unesite koeficijente A, B i C:");
  scanf("%f%f%f", &a, &b, &c);

  /* Racunaju se resenja jednacine u zavisnosti od vrednosti
     koeficijenata a, b i c i ispisuje se odgovarajuci rezultat. */
  if (a == 0) {
    if (b == 0) {
      if (c == 0) {
        /* Slucaj a==0 && b==0 && c==0: beskonacno mnogo resenja. */
        printf("Jednacina ima beskonacno mnogo resenja\n");
      } else {
        /* Slucaj a==0 && b==0 && c!=0: nema resenja. */
        printf("Jednacina nema resenja\n");
      }
    } else {
      /* Slucaj a=0 && b!=0: jedinstveno resenje. */
      printf("Jednacina ima jedinstveno realno resenje %.2f\n",
             -c / b);
    }
  } else {
    /* Slucaj a != 0: racuna se diskriminanta. */
    D = b * b - 4 * a * c;

    /* U zavisnosti od vrednosti diskriminante, ispisuje se
       rezultat. */
    if (D < 0) {
      printf("Jednacina nema realnih resenja\n");
    } else if (D > 0) {
      printf("Jednacina ima dva realna resenja %.2f i %.2f\n",
             (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a));
    } else {
      printf("Jednacina ima jedinstveno realno resenje %.2f\n",
             -b / (2 * a));
    }
  }

  return 0;
}
