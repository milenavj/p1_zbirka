/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS_TEMENA 1000

/* Struktura koja opisuje tacku. */
typedef struct {
  int x, y;
} Tacka;

/* Funkcija racuna rastojanje izmedju dve tacke. */
double rastojanje(const Tacka *a, const Tacka *b) {
  return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

/* Funkcija ucitava temena poligona. */
int ucitaj_poligon(Tacka poligon[], int maks_temena) {
  int i = 0;

  printf("Unesite temena poligona:\n");
  while (scanf("%d%d", &poligon[i].x, &poligon[i].y) != EOF) {
    i++;
    if (i >= maks_temena)
      break;
  }

  return i;
}

/* Funkcija racuna obim poligona. */
double obim_poligona(Tacka poligon[], int n) {
  double obim = 0;
  int i;

  for (i = 0; i < n - 1; i++)
    obim += rastojanje(&poligon[i], &poligon[i + 1]);

  obim += rastojanje(&poligon[n - 1], &poligon[0]);

  return obim;
}

/* Funkcija racuna najduzu stranicu poligona. */
double maksimalna_stranica(Tacka poligon[], int n) {
  double maks = rastojanje(&poligon[0], &poligon[n - 1]);
  double stranica;
  int i;

  for (i = 0; i < n - 1; i++) {
    stranica = rastojanje(&poligon[i], &poligon[i + 1]);
    if (stranica > maks)
      maks = stranica;
  }

  return maks;
}

/* Funkcija racuna povrsinu trougla cija su temena A, B i C. */
double povrsina_trougla(const Tacka *A, const Tacka *B,
                        const Tacka *C) {
  double a = rastojanje(B, C);
  double b = rastojanje(A, C);
  double c = rastojanje(A, B);
  double s = (a + b + c) / 2;

  return sqrt(s * (s - a) * (s - b) * (s - c));
}

/* Funkcija racuna povrsinu poligona. */
double povrsina_poligona(Tacka *poligon, int n) {
  double povrsina = 0;
  int i;

  for (i = 1; i < n - 1; i++)
    povrsina += povrsina_trougla(&poligon[0], &poligon[i],
                          &poligon[i + 1]);

  return povrsina;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int maks_temena, n;
  Tacka poligon[MAKS_TEMENA];

  /* Ucitavanje maksimalnog broja temena i provera ispravnosti. */
  printf("Unesite maksimalan broj temena poligona: ");
  scanf("%d", &maks_temena);
  if (maks_temena < 3 || maks_temena > MAKS_TEMENA) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje poligona. */
  n = ucitaj_poligon(poligon, maks_temena);
  if (n < 3) {
    printf("Greska: poligon mora imati bar tri temena.\n");
    exit(EXIT_FAILURE);
  }

  /* Ispis rezultata. */
  printf("Obim poligona je %.3lf.\n", obim_poligona(poligon, n));
  printf("Duzina maksimalne stranice je %.3lf.\n",
         maksimalna_stranica(poligon, n));
  printf("Povrsina poligona je %.3lf.\n",
         povrsina_poligona(poligon, n));

  exit(EXIT_SUCCESS);
}
