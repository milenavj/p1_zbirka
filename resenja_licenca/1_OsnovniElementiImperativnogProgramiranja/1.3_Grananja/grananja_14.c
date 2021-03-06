/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, n_abs, rezultat;
  char jedinica, desetica, stotina, hiljada;
  int najveca, najmanja, stepen_najvece, stepen_najmanje;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite cetvorocifreni broj: ");
  scanf("%d", &n);

  /* Da bi program radio ispravno i za negativne vrednosti, 
     koristi se apsolutna vrednost broja n. */
  n_abs = abs(n);

  /* Provera ispravnosti ulaznih podataka. */
  if (n_abs < 1000 || n_abs > 9999) {
    printf("Greska: niste uneli cetvorocifreni broj.\n");
    return 1;
  }

  /* Izdvajanje cifara broja n. */
  jedinica = n_abs % 10;
  desetica = (n_abs / 10) % 10;
  stotina = (n_abs / 100) % 10;
  hiljada = n_abs / 1000;

  /* Po algoritmu za trazenje najvece/najmanje cifre (koji je 
     prikazan u zadatku 2.1.11) pronalaze se najveca i najmanja
     cifra broja n, kao i pozicije na kojoj se one nalaze. 
     Radi lakseg izracunavanja, pozicija se pamti kao stepen broja
     10. Na primer, pozicija cifre jedinica je 1, cifre desetica 
     10, itd... */
  najveca = jedinica;
  stepen_najvece = 1;
  
  if (desetica > najveca) {
    najveca = desetica;
    stepen_najvece = 10;
  }

  if (stotina > najveca) {
    najveca = stotina;
    stepen_najvece = 100;
  }
  
  if (hiljada > najveca) {
    najveca = hiljada;
    stepen_najvece = 1000;
  }

  /* Racunanje najmanje cifre. */
  najmanja = jedinica;
  stepen_najmanje = 1;

  if (desetica < najmanja) {
    najmanja = desetica;
    stepen_najmanje = 10;
  }

  if (stotina < najmanja) {
    najmanja = stotina;
    stepen_najmanje = 100;
  }

  if (hiljada < najmanja) {
    najmanja = hiljada;
    stepen_najmanje = 1000;
  }

  /* Ideja: U broju 4179, najmanja cifra je 1 i njen stepen je 100,
     a najveca cifra je 9 i njen stepen je 1. Zamena mesta se vrsi
     tako sto se oduzme 9 i doda 1, a zatim oduzme 100 i doda 900. */
  rezultat = n_abs - najveca * stepen_najvece 
    + najmanja * stepen_najvece - najmanja * stepen_najmanje 
    + najveca * stepen_najmanje;
  
  /* Ako je pocetni broj bio negativan i rezultat treba da bude
     negativan. */
  if(n < 0)
    rezultat = -rezultat;
  
  /* Ispis rezultata. */
  printf("Rezultat: %d\n", rezultat);

  return 0;
}
