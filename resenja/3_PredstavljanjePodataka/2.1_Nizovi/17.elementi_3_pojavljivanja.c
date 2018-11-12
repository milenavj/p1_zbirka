#include <stdio.h>
#include <stdlib.h>

#define MAKS 600

/* Funkcija koja ucitava dimenziju i elemente niza.
   Kao povratnu vrednost vraca ucitanu dimenziju. */
int ucitaj(int niz[])
{
  int i, n;
  /* Ucitava se dimenzija niza i vrsi se provera 
     ispravnosti ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza a: ");
  for (i = 0; i < n; i++)
    scanf("%d", &niz[i]);
  
  return n;
}

/* Funkcija koja ispisuje elemente niza. */
void ispisi(int niz[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

/* Funkcija koja proverava da li niz a dimenzije n sadrzi zadatu
   vrednost x. Pretraga se vrsi od prosledjene pozicije. */
int sadrzi(int niz[], int n, int od_pozicije, int x)
{
  int i;
  for (i = od_pozicije; i < n; i++)
    if (niz[i] == x)
      return 1;

  return 0;
}

int duplikati(int a[], int n, int b[])
{
  /* Promenljiva j je brojac elemenata rezultujuceg niza. */
  int i, j = 0;

  /* Obilazi se element po element niza a. 
     Trenutni element je duplikat ukoliko se javlja jos neki put u
     nizu a. Dovoljno je gledati da li se nalazi iza tekuceg 
     elementa jer ako se nalazi ispred, onda je on vec obradjen 
     (i duplikat je detektovan). 
     Element a[i] se dodaje u niz duplikata ako vazi:
     1. a[i] je duplikat
     2. a[i] se ne nalazi u nizu duplikata 
     Provera sadrzi(a, n, i+1, a[i]) proverava prvi uslov. 
     Provera !sadrzi(b, j, 0, a[i]) proverava drugi uslov. */
  for (i = 0; i < n; i++) 
  {
    if (sadrzi(a, n, i+1, a[i]) && !sadrzi(b, j, 0, a[i])) 
    {
      b[j] = a[i];
      j++;
    }
  }
  
  /* Povratna vrednost funkcije je duzina niza b. */
  return j;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS], b[MAKS];
  int na, nb;

  /* Ucitavaju se podaci o slicicama. */
  na = ucitaj(a);

  /* Niz b se popunjava duplikatima iz a. */
  nb = duplikati(a, na, b);

  /* Ispis rezultata. */
  ispisi(b, nb);

  exit(EXIT_SUCCESS);
}
