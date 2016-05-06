/*
   Napisati program koji ucitava broj elemenata niza (n<=100),
   zatim ucitava elemente niza i ispisuje:
   a) elemente niza koji se nalaze na parnim indeksima
   b) parne elemente niza
   
*/

#include <stdio.h>
#define MAX 100

int main()
{
  int a[MAX];
  int n;
  int i;


  printf("Unesi dimenziju niza:");
  scanf("%d", &n);

  if (n<1 || n>MAX)
  {
    printf("Nekorektan unos\n");
    return -1;
  }



  for (i=0; i<n; i++)
  {
    printf("a[%d]=",i);
    scanf("%d", &a[i]); /* ucitavamo jedan po jedan element niza */
  }

  printf("Elementi sa parnim indeksima:\n");
  for (i=0; i<n; i+=2)
    printf("a[%d]=%d\n",i,a[i]);

  printf("Parni elementi:\n");
  for (i=0; i<n; i++)
    if (a[i]%2==0)
      printf("a[%d]=%d\n",i,a[i]);
   
  
  return 0;
}
