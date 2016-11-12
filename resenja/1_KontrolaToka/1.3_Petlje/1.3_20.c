#include <stdio.h>

int main()
{
  int n;
  /* Ucitavaju se dva broja, broj i sledbenik, i proverava se da li 
     su razlicitog znaka. */
  double broj, sledbenik;
  /* Brojac. */
  int i;
  int broj_promena = 0;

  printf("Unesite broj n ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Neispravan unos.\n");
    return -1;
  }

  /* Prvo se proveara da li uopste ima unosa, i ako unosa nema,
     ispisuje se odgovarajuca poruka i izlazi iz programa. */
  if (n == 0) {
    printf("Broj promena je 0.\n");
    return 0;
  }

  printf("Unesite brojeve: ");
  /* Pre petlje ucitava se jedan broj, a u petlji se ucitava njegov 
     sledbenik i proverava se da li su razlicitog znaka. */
  scanf("%lf", &broj);

  /* Kako je vec jedan broj unesen, brojac se postavlja na 1, a ne
     na 0. */
  for (i = 1; i < n; i++) {
    /* Ucitava se sledbenik. */
    scanf("%lf", &sledbenik);

    /* Ako su razlicitog znaka proizvod je manji od 0. */
    if (sledbenik * broj < 0)
      broj_promena++;
    /* Problem je ako je proizvod jednak 0. Tada mora provera da li 
       je jedan od brojeva negativan jer tada postoji promena
       znaka. */
    else if (sledbenik * broj == 0 && (sledbenik < 0 || broj < 0))
      broj_promena++;

    /* Tekuci sledbenik postaje tekuci broj, a u sledecoj iteraciji 
       petlje se ucitava sledeci sledbenik. */
    broj = sledbenik;
  }

  printf("Broj promena je %d.\n", broj_promena);

  return 0;
}
