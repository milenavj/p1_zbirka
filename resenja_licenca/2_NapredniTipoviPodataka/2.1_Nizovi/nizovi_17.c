/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAKS 600

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n) {
  int i;
  printf("Unesite elemente niza a: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija ispisuje elemente niza dimenzije n. */
void ispisi(int niz[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

/* Funkcija proverava da li niz a dimenzije n sadrzi zadatu
   vrednost x. Pretraga se vrsi od prosledjene pozicije. */
int sadrzi(int niz[], int n, int od_pozicije, int x) {
  int i;
  for (i = od_pozicije; i < n; i++)
    if (niz[i] == x)
      return 1;

  return 0;
}

/* Funkcija formira niz b tako sto u njega ubacuje sve elemente
   niza a koji se u tom nizu pojavljuju bar dva puta. */
int duplikati(int a[], int n, int b[]) {
  /* Promenljiva j je brojac elemenata rezultujuceg niza. */
  int i, j = 0;

  /* Obilazi se element po element niza a. Trenutni element je
     duplikat ukoliko se javlja jos neki put u nizu a. Dovoljno je
     gledati da li se nalazi iza tekuceg elementa jer ako se
     nalazi ispred, onda je on vec obradjen (i duplikat je
     detektovan). Element a[i] se dodaje u niz duplikata ako vazi:
     1. a[i] je duplikat 
     2. a[i] se ne nalazi u nizu duplikata
     Provera sadrzi(a, n, i+1, a[i]) proverava prvi uslov. 
     Provera !sadrzi(b, j, 0, a[i]) proverava drugi uslov. */
  for (i = 0; i < n; i++)
    if (sadrzi(a, n, i + 1, a[i]) && !sadrzi(b, j, 0, a[i])) {
      b[j] = a[i];
      j++;
    }

  /* Povratna vrednost funkcije je duzina niza b. */
  return j;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS], b[MAKS];
  int n_a, n_b;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n_a);
  if (n_a <= 0 || n_a > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje podataka o slicicama. */
  ucitaj(a, n_a);

  /* Popunjavanje niza b duplikatima niza a. */
  n_b = duplikati(a, n_a, b);

  /* Ispis rezultata. */
  printf("Elementi niza b: ");
  ispisi(b, n_b);

  exit(EXIT_SUCCESS);
}
