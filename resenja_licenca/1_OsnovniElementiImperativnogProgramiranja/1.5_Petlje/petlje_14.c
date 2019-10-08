/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int x, proizvod;

  /* Indikator koji oznacava da li je korisnik uneo bar jedan
     broj. */
  int unet_bar_jedan = 0;

  /* Indikator koji oznacava da li je korisnik uneo bar jedan
     pozitivan broj. */
  int unet_pozitivan = 0;

  /* Inicijalizacija proizvoda. */
  proizvod = 1;

  printf("Unesite brojeve:");
  /* Petlja ciji je uslov uvek ispunjen. */
  while (1) {
    /* Ucitavanje jednog broja. */
    scanf("%d", &x);

    /* Ako je uneta nula, petlja se prekida naredbom break. */
    if (x == 0)
      break;

    /* Ako petlja nije prekinuta, znaci da je unet bar jedan broj.
       Iz tog razloga se vrednost indikatora za unete brojeve
       postavlja na 1. */
    unet_bar_jedan = 1;

    /* Provera da li je broj x pozitivan. */
    if (x > 0) {
      /* Ako jeste, znaci da je unet bar jedan pozitivan broj i iz
         tog razloga se vrednost odgovarajuceg indikatora postavlja
         na 1. */
      unet_pozitivan = 1;

      /* Azuriranje vrednosti proizvoda pozitivnih brojeva. */
      proizvod = proizvod * x;
    }
  }

  /* Ispis rezultata. */
  if (unet_bar_jedan == 0)
    printf("Nije unet nijedan broj.\n");
  else if (unet_pozitivan == 0)
    printf("Medju unetim brojevima nema pozitivnih.\n");
  else
    printf("Proizvod pozitivnih brojeva je %d.\n", proizvod);

  return 0;
}
