#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float a, b, c;
  float obim, s, povrsina;

  /* Ucitavaju se duzine stranica. */
  printf("Unesite duzine stranica trougla: ");
  scanf("%f%f%f", &a, &b, &c);

  /* Racuna se obim. */
  obim = a + b + c;

  /* Racuna se povrsina koriscenjem Heronovog obrasca. */
  s = obim / 2;
  povrsina = sqrt(s * (s - a) * (s - b) * (s - c));

  /* Ispis rezultata. */
  printf("Obim: %.2f\n", obim);
  printf("Povrsina: %.2f\n", povrsina);

  return 0;
}
