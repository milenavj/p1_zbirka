#include <stdio.h>
#include <math.h>

void ispis(float x, float y, int n) /* funkcija nema povratnu vrednost; zbog toga je povratni tip void */
{
  float i;
  float korak=(y-x)/(n-1);
  
  for(i=x;i<=y;i+=korak)
    printf("%.4f ", sin(i));
  
  printf("\n");
    
}

int main()
{
  float a,b;
  int n;
  float t;
  printf("Unesi dva realna broja:");
  scanf("%f%f",&a,&b);
  printf("Unesi jedan prirodan broj:");
  scanf("%u",&n);
  
  if (n<=1 || a==b)
  {
      printf("Nekorektan unos\n");
      return -1;
  }
  if (b<a) /* u slucaju da je desni kraj intervala manji od levog */
  {        /* zamenimo im mesta */
     t=a;
     a=b;
     b=t;
  }
  
  
  
  ispis(a,b,n);
  
  
  return 0;
}