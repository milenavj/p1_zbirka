#include <stdio.h>
#include <stdlib.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n;
  char jedinica, desetica, stotina, hiljada, najveca_cifra;

  /* Ucitava se vrednost broja n. */
  printf("Unesite cetvorocifreni broj: ");
  scanf("%d", &n);

  /* Da bi program radio ispravno i za negativne brojeve, uzima se
     apsolutna vrednost broja n. */
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

  /* Racuna se najveca cifra broja n. */
  najveca_cifra = jedinica;

  if (desetica > najveca_cifra)
    najveca_cifra = desetica;

  if (stotina > najveca_cifra)
    najveca_cifra = stotina;

  if (hiljada > najveca_cifra)
    najveca_cifra = hiljada;


  /* Ispis rezultata */
  printf("Najveca cifra je: %d\n", najveca_cifra);

  return 0;
}
