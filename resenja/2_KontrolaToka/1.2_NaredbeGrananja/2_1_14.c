#include <stdio.h>
#include <stdlib.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n;
  char jedinica, desetica, stotina, hiljada;
  int broj_parnih, proizvod_parnih;

  /* Ucitava se vrednost broja n. */
  printf("Unesite cetvorocifreni broj: ");
  scanf("%d", &n);

  /* Da bi program radio ispravno i za negativne vrednosti, uzima
     se apsolutna vrednost broja n. */
  n = abs(n);

  /* Vrsi se provera ispravnosti ulaznih podataka. */
  if (n < 1000 || n > 9999) {
    printf("Greska: niste uneli cetvorocifreni broj.\n");
    return -1;
  }

  /* Izdvajaju se cifre broja n. */
  jedinica = n % 10;
  desetica = (n / 10) % 10;
  stotina = (n / 100) % 10;
  hiljada = n / 1000;

  /* Inicijalizacija brojaca i rezultata. */
  broj_parnih = 0;
  proizvod_parnih = 1;

  /* Za svaku cifru se vrsi provera da li je parna i ukoliko jeste
     tekuci rezultat se mnozi sa tekucom cifrom. */
  if (jedinica % 2 == 0) {
    proizvod_parnih = proizvod_parnih * jedinica;
    broj_parnih++;
  }

  if (desetica % 2 == 0) {
    proizvod_parnih = proizvod_parnih * desetica;
    broj_parnih++;
  }

  if (stotina % 2 == 0) {
    proizvod_parnih = proizvod_parnih * stotina;
    broj_parnih++;
  }

  if (hiljada % 2 == 0) {
    proizvod_parnih = proizvod_parnih * hiljada;
    broj_parnih++;
  }

  /* Ispis rezultata. */
  if (broj_parnih == 0) {
    printf("Nema parnih cifara.\n");
  } else {
    printf("Proizvod parnih cifara: %d\n", proizvod_parnih);
  }

  return 0;
}
