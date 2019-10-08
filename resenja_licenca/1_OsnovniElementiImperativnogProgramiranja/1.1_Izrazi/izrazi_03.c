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
  int x, y, rezultat;

  /* Ucitavanje vrednosti broja x. */
  printf("Unesite vrednost broja x: ");
  scanf("%d", &x);

  /* Ucitavanje vrednosti broja y. */
  printf("Unesite vrednost broja y: ");
  scanf("%d", &y);

  /* I nacin ispisa: Dodela zbira x+y promenljivoj rezultat i 
     ispis vrednosti promenljive rezultat. */
  rezultat = x + y;
  printf("%d + %d = %d\n", x, y, rezultat);

  /* II nacin ispisa: Direktan ispis vrednosti izraza, bez njegovog 
     dodeljivanja posebnoj promenljivoj. */
  printf("%d - %d = %d\n", x, y, x - y);
  printf("%d * %d = %d\n", x, y, x * y);

  /* Kada se operator / primeni na dva celobrojna operanda x i y, 
     kao rezultat se dobije ceo deo pri deljenju broja x brojem y, 
     a ne kolicnik. Na primer, rezultat primene operatora / na 7 i 2
     je 3, a ne 3.5. */
  printf("%d / %d = %d\n", x, y, x / y);

  /* Operator % izracunava ostatak pri celobrojnom deljenju dve
     celobrojne promenljive ili izraza.
     Da bi se odstampao karakter %, u pozivu funkcije printf se pise %%. */
  printf("%d %% %d = %d\n", x, y, x % y);

  return 0;
}
