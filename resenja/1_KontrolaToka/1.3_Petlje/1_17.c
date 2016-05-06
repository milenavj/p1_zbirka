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
      

   if (x==2 || x==3)  /* brojevi 2 i 3 su prosti */
      indikator=0;    
   else if (x%2==0)   /* parni brojevi nisu prosti */
      indikator=1;
   else               /* za neparne brojeve ispitujemo da li imaju delioce */
   {   
      indikator=0;
      for(i=3;i<=sqrt(x);i+=2) /* kandidati za delioce neparnih brojeva su neparni brojevi */
      {
         printf("proveravam za %d\n",i);
         if (x%i==0)     /* cim pronadjemo prvog delioca, znamo da broj nije prost. prekidamo petlju */
         {
           indikator=1;
           break;
         }
      }
   }
   
   if (indikator==0)
      printf("jeste\n");
   else
      printf("nije\n");
   
   return 0;
}