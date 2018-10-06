#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float a, povrsina, obim;

  /* Ucitava se duzina stranice. */
  printf("Unesite duzinu stranice trougla: ");
  scanf("%f", &a);

  /* Racunaju se obim i povrsina. */
  obim = 3 * a;
  povrsina = (a * a * sqrt(3)) / 4;

  /* Ispis rezultata na dve decimale. */
  printf("Obim: %.2f\n", obim);
  printf("Povrsina: %.2f\n", povrsina);

  return 0;
}
