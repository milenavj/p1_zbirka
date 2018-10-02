#include <stdio.h>

/* Funkcija konvertuje malo slovo u veliko ili veliko slovo u malo, ostali karakteri su nepromenjeni. U resenju zadatka se mogu koristiti i ugradjene funkcije islower, isupper, tolower i toupper (procitati vise o njima na man stranama). Funkcije pripadaju zaglavlju ctype.h. Za vezbu napisati resenje koriscenjem ugradjenih funkcija. */
int konverzija(int c)
{
  if (c>='A' && c<='Z')
    return c+'a'-'A';

  if (c>='a' && c<='z')
    return c-'a'+'A';
  
  return c;
}

int main()
{
  int c;

  /* Korisnik unosi karakter po karakter do konstante EOF. */
  while((c=getchar())!=EOF)  
    /* Poziva se funkcija koja menja karakter i novodobijeni karakter se ispisuje sa funkcijom putchar. */
    putchar(konverzija(c));  

  return 0;
}
