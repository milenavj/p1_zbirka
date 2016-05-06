/*
   Napisati funkciju koja za dva data stringa str i
   accept odredjuje koliko se uzastopnih karaktera stringa str
   nalazi u stringu accept pocev od pocetka niza str. Napisati 
   potom program koji testira napisanu funkciju  za dva stringa 
   koji se unose kao argumenti komandne linije. Primeri upotrebe:
   
   1:
   ./a.out aladin bal
   3
   
   2: 
   ./a.out aladin lad
   4
   
   3: 
   ./a.out Aladin ala
   0
   
*/

#include <stdio.h>
#include <string.h>

/*
   Funkcija strspn(str,accept) je ugradjena funkcija koja vraca broj karaktera
   stringa str koji se nalaze u stringu accept, pocev od pocetka stringa str.    

   Funkcija strspn se nalazi u zaglavlju string.h.

   Funkcija strspn_klon je jedna implementacija funkcije strspn.
       
   U zadacima cemo uvek koristiti ugradjenu funkciju strspn osim ako u tekstu zadatka
   nije naglaseno da se ona ne sme koristiti. Funkcija strspn_klon sluzi da pokaze na koji
   nacin radi ugradjena funkcija strspn.
    
   Ugradjena funkcija strspn poziva se na isti nacin kao funkcija strspn_klon:
   strspn(s1,s2) 

*/

int strspn_klon(char str[], char accept[])
{
   int br=0;
   int i;
   
   for(i=0; str[i];i++)
      if(strchr(accept, str[i])!=NULL)
         br++;
      else      /* ako pronadjemo karakter u stringu str koji nije */
         break; /* u stringu accept, prekidamo petlju */
         
   return br;
}

int main(int argc, char* argv[])
{

   int br;
   
   if(argc<3)
   {
      printf("Nekorektan poziv\nProgram treba pozvati sa ./a.out arg1 arg2\n");
      return -1;
   }
   
   br = strspn_klon(argv[1],argv[2]);
   printf("Broj karaktera stringa %s koji se nalaze u stringu %s, pocev od pocetka stringa %s: %d\n", argv[1],argv[2],argv[1],br);
   return 0;
}