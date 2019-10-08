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
  int n;
  char jedinica, desetica, stotina;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite pozitivan trocifreni broj: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaznih podataka. */
  if (n < 100 || n > 999) {
    printf("Greska: niste uneli pozitivan trocifreni broj.\n");
    return 1;
  }

  /* Izdvajanje cifara broja n. */
  jedinica = n % 10;
  desetica = (n / 10) % 10;
  stotina = n / 100;

  /* Ispis rezultata. */
  if (n == jedinica * jedinica * jedinica +
      desetica * desetica * desetica + stotina * stotina * stotina)
    printf("Broj je Armstrongov.\n");
  else
    printf("Broj nije Armstrongov.\n");

  return 0;
}
