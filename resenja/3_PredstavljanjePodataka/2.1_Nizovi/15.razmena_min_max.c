#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n)
{
  int i;  
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija ispisuje elemente niza dimenzije n. */
void ispisi(int a[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

/* Funkcija razmenjuje najmanji i najveci element niza. */
void razmeni_min_max(int brojevi[], int n)
{
  int i;  
  /* Najvecim, kao i najmanjim elementom niza proglasava se nulti
     element niza. Pozicije najveceg i najmanjeg elementa se
     postavljaju na 0. */
  int najveci = brojevi[0];
  int najmanji = brojevi[0];
  int pozicija_najveceg = 0;
  int pozicija_najmanjeg = 0;

  /* U prolazu kroz niz trazi se najveci i najmanji element i
     pamte se njihove pozicije. */
  for (i = 1; i < n; i++) 
  {
    if (brojevi[i] > najveci) 
    {
      najveci = brojevi[i];
      pozicija_najveceg = i;
    }

    if (brojevi[i] < najmanji) 
    {
      najmanji = brojevi[i];
      pozicija_najmanjeg = i;
    }
  }

  /* Zamenjuju se elementi na pozicijama pozicija_najmanjeg i pozicija_najveceg. */
  brojevi[pozicija_najveceg] = najmanji;
  brojevi[pozicija_najmanjeg] = najveci;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int brojevi[MAKS];
  int n;

  /* Ucitava se dimenzija niza i vrsi se provera 
     ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  ucitaj(brojevi, n);

  /* Razmenjuju se najmanji i najveci element. */
  razmeni_min_max(brojevi, n);

  /* Ispisuje se rezultujuci niz. */
  ispisi(brojevi, n);

  exit(EXIT_SUCCESS);
}
