#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int n, i, j;
  char c, novi_red;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Ucitavanje karaktera koji ce se koristiti za iscrtavanje.
     Napomena: voditi racuna da treba preskociti novi red koji
     korisnik zadaje nakon unosa broja n. */
  printf("Unesite karakter c: ");
  scanf("%c%c", &novi_red, &c);

  /* Iscrtavanje trazenog trougla. Iscrtavaju se samo ivice
     trougla, ostalo se popunjava belinama. */
  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++)
      if (i == n - 1 || j == 0 || j == i)
        printf("%c", c);
      else
        printf(" ");
    printf("\n");
  }

  return 0;
}
