#include <stdio.h>

#define MAX 100

/*
  Funkcija koja vraca broj pojavljivanja broja x u nizu.
*/

int broj_pojavljivanja(int niz[], int n, int x)
{
  int i, rezultat = 0;

  /*
    Kada naidjemo na element niza koji je jednak broju x, povecamo brojac rezultat.
  */
  for(i=0;i<n;i++)
    if(niz[i] == x)
      rezultat++;

  return rezultat;
}

int main()
{
  int a[MAX], b[MAX];
  int i, j, n, n_b;

  printf("Unesite broj n: ");
  scanf("%d", &n);

  if(n<1 || n>100)
  {
    printf("Greska: pogresan unos!\n");
    return -1;
  }

  printf("Unesite elemente niza a: ");
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);

  /*
    Brojac elemenata rezultujuceg niza b.
  */
  j = 0;
  for(i=0;i<n;i++)
  {
    /*
      Ukoliko se element niza pojavljuje tacno tri puta i ne postoji u nizu b koji trenutno ima j elemenata
      (nismo ga jos uvek dodali) dodajemo ga u niz b i povecavamo brojac j.
    */
    if(broj_pojavljivanja(a, n, a[i])==3 && broj_pojavljivanja(b, j, a[i])==0)
    {
      b[j] = a[i];
      j++;
    }
  }
  /*
    Broj elemenata u nizu b je j.
  */
  n_b = j;

  for(i=0;i<n_b;i++)
    printf("%d ", b[i]);

  return 0;
}
