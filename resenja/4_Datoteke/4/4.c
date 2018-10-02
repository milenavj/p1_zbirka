/*
   U datoteci cije se ime navodi kao prvi argument komandne
   linije navedena je rec r i niz linija. Napisati
   program koji u datoteku cije se ime navodi kao 
   drugi argument komandne linije upisuje sve linije
   u kojima se rec r pojavljuje bar n puta, gde je
   n prirodan broj koji se unosi sa standardnog ulaza. Ispis
   treba da bude u formatu broj_pojavljivanja: linija. 
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXL 81
#define MAXR 31

/*
   Funkcija broj_pojavljivanja broji koliko
   se puta pojavio string t u stringu s
*/
int broj_pojavljivanja(char s[], char t[])
{
   int br;
   int i,j;
   /*
      i - indeks karaktera u s
      j - indeks karaktera u t
      br - brojac koliko se puta t javlja u s
   */
   br=0;
   for(i=0;s[i];i++)
   {      
      for(j=0;t[j];j++)
         if(s[i+j]!=t[j]) /* Ako naidjemo na razlicite karaktere, */
            break;        /* prekidamo petlju. */
      /*
         Do prekida petlje moze doci ili zbog toga sto su pronadjeni
         razliciti karakteri i usledio je break ili zbog toga sto
         je prestao da vazi uslov petlje, odnosno karakter t[j] je
         jednak '\0'. Ako vazi drugi slucaj, to znaci da se string
         t nalazi u stringu s pocev od indeksa i i potrebno je uvecati
         brojac br.
      */
      if (t[j]=='\0') 
            br++;
   }
   
   return br;
}
int main(int argc, char* argv[])
{
   char rec[MAXR];
   char linija[MAXL];
   FILE* in, *out;
   int n;
   int br;

   if(argc!=3)
   {
      fprintf(stderr,"Greska: program se pokrece sa: %s ime_ulazne_datoteke ime_izlazne_datoteke\n", argv[0]);
      exit(EXIT_FAILURE);
   }             
               
   in= fopen(argv[1],"r");
   if(in==NULL)
   {
      fprintf(stderr, "Greska fopen(): Neuspelo otvaranje datoteke %s.\n", argv[1] );
      exit(EXIT_FAILURE);
   }
                 
   out= fopen(argv[2],"w");
   if(out==NULL)
   {
      fprintf(stderr, "Greska fopen(): Neuspelo otvaranje datoteke %s.\n", argv[2] );
      exit(EXIT_FAILURE);
   }
   
   printf("Unesi n:");   
   scanf("%d", &n);

   if(n<=0)
   {
      fprintf(stderr, "Greska: n treba da bude prirodan broj.\n");
      exit(EXIT_FAILURE);
   }

   fscanf(in,"%s",rec);
   
   while(fgets(linija,MAXL,in)!=NULL)   
   {
      br = broj_pojavljivanja(linija,rec);
      if (br>=n)
         fprintf(out,"%d: %s\n", br, linija);
   }
   fclose(in);
   fclose(out);
   return 0;   
}
