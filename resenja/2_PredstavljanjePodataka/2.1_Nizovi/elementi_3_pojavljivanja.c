#include <stdio.h>

#define MAX 100

/* Funkcija koja vraca broj pojavljivanja broja x u nizu */
int broj_pojavljivanja(int niz[], int n, int x)
{
  int i;
  
  /* Broj pojavljivanja broja x */
  int brojac = 0;

  /* Obilazi se element po element niza */
  for(i=0;i<n;i++){
    /* Ukoliko je tekuci element jednak trazenom broju */
    if(niz[i] == x){
      /* Uvecava se broj pojavljivanja */
      brojac++;
    }
  }

  /* Vraca se izracunata vrednost */
  return rezultat;
}

int main()
{
  /* Niz elemenata koje zadaje korisnik */
  int a[MAX];
  
  /* Niz elemenata koji se pojavljuju tri puta */
  int b[MAX];
  
  int i, j, n, n_b;

  /* Ucitava se broj elemenata korisnickog niza i proverava se njegova ispravnost. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if(n<1 || n>MAX)
  {
    printf("Greska: Nedozvoljena vrednost!\n");
    return -1;
  }

  /* Ucitavaju se elementi korisnickog niza. */
  printf("Unesite elemente niza a: ");
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);

  /* Parametar j je brojac elemenata rezultujuceg niza b. */
  j = 0;
  
  /* Obilazi se element po element niza a. */
  for(i=0;i<n;i++)
  {
    /* Ukoliko se tekuci element pojavljuje vise od dva puta u nizu a i nije upisan u niz b koji trenutno ima j elemenata, dodaje se u niz b na poziciju j i uvecava se broj elemenata niza b. */
    if(broj_pojavljivanja(a, n, a[i])>=3 && broj_pojavljivanja(b, j, a[i])==0)
    {
      b[j] = a[i];
      j++;
    }
  }
  
  /* Ispisuje se rezultujuci niz b, broj elemenata u nizu b je j. */
  n_b = j;
  for(i=0;i<n_b;i++)
    printf("%d ", b[i]);
  printf("\n");

  return 0;
}
