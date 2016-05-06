/*
Napisati program koji za uneti realan broj x i ceo broj n ispisuje
vrednost stepena x^n. Unosenje promenljivih, racunanje stepena i
ispis promenljivih realizovati u posebnim funkcijama.
*/

#include <stdio.h>
#include <stdlib.h>

float stepen(float a, int b)
{
  float s=1;
  int i;
  
  for(i=0;i<abs(b);i++)
    s=s*a;

  return b>0 ? s : 1/s;   /* ukoliko je izlozilac b negativan, izracunamo a^|b| i vracamo reciprocnu vrednost 
                             izracunatog stepena */

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