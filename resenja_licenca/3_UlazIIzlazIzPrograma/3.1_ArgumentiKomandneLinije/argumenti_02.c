/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Funkcija proverava da li prosledjenu nisku cine samo karakteri
   koji su cifre. */
int samo_cifre(char arg[]) {
  int i;

  /* Prvi karakter mora biti ili cifra ili znak broja. */
  if (!isdigit(arg[0]) && arg[0] != '+' && arg[0] != '-')
    return 0;

  /* Ostali karakteri moraju biti cifre. */
  for (i = 1; arg[i]; i++)
    if (!isdigit(arg[i]))
      return 0;

  return 1;
}

int main(int argc, char *argv[]) {
  /* Deklaracija potrebnih promenljivih. */
  int i, suma = 0;

  /* Kako su argumenti komandne linije niske, potrebno ih je
     konvertovati u brojeve. Za ovo je moguce koristiti funkciju
     atoi. Npr. atoi("567") ima vrednost 567. Treba voditi racuna:
     atoi("abc") ima vrednost 0, ali atoi("12abc") ima vrednost 12.
     Dakle ova funkcija se zaustavlja u trenutku kada se u okviru
     niske naidje na prvi karakter koji nije cifra. Iz tog razloga
     je potrebno proveriti da li dati argument sadrzi samo cifre. */
  for (i = 1; i < argc; i++)
    if (samo_cifre(argv[i]))
      suma += atoi(argv[i]);

  /* Ispis rezultata. */
  printf("Zbir celobrojnih argumenata: %d\n", suma);

  return 0;
}
