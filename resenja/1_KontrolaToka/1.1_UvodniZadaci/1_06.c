
#include <stdio.h>

int main()
{
  /*
     S obzirom da su sve promenljive pozitivini celi brojevi,
     koristimo tip unsigned int (skraceno unsigned)
  */
  unsigned cena;
  unsigned kolicina; 
  unsigned iznos; 
  unsigned kusur;
  
  /* 
     Ucitavamo potrebne podatke. Unutar jednog scanf-a mozemo 
     ucitati vise podataka odjednom. Za svaki treba navesti 
     odgovarajuci format za tip podataka koji se unosi
     (%u za unsigned). 
  */
  printf("Unesite cenu, kolicinu i iznos: ");
  scanf("%u%u%u", &cena, &kolicina, &iznos);
  
  /* Izracunavamo kusur: */
  kusur=iznos - kolicina*cena;
  
  /* I ispisujemo trazenu vrednost: */
  printf("Kusur je %u dinara.\n", kusur);
 
  return 0;
}