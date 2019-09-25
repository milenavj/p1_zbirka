#include <stdio.h>

/* Funkcija vraca zbir cifara datog broja x. */
int zbir_cifara(int x) {
  int zbir = 0;
  while (x) {
    zbir += x % 10;
    x /= 10;
  }
  return zbir;
}

/* Funkcija vraca 1 ako je broj srecan, a 0 u suprotnom. */
int srecan(int x) {
  /* Sve dok broj x ima vise od jedne cifre, vrednost broja x se
     zamenjuje zbirom njegovih cifara. 
     Na primer, pocetno x = 7698 nakon prve iteracije postaje
     x = 7+6+9+8 = 30, nakon druge iteracije postaje x = 3 + 0 = 3, a
     zatim se izlazi iz petlje. */
  while (x >= 10)
    x = zbir_cifara(x);

  /* Broj je srecan ako na kraju x ima vrednost 1. */
  return (x == 1);
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, i;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Ispis svih srecnih brojeva koji su manji ili jednaki n. */
  printf("Srecni brojevi: ");
  for (i = 1; i <= n; i++)
    if (srecan(i))
      printf("%d ", i);

  printf("\n");
  return 0;
}
