#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, suma, pom_n;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Pravi se kopija originalnog broja, da bi originalna vrednost
     n ostala nepromenjena. */
  pom_n = n;

  /*Inicijalizacija sume cifara. */
  suma = 0;
  
  /* Racuna se suma cifara. */
  while (pom_n != 0) {
    /* Na sumu se dodaje poslednja cifra broja. */
    suma += pom_n % 10;
    /* Sa broja se skida poslednja cifra. */
    pom_n /= 10;
  }

  /* Ispis rezultata. */
  if (n % suma == 0)
    printf("Broj %d je deljiv sa %d.\n", n, suma);
  else
    printf("Broj %d nije deljiv sa %d.\n", n, suma);

  return 0;
}
