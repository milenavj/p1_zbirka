#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Funkcija koja racuna broj cifara celog broja n. */
int broj_cifara(int n)
{
  int brojac = 0;
  n = abs(n);
  
  if(n < 10)
    return 1;
  
  while(n)
  {
    brojac++;
    n /= 10;
  }
    
  return brojac;
}


/* Funkcija proverava da li je broj Armstrongov. */
int armstrong(int x)
{
  int suma = 0;
  int n = broj_cifara(x);
  int x_pocetno = x;

  /* Racuna se suma n-tih stepena cifara broja x. */
  while (x) {
    suma += pow(x % 10, n);
    x /= 10;
  }

  /* Ako je suma jednaka pocetnoj vrednosti broja x, broj je
     Armstrongov, u suprotnom nije. */
  return x_pocetno == suma;
}


int main()
{
  /* Deklaracija potrebne promenljive. */
  int x;
  
  /* Ucitava se vrednost broja x. */
  printf("Unesite broj: ");
  scanf("%d", &x);

  /* Proverava se da li je x Armstrongov broj i ispisuje se
     odgovarauca poruka. */
  if (armstrong(x))
    printf("Broj je Armstrongov.\n");
  else
    printf("Broj nije Armstrongov.\n");

  return 0;
}
