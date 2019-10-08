/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracije i inicijalizacije potrebnih promenljivih. */
  char c;
  int broj_velikih = 0, broj_malih = 0;
  int broj_cifara = 0, suma_cifara = 0, broj_belina = 0;

  /* Petlja se zavrsava kada korisnik zada konstantu koja oznacava 
     kraj ulaza (EOF konstantu). Ova konstanta se zadaje kombinacijom
     tastera CTRL+D i ima vrednost -1. */
  printf("Unesite tekst:\n");
  while ((c = getchar()) != EOF) {
    if (c >= 'A' && c <= 'Z')
      broj_velikih++;
    else if (c >= 'a' && c <= 'z')
      broj_malih++;
    else if (c >= '0' && c <= '9') {
      broj_cifara++;
      suma_cifara = suma_cifara + c - '0';
    } else if (c == '\t' || c == '\n' || c == ' ')
      broj_belina++;
  }

  /* Ispis rezultata. */
  printf("Velika slova: %d\nMala slova: %d\n", broj_velikih, broj_malih);
  printf("Cifre: %d\nBeline: %d\n", broj_cifara, broj_belina);
  printf("Suma cifara: %d\n", suma_cifara);

  return 0;
}
