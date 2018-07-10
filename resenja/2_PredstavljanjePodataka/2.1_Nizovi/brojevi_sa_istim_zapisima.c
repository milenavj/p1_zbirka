#include <stdio.h>

#define BROJ_CIFARA 10

/* Analiziraju se cifre broja i smestaju u odgovarajuci niz. */
void analiza_cifara(int broj, int niz[])
{
  int c;

  /* Niz predstavlja brojace za cifre broja.
     Na pocetku se ovi nizovi inicijalizuju nulama. 
  */
  for(i=0;i<BROJ_CIFARA;i++)
      niz[i] = 0;
  
  do
  {
    c = broj%10;
    niz[c]++;
    broj /= 10;
  }
  while(broj);
}

int main()
{
  char c;
  /* Niz cifrex predstavlja brojace za cifre broja x. 
     Niz cifrey predstavlja brojace za cifre broja y.
  */
  int cifrex[BROJ_CIFARA], cifrey[BROJ_CIFARA];
  int x, y, i, indikator;

  /* Ucitavaju se brojevi x i y */
  printf("Unesite dva broja: ");
  scanf("%d%d", &x, &y);

  /* Za slucaj da su unete vrednosti negativne, posmatra se njihova apsolutna vrednost. 
   Ovo je opravdano iz razloga sto se brojevi x i -x zapisuju istim ciframa. */
  x=abs(x);
  y=abs(y);

  analiza_cifara(x, cifrex);
  analiza_cifara(y, cifrey);
 

  /* Promenljiva indikator sluzi za pracenje da li su oba broja sastavljena od istih cifara. */
  indikator = 1;
 
  for(i=0;i<BROJ_CIFARA;i++){
    /* Ako se broj pojavljivanja cifre i u zapisu broja x razlikuje od broja pojavljivanja cifre i u 
     zapisu broja y, brojevi se ne zapisuju istim ciframa. Zato se vrednost indikatora moze postaviti na 
     0 i prekinuti dalje uporedjivanje broja pojavljivanja. */
    if(cifrey[i] != cifrex[i])
    {
     indikator = 0;
     break;
    }
  }

    /* Ako je vrednost promenljive indikator ostala 1, to znaci da u petlji nije pronadjena cifra
    koja se ne pojavljuje isti broj puta u zapisima brojeva x i y. Zato se moze zakljuciti da se brojevi
    zapisuju istim ciframa. */
  if(indikator)
    printf("Brojevi se zapisuju istim ciframa!\n");
  else
    printf("Brojevi se ne zapisuju istim ciframa!\n");

  
  return 0;
}
