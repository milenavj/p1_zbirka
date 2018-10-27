#include<stdio.h>

/* Funkcija koja iscrtava romb. */
void romb(int n)
{
  int i, j;

  /* Petlja iscrtava liniju po liniju romba. */
  for (i = 0; i < n; i++) {
    /* U svakoj liniji prvo se ispisuje n-i-1 razmaka. */
    for (j = 0; j < n - i - 1; j++)
      printf(" ");

    /* Ispisuje se n zvezdica. */
    for (j = 0; j < n; j++)
      printf("*");

    /* Ispisuje se novi red. */
    printf("\n");
  }

}

int main()
{
  /* Deklaracija potrebne promenljive. */
  int n;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n <= 0){
    printf("Greska: neispravan unos.\n");
    return -1;
  }
  
  /* Iscrtava se romb. */
  romb(n);

  return 0;
}
