#include <stdio.h>
#include <stdlib.h>

#define BROJ_CIFARA 10

/* Funkcija inicijalizuje niz postavljajuci vrednosti svih
   elemenata na nulu. */
void inicijalizuj(int niz[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    niz[i] = 0;
}

/* Funkcija izdvaja cifru po cifru broja i uvecava odgovarajuci
   element niza koji odgovara brojacu za tu cifru. Na primer,
   za broj=1123, po zavrsetku ove funkcije niz[1] ce imati vrednost
   2 jer se cifra 1 pojavljuje 2 puta, niz[2] i niz[3] ce imati
   vrednost 1, a svi ostali elementi niza ce imati vrednost 0. */
void analiza_cifara(int broj, int niz[])
{
  int c;

  /* Inicijalizacia svih brojaca na nule. */
  inicijalizuj(niz, BROJ_CIFARA);

  /* Uvecavanje odgovarajucih brojaca. */
  do {
    c = broj % 10;
    niz[c]++;
    broj /= 10;
  }
  while (broj);
}

int main()
{
  /* Niz cifrex predstavlja brojace za cifre broja x. Niz cifrey
     predstavlja brojace za cifre broja y. */
  int cifrex[BROJ_CIFARA], cifrey[BROJ_CIFARA];
  int x, y, i, indikator;

  /* Ucitavaju se brojevi x i y. */
  printf("Unesite dva broja: ");
  scanf("%d%d", &x, &y);

  /* Za slucaj da su unete vrednosti negativne, posmatra se njihova 
     apsolutna vrednost. Ovo je opravdano iz razloga sto se brojevi 
     x i -x zapisuju istim ciframa. */
  x = abs(x);
  y = abs(y);

  /* Popunjavaju se nizovi sa brojacima cifara. */
  analiza_cifara(x, cifrex);
  analiza_cifara(y, cifrey);

  /* Promenljiva indikator sluzi za pracenje da li su oba broja
     sastavljena od istih cifara. */
  indikator = 1;

  for (i = 0; i < BROJ_CIFARA; i++) {
    /* Ako se broj pojavljivanja cifre i u zapisu broja x razlikuje 
       od broja pojavljivanja cifre i u zapisu broja y, brojevi se
       ne zapisuju istim ciframa. Zato se vrednost indikatora moze
       postaviti na 0 i prekinuti dalje uporedjivanje broja
       pojavljivanja. */
    if (cifrey[i] != cifrex[i]) {
      indikator = 0;
      break;
    }
  }

  /* Ako je vrednost promenljive indikator ostala 1, to znaci da u
     petlji nije pronadjena cifra koja se ne pojavljuje isti broj
     puta u zapisima brojeva x i y. Zato se moze zakljuciti da se
     brojevi zapisuju istim ciframa. */
  if (indikator)
    printf("Brojevi se zapisuju istim ciframa.\n");
  else
    printf("Brojevi se ne zapisuju istim ciframa.\n");


  exit(EXIT_SUCCESS);
}
