#include <stdio.h>
#include <stdlib.h>

#define MIN_RGB 0
#define MAKS_RGB 255

/* Funkcija koja vrsi konverziju boje iz rgb formata u cmy format.
   Kako se pomocu naredbe return ne moze vratiti vise od jedne
   vrednosti, neophodno je da se promenljive cije se vrednosti
   racunaju prenesu preko pokazivaca. */
void rgb_u_cmy(int r, int g, int b, float* c, float* m, float* y)
{
  *c = 1 - r / 255.0;
  *m = 1 - g / 255.0;
  *y = 1 - b / 255.0;
}

/* Funkcija koja proverava da li je vrednost boje u ispravnom
   opsegu. */
int ispravna_rgb_vrednost(int a)
{
  if (a < MIN_RGB || a > MAKS_RGB)
    return 0;
  return 1;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int r, g, b;
  float c, m, y;

  /* Ucitava se vrednost boje u rgb formatu. */
  printf("Unesite boju u rgb formatu: ");
  scanf("%d%d%d", &r, &g, &b);

  /* Vrsi se provera ispravnosti ulaza. */
  if (!ispravna_rgb_vrednost(r) || !ispravna_rgb_vrednost(g) ||
      !ispravna_rgb_vrednost(b))
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Konverzija boje i ispis rezultata. Funkciji se kao argumenti
     prosledjuju vrednosti brojeva r, g, i b, kao i adrese na koje
     treba da se upisu izracunate c, m, y vrednosti. */
  rgb_u_cmy(r, g, b, &c, &m, &y);
  printf("cmy: (%.2f,%.2f,%.2f)\n", c, m, y);

  exit(EXIT_SUCCESS);
}
