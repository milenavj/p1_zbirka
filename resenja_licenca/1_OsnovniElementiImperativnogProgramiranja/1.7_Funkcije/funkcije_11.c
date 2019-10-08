/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Funkcija ispituje da li se cifra c nalazi u zapisu celog broja
   x. Vraca 1 ako je uslov ispunjen i 0 u suprotnom. */
int sadrzi(int x, int c) {
  /* Izracunava se apsolutna vrednost broja x. */
  x = abs(x);

  /* Izdvaja se cifra po cifra broja x. Ako se naidje na cifru cija 
     je vrednost c, onda se kao rezultat funkcije vraca 1 (jer x
     sadrzi c). */
  while (x) {
    if (x % 10 == c)
      return 1;
    x /= 10;
  }

  /* Ako se petlja zavrsila, znaci da se nijednom nije naislo na
     cifru c, sto znaci da broj x ne sadrzi cifru c i kao povratna
     vrednost funkcije se vraca 0. */
  return 0;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int x, c;

  /* Ucitavanje vrednosti x i c. */
  printf("Unesite broj i cifru:");
  scanf("%d%d", &x, &c);

  /* Provera ispravnosti ulaza. */
  if (c < 0 || c > 9) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Racunanje i ispis rezultata. */
  if (sadrzi(x, c))
    printf("Cifra %d se nalazi u zapisu broja %d\n", c, x);
  else
    printf("Cifra %d se ne nalazi u zapisu broja %d\n", c, x);
  
  return 0;
}
