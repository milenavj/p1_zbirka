/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <math.h>

/* Uvek kada se koristi neka funkcija iz matematicke bibilioteke
  (na primer , funkcije sqrt , pow , sin , cos) 
  potrebno je prilikom prevodjenja dodati i opciju -lm kojom se 
  kompajler upucuje da je za pravljenje izvrsne verzije programa 
  potrebno da se program poveze sa matematickom bibliotekom. 
  Ukoliko se ova opcija ne navede, kompajler prijavljuje gresku: 
  collect2: error: ld returned 1 exit status
*/

int main() {
  /* Deklaracija potrebnih promenljivih. */
  float a, povrsina, obim;

  /* Ucitavanje duzina stranice. */
  printf("Unesite duzinu stranice trougla: ");
  scanf("%f", &a);

  /* Racunanje obima i povrsine. */
  obim = 3 * a;
  povrsina = (a * a * sqrt(3)) / 4;

  /* Ispis rezultata na dve decimale. */
  printf("Obim: %.2f\n", obim);
  printf("Povrsina: %.2f\n", povrsina);

  return 0;
}
