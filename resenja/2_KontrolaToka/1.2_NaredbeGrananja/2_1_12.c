#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n;
  char jedinica, desetica, stotina, hiljada, najveca_cifra;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite cetvorocifreni broj: ");
  scanf("%d", &n);

  /* Da bi program radio ispravno i za negativne brojeve, koristi
    se apsolutna vrednost broja n. */
  n = abs(n);

  /* Provera ispravnosti ulaznih podataka. */
  if (n < 1000 || n > 9999) {
    printf("Greska: niste uneli cetvorocifreni broj.\n");
    return 1;
  }

  /* Izdvajanje cifara broja n. */
  jedinica = n % 10;
  desetica = (n / 10) % 10;
  stotina = (n / 100) % 10;
  hiljada = n / 1000;

  /* Racunanje najvece cifra broja n. */
  najveca_cifra = jedinica;

  if (desetica > najveca_cifra)
    najveca_cifra = desetica;

  if (stotina > najveca_cifra)
    najveca_cifra = stotina;

  if (hiljada > najveca_cifra)
    najveca_cifra = hiljada;

  /* Ispis rezultata. */
  printf("Najveca cifra je: %d\n", najveca_cifra);

  return 0;
}
