#include <stdio.h>
#include <stdlib.h>

#define MAKS_ARTIKALA 20
#define MAKS_KORPI 100
#define MAKS_NAZIV 31

/* Struktura koja opisuje artikal. */
typedef struct {
  char naziv[MAKS_NAZIV];
  int kolicina;
  float cena;
} Artikal;

/* Struktura koja opisuje korpu. */
typedef struct {
  int broj_artikala;
  Artikal artikli[MAKS_ARTIKALA];
} Korpa;

/* Funkcija ucitava jedan artikal i proverava ispravnost ucitanih
   podataka. */
void ucitaj_artikal(Artikal *a) {
  printf("Unesite artikal (naziv, kolicinu i cenu): ");
  scanf("%s%d%f", a->naziv, &a->kolicina, &a->cena);

  if (a->kolicina <= 0) {
    printf("Greska: neispravan unos kolicine (%d).\n", a->kolicina);
    exit(EXIT_FAILURE);
  }

  if (a->cena < 0) {
    printf("Greska: neispravan unos cene (%f).\n", a->cena);
    exit(EXIT_FAILURE);
  }
}

/* Funkcija ucitava podatke o jednoj potrosackoj korpi. */
void ucitaj_korpu(Korpa *k) {
  int i;
  printf("Unesite podatke o korpi: \n");

  /* Ucitavanje broja artikala u korpi. */
  printf("Broj artikala: ");
  scanf("%d", &k->broj_artikala);
  if (k->broj_artikala <= 0) {
    printf("Greska: neispravan unos broja artikala (%d).\n",
           k->broj_artikala);
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje podataka o svakom artiklu. */
  for (i = 0; i < k->broj_artikala; i++)
    ucitaj_artikal(&k->artikli[i]);
}

/* Funkcija ucitava podatke o n potrosackih korpi. */
void ucitaj_niz_korpi(Korpa korpe[], int n) {
  int i;
  for (i = 0; i < n; i++)
    ucitaj_korpu(&korpe[i]);
}

/* Funkcija racuna ukupan racun za datu korpu. */
float izracunaj_racun(const Korpa *k) {
  int i;
  float racun = 0;

  for (i = 0; i < k->broj_artikala; i++)
    racun += k->artikli[i].kolicina * k->artikli[i].cena;

  return racun;
}

/* Funkcija ispisuje racun za datu korpu. */
void ispisi_racun(const Korpa *k) {
  int i;
  for (i = 0; i < k->broj_artikala; i++)
    printf("\t%s %d %.2f\n", k->artikli[i].naziv,
           k->artikli[i].kolicina, k->artikli[i].cena);
  printf("------------------------\n");
  printf("\tukupno: %.2f\n", izracunaj_racun(k));
}

/* Funkcija ispisuje racune za sve potrosacke korpe u nizu. */
void ispisi_racune_za_korpe(Korpa korpe[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("\nKorpa %d:\n", i);
    ispisi_racun(&korpe[i]);
  }
}

/* Funkcija racuna prosecnu cenu potrosacke korpe za dati niz
   potrosackih korpi. */
float prosek(Korpa korpe[], int n) {
  int i;
  float prosecna_cena = 0;

  for (i = 0; i < n; i++)
    prosecna_cena += izracunaj_racun(&korpe[i]);

  return prosecna_cena / n;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n;
  Korpa korpe[MAKS_KORPI];

  /* Ucitavanje broja potrosackih korpi i provera ispravnosti
     ulaza. */
  printf("Unesite broj potrosackih korpi:");
  scanf("%d", &n);
  if (n < 0 || n > MAKS_KORPI) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje podataka o potrosackim korpama. */
  ucitaj_niz_korpi(korpe, n);

  /* Ispis svih racuna. */
  ispisi_racune_za_korpe(korpe, n);

  /* Ispis prosecne cene potrosacke korpe. */
  printf("Prosecna cena potrosacke korpe: %.2f\n",
         prosek(korpe, n));

  return 0;
}
