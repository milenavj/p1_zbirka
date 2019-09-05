#include <stdio.h>
#include <stdlib.h>

/* Funkcija ispisuje odgovarajucu poruku na standardni izlaz za
   greske i prekida izvrsavanje programa. */
void greska() {
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n;
  char cifra_jedinica, cifra_desetica, cifra_stotina, cifra_hiljada;
  float aritmeticka_sredina;
  char suma_cifara;

  /* Ucitavanje i provera ispravnosti ulaza. */
  scanf("%d", &n);
  if (n < 1000 || n > 9999) {
    greska();
  }

  /* Izdvajanje cifara unetog broja. */
  cifra_jedinica = n % 10;
  cifra_desetica = (n / 10) % 10;
  cifra_stotina = (n / 100) % 10;
  cifra_hiljada = n / 1000;

  /* Izracunavanje aritmeticke sredine cifara. */
  aritmeticka_sredina =
      (cifra_hiljada + cifra_desetica + cifra_jedinica +
       cifra_stotina) / 4.0;

  /* Izracunavanje sume onih cifara koje su vece od aritmeticke
     sredine. */
  suma_cifara = 0;

  if (cifra_jedinica > aritmeticka_sredina)
    suma_cifara += cifra_jedinica;

  if (cifra_desetica > aritmeticka_sredina)
    suma_cifara += cifra_desetica;

  if (cifra_stotina > aritmeticka_sredina)
    suma_cifara += cifra_stotina;

  if (cifra_hiljada > aritmeticka_sredina)
    suma_cifara += cifra_hiljada;

  /* Ispis rezultata. */
  printf("%d\n", suma_cifara);

  exit(EXIT_SUCCESS);
}
