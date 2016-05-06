/*
Sa standardnog ulaza unosi se broj n. Napisati program koji ispisuje brojeve od 1 do n, zatim
od 2 do n - 1, 3 do n - 2, itd. i na kraju ispisuje njihovu sumu. Za neispravan unos, program ispisuje broj -1.
Na primer, za n=7, program treba da ispise
1 2 3 4 5 6 7 2 3 4 5 6 3 4 5 4 
S=64
*/

#include<stdio.h>

int main()
{
   int n;
   int i,j;
   int S=0;
   
   printf("Unesi jedan prirodan broj:");
   scanf("%d",&n);
   
   if (n<=0)
   {
      printf("Neispravan unos\n");
      return -1;
   }
   
   for(i=0;i<n;i++)
      for (j=i+1;j<n-i+1;j++)
      {
         printf("%d ",j);
         S+=j;
      }
   printf("\n");
   printf("S=%d\n",S);
   return 0;
}
