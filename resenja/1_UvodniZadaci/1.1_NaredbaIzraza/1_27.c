#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int duzina, sirina, visina;
  unsigned int cena;
  float povrsina_za_krecenje;
  float ukupna_cena;

  /* Ucitavaju se vrednosti duzine, sirine i visine sobe. */
  printf("Unesite dimenzije sobe: ");
  scanf("%u%u%u", &duzina, &sirina, &visina);

  /* Ucitava se cena krecenja */
  printf("Unesite cenu po m2: ");
  scanf("%u", &cena);

  /* Povrsina za krecenje odgovara povrsini kvadra 
     umanjena za povrsinu poda jer se on ne kreci. */
  povrsina_za_krecenje = 0.8 * (duzina * sirina +
                                2 * duzina * visina +
                                2 * sirina * visina);
  
  /* Racuna se ukupna cena. */
  ukupna_cena = povrsina_za_krecenje * cena;

  /* Ispis rezultata. */
  printf("Moler treba da okreci %.2f m2\n", povrsina_za_krecenje);
  printf("Cena krecenja je %.2f\n", ukupna_cena);

  return 0;
}
