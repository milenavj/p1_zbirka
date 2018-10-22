#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, tekuca_vrednost;
  
  /* Za cuvanje vrednosti faktorijela se koristi tip unsigned long
     jer izracunata vrednost moze da bude jako veliki broj. */
  unsigned long faktorijel;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n < 0) {
    printf("Greska: neispravan unos..\n");
    return -1;
  }

  if (n >= 22) {
    printf("Pri racunanju %d! ce doci do prekoracenja.\n", n);
    return -1;
  }

  /* Tekuca vrednost uzima vrednosti n, n-1, n-2, ..., 2. 
     Na pocetku se inicijalizuje na n, a zatim se u svakoj
     iteraciji umanjuje za 1. */
  tekuca_vrednost = n;
  
  /* Inicijalizacija vrednosti faktorijela. */
  faktorijel = 1;
  
  /* Racuna se vrednost faktorijela tako sto se trenutni rezultat
     u svakoj iteraciji mnozi sa promenljivom cija vrednost krece 
     od n, a zatim se u svakoj iteraciji umanjuje za 1. */
  while (tekuca_vrednost > 1) {
    faktorijel = faktorijel * tekuca_vrednost;
    tekuca_vrednost--;
  }

  /* Ispis rezultata. */
  printf("%d! = %lu\n", n, faktorijel);

  return 0;
}
