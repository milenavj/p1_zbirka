#include <stdio.h>

float zbir_reciprocnih(int n)
{
  float z=0;
  int i;
  for(i=1;i<=n;i++)
    z+=1.0/i;  /* da bismo dobili reciprocnu vrednost broja, vazno je da izbegnemo celobrojno deljenje dva cela broja */
  return z;    /* tako sto ce npr deljenik biti 1.0 umesto 1 */
}

int main()
{
  int n;
  printf("Unesi jedan pozitivan ceo broj:\n");
  scanf("%d", &n);
  printf("Zbir je %.2f\n", zbir_reciprocnih(n));
  /* povratna vrednost funkcije zbir_reciprocnih je float; funkciju mozemo pozvati u okviru 
     naredbe printf i umesto specifikatora %.2f bice ispisana povratna vrednost funkcije 
     zbir_reciprocnih zaokruzena na dve decimale */
  return 0;
}