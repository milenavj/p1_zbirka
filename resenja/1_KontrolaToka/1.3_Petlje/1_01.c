/*
Napisati program koji 10 puta ispisuje tekst "We love C programming".
*/

#include<stdio.h>

int main()
{
   int i=0;      /* promenljiva i kontrolise koliko puta ce se petlja izvrsiti */
   while (i<10) /* pre ulaska u telo petlje proverava se da li je */
   {             /* ispunjen uslov petlje */
       printf("We love C programming\n");
       i++; /* operator ++ uvecava i promenljivu za 1 
               i++; ima isti efekat kao i=i+1;
               ili i+=1;
               
               ukoliko ne bismo menjali vrednost promenljive i doslo bi
               do beskonacne petlje!
             */
   }
   
   /*
      brojanje u while petlji smo mogli realizovati i preko uslova:
	  
	  i=1;
	  while(i<=10)
	  {
	     ...
	  }
	  
	  ili 
	  
	  i=2;
	  while(i<=11)
	  {
	     ...
	  }
	  
	  ili
	  
	  i=3;
	  while(i<13)
	  {
	     ...
	  }
	  
       Brojanje pocev od 0 uz koriscenje stroge nejednakosti
       je u duhu programskog jezika C i zato cemo ovaj nacin
       brojanja najcesce koristiti
   */
   return 0;
}