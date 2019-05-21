#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n;
  char jedinica, desetica, stotina, hiljada;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite cetvorocifreni broj: ");
  scanf("%d", &n);

  /* Da bi program radio ispravno i za negativne vrednosti, uzima
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

  /* Ispis rezultata. */
  if (hiljada <= stotina && stotina <= desetica
      && desetica <= jedinica)
    printf("Cifre su uredjene neopadajuce. \n");
  else if (hiljada >= stotina && stotina >= desetica
           && desetica >= jedinica)
    printf("Cifre su uredjene nerastuce. \n");
  else
    printf("Cifre nisu uredjene.\n");

  return 0;
}
