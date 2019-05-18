#include <stdio.h>

int main() {
  /* Deklaracija potrebne promenljive. */
  int n;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Slucaj kada broj n ima vrednost nula se posebno obradjuje.
     Kada ovo ne bi bilo navedeno, petlja u nastavku bi se u ovom
     slucaju izvrsavala beskonacno. */
  if (n == 0) {
    printf("0\n");
    return 0;
  }

  /* Uklanjanje poslednje cifre broja se vrsi deljenjem broja sa 10.
     Ovaj postupak se ponavlja dok god je poslednja cifra nula. */
  while (n % 10 == 0)
    n = n / 10;

  /* Ispis rezultata. */
  printf("%d\n", n);

  return 0;
}
