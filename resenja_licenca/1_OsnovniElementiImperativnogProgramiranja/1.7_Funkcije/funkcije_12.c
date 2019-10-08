/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Funkcija odredjuje broj neparnih cifara u zapisu datog celog
   broja. */
int broj_neparnih_cifara(int x) {
  int brojac_neparnih = 0;
  char cifra;
  x = abs(x);

  while (x) {
    /* Izdvaja se poslednja cifra broja. */
    cifra = x % 10;
    
    /* Moze se izbeci koriscenje naredbe if pomocu narednog izraza. 
       Naime, vrednost izraza cifra%2 je 1 kada je cifra neparna,
       odnosno 0 kada je parna. Tako ce na broj neparnih cifara
       biti dodata jednica ako je cifra neparna, a ako je parna
       bice dodata 0, sto jeste zeljeno ponasanje. */
    brojac_neparnih += (cifra % 2);
    x /= 10;
  }

  return brojac_neparnih;
}

int main() {
  /* Deklaracija potrebne promenljive. */
  int x;

  /* Ucitavanje brojeva sve do unosa broja nula i ispis
     broja neparnih cifara za svaki ucitani broj. */
  printf("Unesite cele brojeve:\n");
  while (1) {
    scanf("%d", &x);
    if (x == 0)
      break;

    printf("Broj neparnih cifara: %d\n", broj_neparnih_cifara(x));
  }

  return 0;
}
