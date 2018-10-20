#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, i, broj_promena = 0;
  double prethodni, trenutni;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  printf("Unesite brojeve: ");
  /* Provera promene znaka se vrsi za svaka dva susedna uneta 
     broja. Prvi broj se ucitava pre petlje i smesta se u 
     promenljivu prethodni. Zatim se u petlji ucitava drugi i
     njihov znak se poredi. Postupak se ponavlja za sve parove,
     tako sto se uvek na kraju petlje poslednji ucitani broj
     postavi da bude prethodni za sledecu iteraciju. */
  scanf("%lf", &prethodni);

  /* Kako je vec jedan broj unesen, brojac se postavlja na 1, a ne
     na 0. */
  for (i = 1; i < n; i++) {
    
    /* Ucitava se broj. */
    scanf("%lf", &trenutni);

    /* Proverava se da li je doslo do promene znaka izmedju
       prethodnog i trenutnog. Oni su razlicitog znaka ako vazi:
       1. da im je proizvod negativan ILI 
       2. da im je proizvod nula, a jedan od njih je negativan. */
    if (prethodni * trenutni < 0)
      broj_promena++;
    else if (prethodni * trenutni == 0 && 
      (prethodni < 0 || trenutni < 0))
      broj_promena++;

    /* Trenutni broj postaje prethodni za sledecu iteraciju. */
    prethodni = trenutni;
  }

  /* Ispis rezultata. */
  printf("Broj promena je %d.\n", broj_promena);

  return 0;
}
