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
  printf("Unesite karakter: ");
  scanf("%c", &c);

  /* Ispis karaktera i vrednosti njegovog ASCII koda. */
  printf("Uneti karakter: %c\n", c);
  printf("ASCII kod: %d\n", c);

  /* Karakteri koji odgovaraju velikim slovima su u ASCII tablici
     smesteni sekvencijalno. Na primer, ASCII kod karaktera 'A' je
     65, 'B' je 66, ..., 'Z' je 90. Isto vazi i za mala slova: 'a' 
     je 97, 'b' je 98, ..., 'z' je 122.

     Odavde, ako se vrsi provera da li je neki karakter veliko
     slovo, dovoljno je proveriti da li se njegov ASCII kod nalazi
     izmedju ASCII kodova slova 'A' i slova 'Z'.

     Dodatno, moze se primetiti da je razlika izmedju ASCII koda
     svakog malog i odgovarajuceg velikog slova konstanta koja ima 
     vrednost 'a'-'A', sto je isto sto i 'b'-'B', itd. Zbog toga,
     ako je potrebno od velikog slova dobiti malo, onda je
     dovoljno ASCII kodu velikog slova dodati pomenutu konstantu.
     Za mala slova, vazi obrnuto - da bi se dobilo veliko slovo,
     ova konstanta se oduzima. */

  if (c >= 'A' && c <= 'Z') {
    printf("Odgovarajuce malo slovo: %c\n", c + ('a' - 'A'));
    printf("ASCII kod: %d\n", c + ('a' - 'A'));
  }

  if (c >= 'a' && c <= 'z') {
    printf("Odgovarajuce veliko slovo: %c\n", c - ('a' - 'A'));
    printf("ASCII kod: %d\n", c - ('a' - 'A'));
  }

  return 0;
}
