/* Napisati program koji za unetu kolicinu jabuka u kilogramima i unetu cenu
po kilogramu ispisuje ukupan iznos koji treba platiti */

#include <stdio.h>

int main(){
  int kolicina; 
  int cena;

  /* Ucitavamo potrebne podatke */
  printf("Unesite kolicinu jabuka (u kg): ");
  scanf("%d", &kolicina);
  
  printf("Unesite cenu (u dinarima): ");
  scanf("%d", &cena);
  
  /* Ispisujemo trazeni iznos */
  printf("Molimo platite %d dinara.\n", kolicina*cena);
  
  /* Zavrsavamo sa programom */
  return 0;

}