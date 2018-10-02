#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int x, y, rezultat;

  /* Ucitava se vrednost broja x. */
  printf("Unesite vrednost celobrojne promenljive x: ");
  scanf("%d", &x);

  /* Ucitava se vrednost broja y. */
  printf("Unesite vrednost celobrojne promenljive y: ");
  scanf("%d", &y);

  /* I nacin ispisa: dodela zbira x+y promenljivoj rezultat i 
     ispis vrednosti promenljive rezultat. */
  rezultat = x + y;
  printf("%d + %d = %d\n", x, y, rezultat);

  /* II nacin ispisa: direktan ispis vrednosti izraza, bez njegovog 
     dodeljivanja posebnoj promenljivoj. */
  printf("%d - %d = %d\n", x, y, x - y);
  printf("%d * %d = %d\n", x, y, x * y);

  /* Kada se operator / primeni na dva celobrojna argumenta x i y, 
     kao rezultat se dobije ceo deo pri deljenju broja x brojem y, 
     a ne kolicnik. Na primer, rezultat primene operatora / na 7 i 2
     je 3, a ne 3.5. */
  printf("%d / %d = %d\n", x, y, x / y);

  /* Operator % izracunava ostatak pri celobrojnom deljenju dve
     celobrojne promenljive.
     Da bi se odstampao karakter %, u naredbi printf se pise %%. */
  printf("%d %% %d = %d\n", x, y, x % y);

  return 0;
}
