/* Napisati program koji u datom prirodnom broju x ubacuje cifru c na poziciju p
i rezultat ispisuje na standardni izlaz. Brojevi x, c i p se unose sa
standardnog ulaza. Podrazumeva se da je broj p manji od ukupnog broja
cifara broja i da numeracija cifara pocinje od 1. 

Uputstvo: koristiti funkciju pow iz math.h biblioteke za racunanje stepena
broja.  Na primer, pow(10, 2)=100.000. 
S obzirom da funkcija pow vraca double vrednosti, pre upotrebe je potrebno
konvertovati (kastovati) ove vrednosti u int tip. 

Prilikom prevodjenja programa koristiti -lm opciju.
*/

#include <stdio.h>
#include <math.h>

int main(){
  int x, c, p;
  int levo, desno;
  int novo_x;

  /* Ucitavamo potrebne vrednosti */
  printf("Unesite redom x, c i p: ");
  scanf("%d %d %d", &x, &c, &p);
  
  /* Odredjujemo deo broja koji se nalazi desno od pozicije p */
  desno=x%(int)pow(10, p-1);
  
  /* Odredjujemo deo broja koji se nalazi levo od pozicije p */
  levo=x/(int)pow(10, p-1);
  
  /* Odredjujemo novi broj */
  novo_x=levo*(int)pow(10, p) +c*(int)pow(10, p-1) + desno;
 
  /* Ispisujemo dobijenu vrednost */
  printf("Rezultat je: %d\n", novo_x);
  
  /* Zavrsavamo sa programom */
  return 0;

}