/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracija potrebne promenljive. */
  char c;

  /* Ucitavanje jednog karaktera. */
  printf("Unesite jedan karakter:");
  scanf("%c", &c);

  /* Proverava se da li je karakter c samoglasnik, tj. da li
     odgovara nekom od sledecih karaktera: A,E,I,O,U,a,e,i,o,u. */
  switch (c) {
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    printf("Uneti karakter je samoglasnik.\n");
    break;
  default:
    printf("Uneti karakter nije samoglasnik.\n");
    break;
  }

  return 0;
}
