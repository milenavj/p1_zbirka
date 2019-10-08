/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

/* Prevodjenje programa program.c na Linux operativnom sistemu 
  koriscenjem kompajlera gcc vrsi se iz terminala komandom 
  gcc program.c
  Ukoliko program.c ne sadrzi greske, kompajler ce napraviti 
  izvrsnu verziju programa koja ce se zvati a.out 
  Ovaj program se moze pokrenuti iz terminala navodjenjem komande
  ./a.out
  Ukoliko se program prevede na sledeci nacin
  gcc program.c -o program
  onda ce izvrsna verzija biti imenovana nazivom koji je dat nakon 
  -o opcije (u ovom slucaju je to rec program) tako da se pokretanje 
  iz terminala moze uraditi navodjenjem komande 
  ./program 
*/

int main() {
  /* Ispis trazene poruke. Na kraju poruke se ispisuje novi red. */
  printf("Zdravo svima!\n");

  /* Povratna vrednost 0 se obicno koristi da oznaci da je prilikom 
     izvrsavanja programa sve proslo u redu. */
  return 0;
}
