/* 
   Napisati program koji u datoteci cije se ime navodi kao prvi
   argument komandne linije odredjuje liniju maksimalne duzine i
   ispisuje je na standarni izlaz. Ukoliko ima vise takvih linija,
   ispisati onu koja je leksikografski prva. Mozemo pretpostaviti
   da datoteka ne sadrzi linije duze od 80 karaktera.  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 81
 
int main(int argc, char* argv[])
{
   char linija[MAX_LEN];
   char max_linija[MAX_LEN];
   int duzina;
   int max_duzina;
   
   FILE *ulaz, *izlaz;

   /*
     Proveravamo da li poziv programa ima dovoljan broj argumenata. 
   */
   if(argc!=2)
   {
      fprintf(stderr,"Greska: program se pokrece sa: %s ime_ulazne_datoteke\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   ulaz=fopen(argv[1],"r");
   if(ulaz==NULL)
   {
      fprintf(stderr,"error fopen(): Neuspelo otvoranje datoteke %s za citanje.\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   /*
      Funkcija fgets ucitava jednu liniju teksta maksimalne duzine MAX_LEN
      iz datoteke ulaz u string linija. Ukoliko ucitavanje ne uspe (na primer,
      zato sto smo dosli do kraja datoteke), povratna vrednost ove funkcije
      bice prazan pokazivac (NULL).
   */	
   
   max_duzina=0;	
   while(fgets(linija, MAX_LEN, ulaz)!=NULL)
   { 
      duzina = strlen(linija);      
      /*
         Promenljivu max_duzina inicijalizovali smo na 0 pre ulaska u petlju.
         Ovu promenljivu menjamo kada je duzina ucitana linije
         veca od max_duzina ili kada su jednake, ali je ucitana linija 
         leksikografski ispred trenutne linije sa maksimalnom duzinom.
         
         Setimo se da funkcija strcmp(s1,s2) vraca razliku ascii kodova prva dva
         razlicita karaktera stringova s1 i s2 na istim indeksima, ukoliko oni
         postoje, ili 0 ukoliko su jednaki. Ova funkcija je stoga osetljiva
         na mala i velika slova (npr 'D' je leksikografski ispred 'p').         
         
      */
      
      if(duzina>max_duzina || (duzina==max_duzina && strcmp(linija,max_linija)<0))
      {
         strcpy(max_linija, linija);
         max_duzina=duzina;
      }
   }
   
   /*
      Funkcija fputs ispisuje string koji je njen prvi argument u datoteku
      koja je njen drugi argument. Sve funkcije za ucitavanje iz datoteka i 
      upis u datoteke (fgetc, fputc, fgets, fputs, ...) mozemo koristiti
      i kada radimo sa standardnim ulazom i standardnim izlazom. Kao nazive
      datoteka tada navodimo stdin i stdout.
   */
   fputs(max_linija, stdout);
   
   fclose(ulaz);
   return 0;
}
