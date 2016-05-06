/*
Napisati program koji ispituje da li je uneti broj prost.
*/

#include<stdio.h>
#include<math.h>
int main()
{
   int x;
   int i;
   int indikator;
      
   printf("Unesi x>0:");  
   scanf("%d", &x);

   if (x<=0)                        
   {
       printf("Neispravan unos\n"); 
       return -1;                   
   }                                
   
   
   indikator=0;
   for(i=2;i<x;i++)
   {
      printf("proveravam za %d\n",i);
      if (x%i==0)             /* cim pronadjemo prvog delioca, znamo da broj nije prost. prekidamo petlju */
      {
         indikator=1;
         break;
      }
   }
   
   if (indikator==0)
      printf("jeste\n");
   else
      printf("nije\n");
   
   return 0;
}