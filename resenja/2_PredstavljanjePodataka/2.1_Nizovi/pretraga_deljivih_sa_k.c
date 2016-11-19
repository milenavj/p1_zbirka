#include <stdio.h>

#define MAX 100

int main()
{
  int brojevi[MAX];
  int n, i, k, indikator;

  /* Ucitava se dimenzija niza i proverava se njena ispravnost */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if(n<1 || n>MAX)
  {
    printf("Greska: Nedozvoljena vrednost!\n");
    return -1;
  }
  
  /* Ucitavaju se elementi niza */
  printf("Unesite elemente niza: ");
  for(i=0;i<n;i++)
    scanf("%d", &brojevi[i]);

  
  /* Ucitava se broj k i proverava se njegova ispravnost */
  printf("Unesite broj k: ");
  scanf("%d", &k);
  if(k == 0)
  {
    printf("Greska: Pogresan unos!\n");
    return -1;
  }
  
  /*
     Promenljiva koja cuva informaciju o tome da li je u nizu postojao element koji je deljiv brojem k.
     Inicijalna vrednost je 0.
  */

  indikator = 0;

  /*
    Ukoliko je element niza deljiv brojem k, indikator se postavlja na 1
    i ispisuje se indeks tog elementa.
  */

  for(i=0;i<n;i++){
    if(brojevi[i]%k == 0)
      {
        indikator = 1;
        printf("%d ",i);
      }
  }

  /* Ukoliko je indikator jednak nuli to znaci da ne postoji element u nizu koji je deljiv brojem k. */

  if(indikator == 0){
    printf("U nizu nema elemenata koji su deljivi brojem %d!\n",k);
  }
  
  
  return 0;
}
