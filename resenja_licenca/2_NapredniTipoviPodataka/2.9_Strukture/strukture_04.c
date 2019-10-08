/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAKS_IME 21
#define MAKS_GRADOVA 50
#define DONJA_GRANICA 3
#define GORNJA_GRANICA 8

/* Struktura koja opisuje grad. */
typedef struct {
  char ime_grada[MAKS_IME];
  float temperatura;
} Grad;

/* Funkcija ucitava podatke o gradovima u niz. */
void ucitaj(Grad gradovi[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("Unesite grad i temperaturu: ");
    scanf("%s %f", gradovi[i].ime_grada, &gradovi[i].temperatura);
  }
}

/* Funkcija ispisuje gradove sa idealnom temperaturom za klizanje u 
   decembru. */
void ispisi(Grad gradovi[], int n) {
  int i;

  printf("Gradovi sa idealnom temperaturom za "
         "klizanje u decembru:\n");
  for (i = 0; i < n; i++) {
    if (gradovi[i].temperatura >= DONJA_GRANICA &&
        gradovi[i].temperatura <= GORNJA_GRANICA) {
      printf("%s\n", gradovi[i].ime_grada);
    }
  }
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n;
  Grad gradovi[MAKS_GRADOVA];

  /* Ucitavanje broja gradova i provera ispravnosti ulaza. */
  printf("Unesite broj gradova: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS_GRADOVA) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje podataka o gradovima. */
  ucitaj(gradovi, n);

  /* Ispis rezultata. */
  ispisi(gradovi, n);

  exit(EXIT_SUCCESS);
}
