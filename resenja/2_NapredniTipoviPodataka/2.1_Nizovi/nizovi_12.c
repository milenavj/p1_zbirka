#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n) {
  int i;
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* I nacin: Funkcija vraca poziciju najveceg elementa niza. 
   Prolazi se kroz niz i ako se naidje na element cija je
   vrednost veca od trenutno najveceg elementa (a[pozicija]), 
   vrsi se azuriranje pozicije trenutno najveceg. 
   int pozicija_najveceg(int a[], int n) {
     int i, pozicija = 0;
       for(i=1; i<n; i++)
         if(a[i] > a[pozicija])
           pozicija = i;  
     return pozicija;
   }

  Funkcija vraca broj parnih elemenata niza koji prethode
  maksimalnom elementu niza. 
  int prebrojavanje(int a[], int n) {
     int i;
     int pozicija_maksimuma = pozicija_najveceg(a,n);
     int broj_parnih = 0;
     for (i = 0; i < pozicija_maksimuma; i++) {
       if (a[i] % 2 == 0) {
	      broj_parnih++;
       }
     }   
     return broj_parnih;
   }
*/ 

/* II nacin:
   Zadatak se moze resiti i jednim prolazom kroz niz. Ideja je da 
   se paralelno radi pretraga maksimalnog elementa i prebrojavanje
   parnih elemenata koji mu prethode.

   Ovo moze da se uradi sa dva brojaca parnih elemenata: 
   1. broj_parnih - brojac koji cuva broj parnih elemenata 
   koji prethode trenutnom maksimumu
   2. broj_parnih_izmedju - brojac koji cuva broj parnih elemenata
   koji se nalaze iza trenutnog maksimuma

   Svaki put kada se maksimum azurira, na broj parnih se doda broj 
   parnih koji se prebrojao izmedju dva azuriranja, a
   broj_parnih_izmedju se vraca na nulu. */
int prebrojavanje_jednim_prolazom(int a[], int n) {
  int i;
  int pozicija_maksimuma = 0;
  int broj_parnih = 0;
  int broj_parnih_izmedju = 0;

  for (i = 0; i < n; i++) {
    if (a[i] > a[pozicija_maksimuma]) {
      pozicija_maksimuma = i;
      broj_parnih += broj_parnih_izmedju;
      broj_parnih_izmedju = 0;
    }

    if (a[i] % 2 == 0)
      broj_parnih_izmedju++;
  }

  return broj_parnih;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int n;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(a, n);

  /* Ispis rezultata. */
  /* I nacin: printf("%d\n", prebrojavanje(a, n)); */

  /* II nacin: Jednim prolazom kroz niz. */
  printf("Rezultat: %d\n", prebrojavanje_jednim_prolazom(a, n));

  exit(EXIT_SUCCESS);
}
