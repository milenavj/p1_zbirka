#include <stdio.h>

int main()
{

  /* Deklaracija potrebnih promenljivih. */
  unsigned int poletanje, poletanje_sat, poletanje_minut;
  unsigned int sletanje, sletanje_sat, sletanje_minut;
  unsigned int duzina, duzina_sat, duzina_minut;

  /* Ucitavaju se sat i minut vremena poletanja. */
  printf("Unesite vreme poletanja: ");
  scanf("%u%u", &poletanje_sat, &poletanje_minut);

  /* Ucitavaju se sat i minut vremena sletanja. */
  printf("Unesite vreme sletanja: ");
  scanf("%u%u", &sletanje_sat, &sletanje_minut);

  /* Obe vrednosti se pretvaraju u sekunde, 
     kako bi se lakse izracunala razlika. */
  poletanje = poletanje_sat * 3600 + poletanje_minut * 60;
  sletanje = sletanje_sat * 3600 + sletanje_minut * 60;

  /* Racunanje razlike u sekundama izmedju sletanja i poletanja. */
  duzina = sletanje - poletanje;

  /* Razlika u sekundama se pretvara u razliku u satima i minutima.
     Razlika u satima se dobija celobrojnim deljenjem broja sekundi
     sa 3600.
     Preostali broj minuta se dobija deljenjem preostalog broja 
     sekundi sa 60. */
  duzina_sat = duzina / 3600;
  duzina_minut = (duzina - duzina_sat * 3600) / 60;
  
  /* II nacin: duzina_minut = (duzina % 3600) / 60; */
  
  /* Ispis rezultata. */
  printf("Duzina trajanja leta je %u h i %u min\n", duzina_sat,
         duzina_minut);

  return 0;
}
