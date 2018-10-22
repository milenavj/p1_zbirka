#include<stdio.h>
#include<stdlib.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int t, x, i;
  int ukupan_prihod, ukupan_rashod, ukupan_rashod_abs;

  /* Ucitava se vrednost broja t. */
  printf("Unesite broj t:");
  scanf("%d", &t);

  /* Vrsi se provera ispravnosti ulaza. */
  if (t < 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  } 
  else if( t == 0) {
    printf("Nema evidentiranih transakcija.");
    return 0;
  }

  /* Inicijalizacija suma. */
  ukupan_prihod = 0;
  ukupan_rashod = 0;

  /* Ucitavanje transakcija i izracunavanje suma. */
  printf("Unesite transakcije: ");
  i = 0;
  while (i < t) {
    /* Ucitava se jedna transakcija. */
    scanf("%d", &x);

    /* Dodaje se na odgovarajucu sumu. */
    if (x < 0)
      ukupan_rashod += x;
    else
      ukupan_prihod += x;

    /* Uvecava se brojac. */
    i++;
  }

  /* Ispis rezultata. */
  printf("Prihod: %d\n", ukupan_prihod);
  printf("Rashod: %d\n", ukupan_rashod);
  
  ukupan_rashod_abs = abs(ukupan_rashod);
  if(ukupan_prihod >= ukupan_rashod_abs)
    printf("Zarada: %d\n", ukupan_prihod - ukupan_rashod_abs);
  else
    printf("Gubitak: %d\n", ukupan_rashod_abs - ukupan_prihod);
    
  return 0;
}
