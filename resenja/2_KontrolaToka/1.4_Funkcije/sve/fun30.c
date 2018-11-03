#include<stdio.h>

/* Funkcija koja stampa n zvezdica za kojima sledi znak za novi
   red. */
void stampaj_zvezdice(int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("*");

  printf("\n");
}

/* Funkcija koja crta grafikon. */
void grafikon_h(int a, int b, int c, int d)
{
  /* Prvo se ispisuje a zvezdica. */
  stampaj_zvezdice(a);

  /* Postupak se ponavlja za vrednosti b, c i d. */
  stampaj_zvezdice(b);
  stampaj_zvezdice(c);
  stampaj_zvezdice(d);
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a, b, c, d;

  /* Ucitavaju se vrednosti a,b,c,d. */
  printf("Unesite brojeve: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);

  /* Vrsi se provera ispravnosti ulaza i ispisuje se rezultat. */
  if (a < 0 || b < 0 || c < 0 || d < 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  } else {
    grafikon_h(a, b, c, d);
  }

  return 0;
}