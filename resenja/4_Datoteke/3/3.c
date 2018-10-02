/*
   U datoteci cije se ime zadaje kao prvi argument komandne linije nalazi se
   prirodan broj n a zatim i n celih brojeva. Napisati program koji prebrojava
   koliko k-tocifrenih brojeva postoji u datoteci, pri cemu se prirodan broj k
   zadaje kao drugi argument komandne linije.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
   Funkcija ucitaj_i_prebroj ucitava brojeve
   iz datoteke na koju pokazuje f i prebrojava
   koliko je medju njima k-tocifrenih brojeva  
*/
int ucitaj_i_prebroj(FILE* f, int k)
{
   int n;
   int x;
   int i;
   int br;
   
   /* U datoteci je prvo naveden ukupan broj brojeva. */
   fscanf(f,"%d",&n);

   /* Ako je taj broj negativan ili nula, izdajemo poruku o gresci. */
   if(n<=0)
   {
      fprintf(stderr, "Greska: broj n mora biti prirodan\n");
      exit(EXIT_FAILURE);
   }

   br=0;
   for(i=0;i<n;i++)
   {
      fscanf(f,"%d",&x);
      if(broj_cifara(x)==k)
         br++;
   }

   return br;
}

int broj_cifara(int x)
{
   int br_c;
   
   br_c=0;
   
   /* 
      Do while petlja je pogodnija od petlji sa preduslovom 
      jer tacno racuna broj cifara i za broj 0. 
   */
   do
   {
     br_c++;
     x/=10;
   } while(x);
   
   return br_c;
}

int main(int argc, char* argv[])
{
   int n;
   int k;
   FILE* f;
   int br;

   if(argc!=3)
   {
      fprintf(stderr,"Greska: program se pokrece sa: %s naziv_datoteke k \n", argv[0]);
      exit(EXIT_FAILURE);       
   }
          
   f=fopen(argv[1], "r");
   
   if(f==NULL)
   {
      fprintf(stderr, "Greska fopen(): Neuspelo otvaranje datoteke %s.\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   /* Argumenti komandne linije su stringovi. Da bismo konvertovali string
      u ceo broj koristimo ugradjenu funkciju atoi. */
   k = atoi(argv[2]);
   
   if (k<=0)
   {
      fprintf(stderr, "Greska: broj k mora biti prirodan\n");
      exit(EXIT_FAILURE);
   }
   
   printf("Broj %d-cifrenih brojeva u datoteci: %d\n", k,ucitaj_i_prebroj(f,k));
   
   fclose(f);
   return 0;
}
