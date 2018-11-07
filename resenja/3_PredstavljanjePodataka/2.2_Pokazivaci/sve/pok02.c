#include <stdio.h>
#include <stdlib.h>

#define MIN_RGB 0
#define MAKS_RGB 255

/* Funkcija koja vrsi konverziju boje iz rgb formata u cmy format.
   Kako pomocu naredbe return ne mozemo vratiti vise od jedne
   vrednosti, neophodno je da promenljive ciju vrednost zelimo
   da promenimo prenesemo preko pokazivaca.*/
void rgb_u_cmy(float *a, float *b, float *c)
{
  *a = 1 - *a / 255;
  *b = 1 - *b / 255;
  *c = 1 - *c / 255;
}

/* Funkcija koja proverava da li je vrednost boje u ispravnom
   opsegu. */
int ispravna_rgb_vrednost(float a)
{
  if (a < MIN_RGB || a > MAKS_RGB)
    return 0;
  return 1;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float a, b, c;

  /* Ucitava se vrednost boje u rgb formatu. */
  printf("Unesite boju u rgb formatu: ");
  scanf("%f%f%f", &a, &b, &c);

  /* Vrsi se provera ispravnosti ulaza. */
  if (!ispravna_rgb_vrednost(a) || !ispravna_rgb_vrednost(b) ||
      !ispravna_rgb_vrednost(c))
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Konverzija boje i ispis rezultata. */
  rgb_u_cmy(&a, &b, &c);
  printf("cmy: (%.2f,%.2f,%.2f)\n", a, b, c);

  exit(EXIT_SUCCESS);
}
