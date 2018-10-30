#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS 200

/* Funkcija koja racuna aritmeticku sredinu onih elemenata niza
   koji su deljivi sa 3. */
float artmeticka_sredina_3(int niz[], int n)
{
  int i, suma_deljivih_sa_tri = 0, broj_deljivih_sa_tri = 0;

  /* U petlji se proverava svaki element niza i za one koji su
     deljivi sa 3 uvecava se suma i odgovarajuci brojac. */
  for (i = 0; i < n; i++){
    if (niz[i] % 3 == 0) {
      suma_deljivih_sa_tri += niz[i];
      broj_deljivih_sa_tri++;
    }
  }

  return (float) suma_deljivih_sa_tri / broj_deljivih_sa_tri;
}


/* Funkcija koja racuna element koji je najblizi po vrednosti
   aritmetickoj sredini elemenata deljivih sa tri. */
int blizu_3(int a[], int n)
{
  float aritmeticka_sredina = artmeticka_sredina_3(a, n);
  int najblizi_po_vrednosti = a[0];
  
  /* Radi brzine izracunavanja pamti se razdaljina izmedju trenutno 
     najblizeg elementa i aritmeticke sredine. Izracunava se
     apsolutna vrednost razdaljine jer ona moze biti i negativna. */
  float razdaljina_najblizeg = fabs(aritmeticka_sredina - najblizi_po_vrednosti);
  float nova_razdaljina;
  int i;

  /* U petlji se ispituje svaki element niza i proverava se da li
     postoji neki koji je po vrednosti blizi aritmetickoj sredini. 
     Ako se naidje na takav element, azurira se vrednost najblizeg
     po vrednosti, kao i vrednost njegove razdaljine. */
  for (i = 1; i < n; i++) {
    nova_razdaljina = fabs(a[i] - aritmeticka_sredina);
    if (nova_razdaljina < razdaljina_najblizeg) {
      razdaljina_najblizeg = nova_razdaljina;
      najblizi_po_vrednosti = a[i];
    }
  }

  return najblizi_po_vrednosti;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int niz[MAKS], n, i;

  /* Ucitava se dimenzija niza. */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &niz[i]);

  /* Ispis rezultata. */
  printf("Trazeni broj je %d.\n", blizu_3(niz, n));

  exit(EXIT_SUCCESS);
}
