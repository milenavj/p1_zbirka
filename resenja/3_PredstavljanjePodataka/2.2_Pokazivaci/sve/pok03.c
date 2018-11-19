#include <stdio.h>
#include <stdlib.h>

/* Funkcija koja racuna presek pravih y = k1 * x + n1 i 
   y = k2 * x + n2. Koordinate preseka (ako postoji) se upisuju
   na adrese px i py. Kao povratna vrednost funkcije se vraca
   jedinica ukoliko presek postoji, a nula inace. */
int presek(float k1, float n1, float k2, float n2, float *px,
           float *py)
{
  /* Ako je koeficijent pravca jednak, prave su paralelne. 
     Povratna vrednost funkcije je 0, kao indikator da 
     nema presecne tacke. */
  if (k1 == k2)
    return 0;

  /* Koordinate preseka se upisuju na adrese (px, py). */
  *px = -(n1 - n2) / (k1 - k2);
  *py = k1 * (*px) + n1;
  
  /* Funkcija vraca 1 kao indikator da je presek uspesno
     izracunat. */
  return 1;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  float k1, k2, n1, n2;
  float x, y;

  /* Ucitavaju se parametri za dve prave. */
  printf("Unesite k i n za prvu pravu:");
  scanf("%f%f", &k1, &n1);
  printf("Unesite k i n za drugu pravu:");
  scanf("%f%f", &k2, &n2);

  /* Ispis rezultata. */
  if (presek(k1, n1, k2, n2, &x, &y))
    printf("Prave se seku u tacki (%.2f,%.2f).\n", x, y);
  else
    printf("Prave su paralelne.\n");

  exit(EXIT_SUCCESS);
}