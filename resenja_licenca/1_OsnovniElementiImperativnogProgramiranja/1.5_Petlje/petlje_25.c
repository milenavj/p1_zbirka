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
  int x, pozicija, rezultat, cifra;
  int znak = 1;

  /* Ucitavanje vrednosti polaznog broja. */
  printf("Unesite broj: ");
  scanf("%d", &x);

  /* Ako je broj negativan, koristi se njegova apsolutna vrednost
     i azurira se vrednost znaka broja. */
  if (x < 0) {
    x = abs(x);
    znak = -1;
  }

  /* Pozicija oznacava tezinu trenutne cifre rezultata i moze imati
     vrednosti 1, 10, 100, ... */
  pozicija = 1;
  rezultat = 0;

  /* Ideja: u rezultatu se zadrzavaju cifre jedinice, stotine,.. Na 
     primer, x=12345 Pre petlje: pozicija = 1, rezultat = 0 1.
     iteracija: cifra = 5, rezultat = 0+5*1=5, x = 123, pozicija = 
     10 2. iteracija: cifra = 3, rezultat = 5+3*10 = 35, x = 1,
     pozicija = 100 3. iteracija: cifra = 1, rezultat = 35+1*100,
     x = 0, pozicija = 1000 Petlja se zavrsava jer x ima vrednost
     0. */
  while (x > 0) {
    /* Izdvajanje poslednje cifre. */
    cifra = x % 10;

    /* Rezultat se uvecava za vrednost cifre pomnozene vrednoscu
       tezine njene pozicije u broju. */
    rezultat += cifra * pozicija;

    /* Uklanjanje poslednje dve cifre polaznog broja jer u rezultatu
       treba da ostane svaka druga cifra. */
    x /= 100;

    /* Mnozenje pozicije sa 10, kako bi imala ispravnu vrednost u
       sledecoj iteraciji. */
    pozicija *= 10;
  }

  /* Ispis rezultata */
  printf("Rezultat: %d\n", znak * rezultat);

  return 0;
}
