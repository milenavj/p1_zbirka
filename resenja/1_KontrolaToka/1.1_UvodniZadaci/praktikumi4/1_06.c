
#include <stdio.h>

int main(){
  int cena;
  int kolicina; 
  int iznos; 
  int kusur;
  
  /* 
     Ucitavamo potrebne podatke. Unutar jednog scanf-a mozemo 
     ucitati vise podataka odjednom. Za svaki treba navesti 
     odgovarajuci format za tip podataka koji se unosi. 
  */
  printf("Unesite redom cenu, kolicinu i iznos: ");
  scanf("%d %d %d", &cena, &kolicina, &iznos);
  
  /* Izracunavamo kusur: */
  kusur=iznos - kolicina*cena;
  
  /* I ispisujemo trazenu vrednost: */
  printf("Kusur je %d dinara.\n", kusur);
 
  return 0;
}