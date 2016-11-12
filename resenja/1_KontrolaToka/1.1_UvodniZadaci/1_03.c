#include<stdio.h>

int main()
{
  /* Promenljive istog tipa mogu se deklarisati jedna za drugom. */
  int x, y, rezultat;

  printf("Unesi vrednost celobrojne promenljive x: ");
  scanf("%d", &x);

  printf("Unesi vrednost celobrojne promenljive y: ");
  scanf("%d", &y);

  /* Dodeljujemo vrednost promenljivoj rezultat. */
  rezultat = x + y;
  printf("%d + %d = %d\n", x, y, rezultat);

  /* Mozemo ispisivati direktno vrednost izraza x-y i bez njegovog 
     dodeljivanja posebnoj promenljivoj */
  printf("%d - %d = %d\n", x, y, x - y);
  printf("%d * %d = %d\n", x, y, x * y);

  /* Kada bilo koju artimeticku operaciju primenimo na dve
     promenljive istog tipa (u ovom slucaju dva celobrojne
     promenljive), rezultat ce biti tog istog tipa. Specijalno, za 
     operaciju deljenja: kada operator / primenimo na dva
     celobrojna argumenta x i y, kao rezultat dobijemo ceo deo pri 
     deljenju broja x brojem y, a ne kolicnik. Na primer, rezultat 
     primene operatora / na 7 i 2 je 3, a ne 3.5. */
  printf("%d / %d = %d\n", x, y, x / y);

  /* Operator % izracunava ostatak pri celobrojnom deljenju dve
     celobrojne promenljive. Na primer, 7%2 ima vrednost 1 (jer je 
     7=3*2+1). Da bismo odstampali karakter %, u naredbi printf
     pisemo %% */
  printf("%d %% %d = %d\n", x, y, x % y);

  return 0;
}
