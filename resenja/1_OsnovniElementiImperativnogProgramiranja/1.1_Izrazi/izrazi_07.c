#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int poletanje, poletanje_sat, poletanje_minut;
  unsigned int sletanje, sletanje_sat, sletanje_minut;
  unsigned int duzina, duzina_sat, duzina_minut;

  /* Ucitavanje vremena poletanja. */
  printf("Unesite vreme poletanja: ");
  scanf("%u%u", &poletanje_sat, &poletanje_minut);

  /* Ucitavanje vremena sletanja. */
  printf("Unesite vreme sletanja: ");
  scanf("%u%u", &sletanje_sat, &sletanje_minut);

  /* Pretvaranje oba vremena u minute radi lakseg racunanja 
     razlike. */
  poletanje = poletanje_sat * 60 + poletanje_minut;
  sletanje = sletanje_sat * 60 + sletanje_minut;

  /* Racunanje razlike u minutima izmedju sletanja i poletanja. */
  duzina = sletanje - poletanje;

  /* Pretvaranje razlike u minutama u razliku u satima i minutima.
     Razlika u satima se dobija celobrojnim deljenjem broja minuta
     sa 60.
     Preostali broj minuta se dobija kao ostatak pri deljenju sa 60. */
  duzina_sat = duzina / 60;
  duzina_minut = duzina % 60;
  
  /* II nacin: duzina_minut = duzina - duzina*60; */
  
  /* Ispis rezultata. */
  printf("Duzina trajanja leta: %u h i %u min\n", duzina_sat,
         duzina_minut);

  return 0;
}
