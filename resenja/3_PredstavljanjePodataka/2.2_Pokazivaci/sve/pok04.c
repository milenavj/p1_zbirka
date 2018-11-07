#include <stdio.h>
#include <stdlib.h>

int kolicnik_ostatak(int a, int b, int* pk, int* po)
{
  if(b == 0)
    return 0;
    
  *pk = a/b;
  *po = a%b;
  return 1;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a, b, kolicnik, ostatak;
  
  /* Ucitavaju se vrednosti a i b. */
  printf("Unesite brojeve: ");
  scanf("%d%d", &a, &b);
  
  /* Ispis rezultata. */
  if(kolicnik_ostatak(a, b, &kolicnik, &ostatak)){
    printf("Kolicnik: %d\n", kolicnik);
    printf("Ostatak: %d\n", ostatak);
  }
  else
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }
  
  exit(EXIT_SUCCESS);
}