#include<stdio.h>
#include<stdlib.h>

int broj_ncifara(int x)
{
   int s=0;
   char cifra;
   x = abs(x);
   
   while(x)
   {
      cifra = x%10;
      s+=(cifra%2); /* izraz cifra%2 ima vrednost 1 kada je cifra neparna, 
                       a 0 kada je cifra parna */
      x/=10;
   }
   
   return s;
}

int main()
{
  int x;
  do
  {
     scanf("%d",&x);
     printf("%d\n", broj_ncifara(x));
  } while(x!=0);
  
  return 0;
}