#include <stdio.h>

#define MAX 100

int main()
{
  int brojevi[MAX];
  int n, i, poz_max, poz_min, max, min, tmp;

  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);

  if(n<1 || n>100)
  {
    printf("Greska: pogresan unos!\n");
    return 0;
  }

  printf("Unesite elemente niza:\n");
  for(i=0;i<n;i++)
    scanf("%d", &brojevi[i]);

  /*
    Maksimum tj. minimum pre ulaska u petlju postavimo da budu prvi element niza.
    Pozicije maksimuma tj. minimuma postavimo na 0.
  */
  max = brojevi[0];
  min = brojevi[0];
  poz_max = 0;
  poz_min = 0;

  /*
    Pronadjemo maksimalni tj. minimalni element tako sto u petlji
    prodjemo kroz sve elemente i ukoliko naletimo na element veci od maksimuma
    tj. manji od minimuma, promenimo tako da sada maksimum tj. minimum budu taj element
    i promenimo njihove pozicije.
  */
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

  /*
    Zamenimo minimalni i maksimalni element na pozicijama poz_min i poz_max.
    Koristimo pomocnu promenljivu tmp kako bismo sacuvali vrednost maksimalnog elementa.
  */
  tmp = max;
  brojevi[poz_max] = min;
  brojevi[poz_min] = tmp;

  for(i=0;i<n;i++)
    printf("%d ", brojevi[i]);

  return 0;
}
