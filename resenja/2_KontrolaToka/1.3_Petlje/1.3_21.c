#include <stdio.h>

int main()
{
  /* Broj artikala. */
  int n;
  /* Brojac. */
  int i;
  /* Cena trenutno unetnog artikla. */
  float cena;
  /* Minimalna cena. */
  float min_cena;

  printf("Unesite broj artikala:");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Neispravan unos\n");
    return -1;
  }

  /* Prva cena se unosi iznad petlje kako bi bio njegova vrednost
     bila dodeljena promenljivoj min_cena. Neophodno je da
     promenljiva min bude inicijalizovana pre ulaska u petlju da bi 
     uslov x<min mogao da bude ispitan u prvoj iteraciji. */
  printf("Unesite cenu artikala:");
  scanf("%f", &cena);
  /* Proveravamo da li je cena isprano uneta vrednost. */
  if (cena <= 0) {
    printf("Cena ne moze biti negativna.\n");
    return -1;
  }

  min_cena = cena;
  i = 0;
  while (i < n - 1) {
    scanf("%f", &cena);

    if (cena <= 0) {
      printf("Cena ne moze biti negativna.\n");
      return -1;
    }

    /* Provera da li je uneta cena manja od tekuce minimalne cene. */
    if (cena < min_cena)
      min_cena = cena;
    i++;
  }

  printf("Minimalna cena je: %f\n", min_cena);

  return 0;
}
