#include <stdio.h>
#include <stdlib.h>

/* Funkcija proverava da li se neka cifra nalazi u zapisu celog
   broja i ako se nalazi vraca odgovarajucu poziciju (tj. njenu
   tezinu koja je neki stepen broja 10), a u suprotnom vraca -1. 
   Na primer, za broj = 1234 i cifra = 2, funckija vraca 100. */
int pozicija_cifre(int broj, int cifra)
{
  int tezina_pozicije = 1;
  
  while(broj)
  {
    if(broj%10 == cifra)
      return tezina_pozicije;
    
    tezina_pozicije *= 10;
    broj /= 10;
  }
  
  return -1;
}

/* Funkcija iz zapisa broja izbacuje cifru koja se nalazi
   na prosledjenoj poziciji. Pozicija je stepen broja 10. 
   Na primer, za x=1234 i pozicija = 10, treba da se izbaci 3.
   levi_deo = 1234/(10*10) = 12
   desni_deo = 1234%10 = 4
   Povratna vrednost je 12*10 + 4 = 124. */
int izbaci_cifru(int broj, int pozicija)
{    
  int levi_deo = broj/(pozicija*10);
  int desni_deo = broj%pozicija;
  return levi_deo*10 + desni_deo;
}

/* Funkcija proverava da li su dva cela broja napisana pomocu istih 
   cifara. Vraca 1 ako je uslov ispunjen, a 0 u suprotnom. */
int zapis(int x, int y)
{
  int pozicija;
  x = abs(x);
  y = abs(y);

  while (x) 
  {
    /* Proverava se da li y sadrzi poslednju cifru broja x. */
    pozicija = pozicija_cifre(y, x % 10);
    
    /* Ako ne sadrzi, x i y se ne zapisuju pomocu istih cifara. */
    if(pozicija == -1)
      return 0;
    
    /* Ako sadrzi, iz x se izbacuje poslednja cifra, a iz y se
       izbacuje ista ta cifra (koja se nalazi na pronadjenoj
       poziciji. */
    x /= 10;
    y = izbaci_cifru(y, pozicija);
  }

  /* Na kraju petlje iz x su izbacene sve cifre, a vazi da su
     brojevi zapisani pomocu istih cifara samo ukoliko ni u y
     nema preostalih cifara. */
  return y == 0;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int x, y;
  
  /* Ucitavaju se vrednosti x i y. */
  printf("Unesite dva cela broja: ");
  scanf("%d%d", &x, &y);

  /* U zavisnosti od povratne vrednosti napisane funckija, 
     ispisuje se odgovarajuca poruka. */
  if (zapis(x, y))
    printf("Uslov je ispunjen.\n");
  else
    printf("Uslov nije ispunjen.\n");

  return 0;
}
