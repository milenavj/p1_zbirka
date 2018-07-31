#include <stdio.h>
#include <stdlib.h>

/* Funkcija za realan broj x i ceo broj n odredjuje vrednost stepena x^n. */
float stepen(float a, int b)
{
  float s=1;
  int i, abs_b = abs(b);
  
  for(i=0;i<abs_b;i++)
    s=s*a;

/* Ukoliko je izlozilac b negativan, prvo se izracuna a^|b|, a vraca se reciprocnu vrednost izracunatog stepena. */
  return b>0 ? s : 1/s;   
}

int main()
{
  int n;
  float x;
  float s;

  printf("Unesi jedan realan i jedan ceo broj:");  
  scanf("%f%d",&x,&n);
  
  s = stepen(x,n);
      
  printf("%f^%d=%f\n",x,n,s);

  return 0;
}
