#include <stdio.h>

#define MAX 100

int main()
{
  int brojevi[MAX];
  int n, i, poz_max, poz_min, max, min, tmp;

  /* Ucitava se dimenzija niza i proverava se njena ispravnost. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if(n<1 || n>MAX)
  {
    printf("Greska: Nedozvoljena vrednost!\n");
    return -1;
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:\n");
  for(i=0;i<n;i++)
    scanf("%d", &brojevi[i]);

  /* Maksimalnim tj. minimalnim elementom niza proglasava se nulti element niza. Pozicije maksimalnog tj. minimalnog elementa se postavljaju na 0. */
  max = brojevi[0];
  min = brojevi[0];
  poz_max = 0;
  poz_min = 0;

  /* U prolazu kroz niz trazi se maksimalni i minimalni element i pamte se njihove pozicije. */
  for(i=1;i<n;i++)
  {
    if(brojevi[i] > max)
    {
      max = brojevi[i];
      poz_max = i;
    }

    if(brojevi[i] < min)
    {
      min = brojevi[i];
      poz_min = i;
    }
  }

  /* Zamenjuju se elementi na pozicijama poz_min i poz_max. */
  tmp = max;
  brojevi[poz_max] = min;
  brojevi[poz_min] = tmp;

  /* Ispisuje se rezultujuci niz. */
  for(i=0;i<n;i++)
    printf("%d ", brojevi[i]);
  printf("\n");


  return 0;
}
