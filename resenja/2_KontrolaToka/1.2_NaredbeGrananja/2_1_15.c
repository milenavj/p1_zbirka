#include <stdio.h>
#include <stdlib.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, n_abs;
  char jedinica, desetica, stotina, hiljada;
  int najveca, najmanja, stepen_najvece, stepen_najmanje;
  int rezultat;

  /* Ucitava se broj vrednost broja n. */
  printf("Unesite cetvorocifreni broj: ");
  scanf("%d", &n);

  /* Da bi program radio ispravno i za negativne vrednosti, uzima
     se apsolutna vrednost broja n. */
  n_abs = abs(n);

  /* Vrsi se provera ispravnosti ulaznih podataka. */
  if (n_abs < 1000 || n_abs > 9999) {
    printf("Greska: niste uneli cetvorocifreni broj.\n");
    return -1;
  }

  /* Izdvajaju se cifre broja n. */
  jedinica = n_abs % 10;
  desetica = (n_abs / 10) % 10;
  stotina = (n_abs / 100) % 10;
  hiljada = n_abs / 1000;

  /* Racunaju se najveca i najmanja cifra, kao i pozicija na kojoj
     se one nalaze. Radi lakseg izracunavanja, pozicija se pamti
     kao stepen broja 10. Na primer, pozicija cifre jedinica je 1,
     cifre desetica 10, itd... */
  najveca = jedinica;
  najmanja = jedinica;
  stepen_najvece = 1;
  stepen_najmanje = 1;

  if (desetica > najveca) {
    najveca = desetica;
    stepen_najvece = 10;
  }
  if (desetica < najmanja) {
    najmanja = desetica;
    stepen_najmanje = 10;
  }

  if (stotina > najveca) {
    najveca = stotina;
    stepen_najvece = 100;
  }
  if (stotina < najmanja) {
    najmanja = stotina;
    stepen_najmanje = 100;
  }

  if (hiljada > najveca) {
    najveca = hiljada;
    stepen_najvece = 1000;
  }
  if (hiljada < najmanja) {
    najmanja = hiljada;
    stepen_najmanje = 1000;
  }

  /* Ideja: U broju 4179, najmanja cifra je 1 i njen stepen je 100,
     a najveca cifra je 0 i njen stepen je 1. Zamena mesta se vrsi
     tako sto se oduzme 9 i doda 1, a zatim oduzme 100 i doda 900. */
  if (n > 0){
    rezultat = n - najveca * stepen_najvece 
                 + najmanja * stepen_najvece 
                 - najmanja * stepen_najmanje 
                 + najveca * stepen_najmanje;
  }
  else {
    rezultat = n + najveca * stepen_najvece 
                 - najmanja * stepen_najvece 
                 + najmanja * stepen_najmanje 
                 - najveca * stepen_najmanje;
  }
  
  /* Ispis rezultata. */
  printf("Rezultat: %d\n", rezultat);

  return 0;
}
