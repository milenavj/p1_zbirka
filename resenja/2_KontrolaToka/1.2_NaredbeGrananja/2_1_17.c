#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float x1, y1, x2, y2;

  /* Ucitavaju se koordinate tacaka A i B. */
  printf("Unesite koordinate tacke A: ");
  scanf("%f%f", &x1, &y1);

  printf("Unesite koordinate tacke B: ");
  scanf("%f%f", &x2, &y2);

  /* Proverava se da li su obe tacke u istom kvadrantu. */
  if ((x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0) ||
      (x1 <= 0 && y1 >= 0 && x2 <= 0 && y2 >= 0) ||
      (x1 >= 0 && y1 <= 0 && x2 >= 0 && y2 <= 0) ||
      (x1 <= 0 && y1 <= 0 && x2 <= 0 && y2 <= 0)) {
    printf("DA\n");
  } else {
    printf("NE\n");
  }

  return 0;
}
