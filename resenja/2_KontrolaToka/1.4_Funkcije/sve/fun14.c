#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Funkcija koja uklanja cifru sa pozicije p iz broja n. 
   Cifra jedinica ima poziciju 1, desetica 2, itd.*/
int ukloni(int n, int p)
{
  int znak, tezina_pozicije, levi_deo, desni_deo;
  
  /* Pamti se znak broja. */
  znak = n < 0 ? 1 : -1;
  
  /* Uzima se apsolutna vrednost. */
  n = abs(n);
  
  /* Racuna se tezina prosledjene pozicije. */
  tezina_pozicije = pow(10, p-1);
  
  /* Broj se deli na dva dela - deo levo od cifre koja se izbacuje
     i deo desno od cifre koja se izbacuje. */
  levi_deo = n/(10*tezina_pozicije);
  desni_deo = n%tezina_pozicije;
  
  /* Povratna vrednost funkcije se dobija spajanjem levog i desnog
     dela i mnozenjem sa znakom pocetnog broja. */
  return znak * (levi_deo*10 + desni_deo);
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int broj, p;

  /* Ucitava se vrednost pozicije. */
  printf("Unesite poziciju: ");
  scanf("%d", &p);
  
  /* Vrsi se provera ispravnosti ulaza. */
  if(p <= 0)
  {
    printf("Greska: neispravan unos.\n");
    return -1;
  }
  
  /* Ucitavaju se brojevi dok se ne unese nula i za svaki
     ucitani broj se ispisuje broj koji se dobije uklanjanjem
     cifre koja se nalazi na poziciji p. */
  while (1) {
    printf("Unesite broj: ");
    scanf("%d", &broj);

    if (broj == 0)
      break;

    printf("%d\n", ukloni(broj, p));
  }

  return 0;
}
