#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int x, tekuca_vrednost;
  
  /* Za cuvanje vrednosti faktorijela se koristi tip unsigned long
     jer izracunata vrednost moze da bude jako veliki broj. */
  unsigned long faktorijel;

  /* Ucitava se vrednost broja x. */
  printf("Unesite pozitivan broj: ");
  scanf("%d", &x);

  /* Vrsi se provera ispravnosti ulaza. */
  if (x < 0) {
    printf("Greska: neispravan unos..\n");
    return -1;
  }

  if (x >= 22) {
    printf("Pri racunanju %d! ce doci do prekoracenja.\n", x);
    return -1;
  }

  /* Tekuca vrednost uzima vrednosti x, x-1, x-2, ..., 2. 
     Na pocetku se inicijalizuje na x, a zatim se u svakoj
     iteraciji umanjuje za 1. */
  tekuca_vrednost = x;
  
  /* Inicijalizacija vrednosti faktorijela. */
  faktorijel = 1;
  
  /* Racuna se vrednost faktorijela tako sto se trenutni rezultat
     u svakoj iteraciji mnozi sa promenljivom cija vrednost krece 
     od x, a zatim se u svakoj iteraciji umanjuje za 1. */
  while (tekuca_vrednost > 1) {
    faktorijel = faktorijel * tekuca_vrednost;
    tekuca_vrednost--;
  }

  /* Ispis rezultata. */
  printf("%d! = %lu\n", x, faktorijel);

  return 0;
}
