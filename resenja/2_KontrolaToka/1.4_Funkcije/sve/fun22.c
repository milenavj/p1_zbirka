#include <stdio.h>
#include <math.h>

/* Funkcija ispisuje vrednosti funckije sin(x) u n ravnomeno 
   rasporedjenih tacaka na intervalu [a,b]. */
void ispis(float a, float b, int n)
{
  float i;
  float korak = (b - a) / (n - 1);

  for (i = a; i <= b; i += korak)
    printf("%.4f ", sin(i));

  printf("\n");
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float a, b;
  int n;
  
  /* Ucitavaju se granice intervala i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite dva realna broja:");
  scanf("%f%f", &a, &b);
  if(b >= a)
  {
    printf("Greska: neispravan unos.\n");
    return -1;
  }
  
  /* Ucitava se broj n i vrsi se provera ispravnosti ulaza. */
  printf("Unesite broj n:");
  scanf("%d", &n);
  if (n <= 1) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }
  
  /* Ispis rezultata. */
  ispis(a, b, n);

  return 0;
}