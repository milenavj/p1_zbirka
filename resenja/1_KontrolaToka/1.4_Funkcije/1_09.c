#include<stdio.h>
#include<stdlib.h>

/* Funkcija ispituje da li se cifra c nalazi u zapisu celog broja x. */
int sadrzi(int x, int c)
{
   char cifra;
   x=abs(x);
   while(x)
   {
      cifra = x%10;
      if (cifra==c)
         return 1;
      x/=10;
   }
   return 0;
}
int main()
{
  int x;
  int c;
  printf("Unesi jedan ceo broj i jednu cifru:");
  scanf("%d%d",&x,&c);
  if (sadrzi(x,c))
     printf("Cifra %d se nalazi u zapisu broja %d\n",c,x);
  else
     printf("Cifra %d se ne nalazi u zapisu broja %d\n",c,x);  
  return 0;
}
