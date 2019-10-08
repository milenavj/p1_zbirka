/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int x, najmanja, najveca;

  printf("Unesite brojeve: ");
  /* Prvi broj se ucitava izvan petlje zbog inicijalizacije najvece 
     i najmanje vrednosti nadmorske visine. Napomena: Ovde bi
     inicijalizacija najveca=-1 bila pogresna jer moze da se desi
     da su svi uneti brojevi negativni i manji od -1 i onda bi
     najveca i nakon izvrsavanja tela petlje ostala -1. */
  scanf("%d", &x);
  najveca = x;
  najmanja = x;

  /* Ako nema unetih nadmorskih visina, ispisuje se odgovarajuca
     poruka. */
  if (x == 0) {
    printf("Nisu unete nadmorske visine.");
    return 0;
  }

  /* Za svaki ucitani broj se proverava da li je manji od najmanje
     ili veci od najvecee i vrsi se azuriranje odgovarajucih
     vrednosti. Petlja se prekida kada se unese broj 0. */
  while (1) {
    scanf("%d", &x);

    if (x == 0)
      break;

    if (x > najveca)
      najveca = x;

    if (x < najmanja)
      najmanja = x;
  }

  /* Ispis rezultata. */
  printf("Razlika: %d\n", najveca - najmanja);

  return 0;
}
