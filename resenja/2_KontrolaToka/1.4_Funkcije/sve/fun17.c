#include <stdio.h>
#include <stdlib.h>

/* Funkcija proverava da li su cifre broja naizmenicno parne i
   neparne. Ako je uslov ispunjen vraca 1, u suprotnom vraca 0. */
int par_nepar(int x)
{
  int prethodna_cifra, tekuca_cifra;
  x = abs(x);

  /* Poslednja cifra broja se izdvaja van petlje da bi u petlji
     moglo da se vrsi poredjenje. */
  prethodna_cifra = x % 10;
  x /= 10;

  while (x) {
    tekuca_cifra = x % 10;

    /* Ukoliko su uzastopne cifre iste parnosti, uslov nije
       ispunjen, rad petlje i funkcije se prekida i vraca se 0. */
    if (tekuca_cifra % 2 == prethodna_cifra % 2)
      return 0;

    /* Tekuca cifra postaje prethodna cifra za narednu iteraciju. */
    prethodna_cifra = tekuca_cifra;
    x /= 10;
  }

  /* Sve uzastopne cifre su razlicite parnosti jer ni jednom u
     petlji uslov da su cifre iste parnosti nije bio ispunjen. */
  return 1;
}


int main()
{
  /* Deklaracija potrebne promenljive. */
  int n;
  
  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* U zavisnosti od povratne vrednosti napisane funkcije, vrsi
     se ispis odgovarajuce poruke. */
  if (par_nepar(n))
    printf("Broj ispunjava uslov.\n");
  else
    printf("Broj ne ispunjava uslov.\n");

  return 0;
}
