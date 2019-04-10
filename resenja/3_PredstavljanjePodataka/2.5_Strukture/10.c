#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS_TACAKA 1000

typedef struct 
{
  int x, y;
} Tacka;

/* Funkcija racuna rastojanje izmedju dve tacke. */
double rastojanje(const Tacka* a, const Tacka* b)
{
  return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

/* Funkcija ucitava tacke poligona. */
int ucitaj_poligon(Tacka poligon[], int maks_tacaka)
{
  int i = 0;

  while (scanf("%d%d", &poligon[i].x, &poligon[i].y) != EOF)
  {
    i++;
    if(i >= maks_tacaka)
      break;
  }

  return i;
}

/* Funkcija racuna obim poligona. */
double obim_poligona(Tacka poligon[], int n)
{
  double obim = 0;
  int i;

  for (i = 0; i < n - 1; i++)
    obim += rastojanje(&poligon[i], &poligon[i + 1]);

  obim += rastojanje(&poligon[n - 1], &poligon[0]);
  
  return obim;
}

/* Funkcija racuna najduzu stranicu poligona. */
double maksimalna_stranica(Tacka poligon[], int n)
{
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
double povrsina_trougla(const Tacka* A, const Tacka* B, const Tacka* C)
{
  double a = rastojanje(B, C);
  double b = rastojanje(A, C);
  double c = rastojanje(A, B);

  double s = (a + b + c) / 2;

  return sqrt(s * (s - a) * (s - b) * (s - c));
}

/* Funkocija racuna povrsinu poligona. */
double povrsina_poligona(Tacka * poligon, int n)
{
  double P = 0;
  int i;

  for (i = 1; i < n - 1; i++)
    P += povrsina_trougla(&poligon[0], &poligon[i], &poligon[i + 1]);

  return P;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int maks_tacaka, n;
  Tacka poligon[MAKS_TACAKA];

  /* Ucitavanje maksimalnog broja tacaka i provera ispravnosti. */
  printf("Uneti maksimalan broj tacaka poligona: ");
  scanf("%d", &maks_tacaka);
  if (maks_tacaka < 3 || maks_tacaka > MAKS_TACAKA) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje poligona. */
  n = ucitaj_poligon(poligon, maks_tacaka);
  if (n < 3) 
  {
    printf("Greska: poligon mora imati bar tri tacke.\n");
    exit(EXIT_FAILURE);
  }

  /* Ispis rezultata. */
  printf("Obim poligona je %.3lf.\n", 
         obim_poligona(poligon, n));
  printf("Duzina maksimalne stranice je %.3lf.\n",
         maksimalna_stranica(poligon, n));
  printf("Povrsina poligona je %.3lf.\n", 
         povrsina_poligona(poligon, n));

  return 0;
}
