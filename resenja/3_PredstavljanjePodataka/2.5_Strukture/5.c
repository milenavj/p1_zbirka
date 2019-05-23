#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int brojilac;
  int imenilac;
} Razlomak;

/* Funkcija Euklidovim algoritmom racuna najveci zajednicki delilac 
   brojeva a i b. */
int nzd(int a, int b) {
  int ostatak;

  while (b != 0) {
    ostatak = a % b;
    a = b;
    b = ostatak;
  }

  return a;
}

/* Funkcija vraca razlomak koji se dobija deljenjem imenioca i
   brojioca sa njihovim najvecim zajednickim deliocem. */
void uprosti(Razlomak *r) {
  int nzd_razlomka = nzd(r->brojilac, r->imenilac);
  r->brojilac /= nzd_razlomka;
  r->imenilac /= nzd_razlomka;
}

/* Funkcija racuna zbir razlomaka a i b. */
Razlomak saberi(const Razlomak *a, const Razlomak *b) {
  Razlomak c;

  c.brojilac = a->brojilac * b->imenilac + 
               b->brojilac * a->imenilac;
  c.imenilac = a->imenilac * b->imenilac;
  uprosti(&c);

  return c;
}

/* Funkcija racuna proizvod razlomaka a i b. */
Razlomak pomnozi(const Razlomak *a, const Razlomak *b) {
  Razlomak c;

  c.brojilac = a->brojilac * b->brojilac;
  c.imenilac = a->imenilac * b->imenilac;
  uprosti(&c);

  return c;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  Razlomak suma, proizvod, r;

  /* Ucitavanje broja razlomaka i provera ispravnosti ulaza. */
  printf("Unesite broj razlomaka: ");
  scanf("%d", &n);
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Inicijalizacija sume i proizvoda. */
  suma.brojilac = 0;
  suma.imenilac = 1;
  proizvod.brojilac = 1;
  proizvod.imenilac = 1;

  /* Ucitavanje razlomaka i racunanje rezultata. */
  printf("Unesite razlomke:\n");
  for (i = 0; i < n; i++) {
    scanf("%d%d", &r.brojilac, &r.imenilac);

    if (r.imenilac == 0) {
      printf("Greska: neispravan unos.\n");
      exit(EXIT_FAILURE);
    }

    suma = saberi(&suma, &r);
    proizvod = pomnozi(&proizvod, &r);
  }

  /* Ispis rezultata. */
  printf("Suma svih razlomaka: %d/%d\n", suma.brojilac,
         suma.imenilac);
  printf("Proizvod svih razlomaka: %d/%d\n", proizvod.brojilac,
         proizvod.imenilac);

  return 0;
}
