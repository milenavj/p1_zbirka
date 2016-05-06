/*
. a) Napisati funkciju 

	int konverzija (int c)

koja prebacuje veliko slovo u ekvivalentno malo i obrnuto.

b) Napisati program koji omogucava korisniku da unese niz karaktera
sa tastature, a potom ispisuje uneseni niz konvertovanih karaktera.
Na primer, za uneti tekst "Kolokvijum iz Prog1 je 1.12." program
treba da ispise "kOLOVKIJUM IZ pROG1 JE 1.12."

*/
#include <stdio.h>

int konverzija(int c)
{
  /* kljucna rec return vraca povratnu vrednost funkcije (ako je ima) */
  /* i zavrsava izvrsavanje funkcije */

  if (c>='A' && c<='Z')
    return c+'a'-'A';

  if (c>='a' && c<='z')
    return c-'a'+'A';
  
  return c;
}

int main()
{
  int c;

  while((c=getchar())!=EOF)  /* korisnik unosi karakter po karakter do konstante EOF */
    putchar(konverzija(c));  /* funkcija putchar ispisuje jedan 
                                karakter na standardni izlaz */

  return 0;
}