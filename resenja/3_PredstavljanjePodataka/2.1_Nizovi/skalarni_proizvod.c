#include <stdio.h>

/* Predprocesorska direktiva kojom se definise maksimalni broj elemenata niza. */
#define MAX 100

int main()
{
  int a[MAX];
  int b[MAX];
  int n;
  int i;
  int skalarni_proizvod;

  
  /* Ucitava se dimenzija vektora i proverava njena ispravnost. */
  printf("Unesite dimenziju vektora: ");
  scanf("%d", &n);
  if (n<1 || n>100)  
  {
    printf("Nedozvoljena vrednost!\n");
    return -1;
  }
       
  /* Ucitavaju se koordinate vektora. */
  printf("Unesite koordinate vektora a: ");
  for (i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }
  
  printf("Unesite koordinate vektora b: ");
  for (i=0; i<n; i++)
  {
    scanf("%d", &b[i]);
  }
  
  /* Izracunava se skalarni proizvod po zadataj formuli. */
  skalarni_proizvod=0;

  for (i=0; i<n; i++)
    skalarni_proizvod = skalarni_proizvod + a[i]*b[i];
  
  /* I ispisuje se njegova vrednost. */
  printf("Skalarni proizvod vektora a i b: %d\n",skalarni_proizvod);     
 
  return 0;
}
