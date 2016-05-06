/*
Napisati funkciju koja za dva realna broja x i y i jedan neoznaceni ceo broj n
ispisuje vrednosti funkcije sin u n ravnomerno rasporedjenih tacaka intervala [x,y].
Napisati potom glavni program koji omogucava korisniku da unese potrebne vrednosti
i poziva napisanu funkciju.
*/

#include <stdio.h>
#include <math.h>

void ispis(float x, float y, int n) /* funkcija nema povratnu vrednost; zbog toga je povratni tip void */
{
  float i;
  float korak=(y-x)/(n-1);
  
  for(i=x;i<=y;i+=korak)
    printf("sin(%.4f)=%.4f\n", i,sin(i));
    
}

int main()
{
  float a,b;
  int n;
  float t;
  printf("Unesi dva realna broja:");
  scanf("%f%f",&a,&b);
  printf("Unesi jedan ceo broj > 1:");
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