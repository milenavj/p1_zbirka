#include <stdio.h>
#include <stdlib.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  int x, x_kopija, broj_cifara;
  int najveci_broj_cifara, rezultat;

  /* Ucitava se vrednost broja n i vrsi se provera ispravnosti. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  if (n == 0) {
    printf("Nisu uneseni brojevi.\n");
    return 0;
  }

  /* Maksimalan broj cifara se postavlja na 0 jer svaki broj ima
     vise od 0 cifara. */
  najveci_broj_cifara = 0;

  printf("Unesite n brojeva: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &x);

    /* Racuna se broj cifara unetog broja x. */
    x_kopija = abs(x);
    broj_cifara = 0;
    do {
      broj_cifara++;
      x_kopija = x_kopija / 10;
    } while (x_kopija != 0);

    /* Ako je broj cifara unetog broja veci od najveceg broja
       cifara, azuriraju se vrednosti najveceg broja cifara i
       tekuceg rezultata. */
    if (broj_cifara > najveci_broj_cifara) {
      najveci_broj_cifara = broj_cifara;
      rezultat = x;
    }
  }

  /* Ispis rezultata. */
  printf("Najvise cifara ima broj %d.\n", rezultat);

  return 0;
}
