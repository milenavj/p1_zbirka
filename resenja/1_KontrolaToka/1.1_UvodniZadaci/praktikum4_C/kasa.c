/* Napisati program koji pomaze kasirki da obracuna kusur tako sto od nje trazi
da unese cenu artikla, kolicinu artikla i iznos koji je dobila od kupca. */

#include <stdio.h>

int main(){
  int cena;
  int kolicina; 
  int iznos; 
  int kusur;
  
  /* Ucitavamo potrebne podatke */
  printf("Unesite redom cenu, kolicinu i iznos: ");
  scanf("%d %d %d", &cena, &kolicina, &iznos);
  
  /* Izracunavamo kusur */
  kusur=iznos - kolicina*cena;
  
  /* I ispisujemo trazenu vrednost */
  printf("Kusur je %d dinara.\n", kusur);
 
  return 0;
}