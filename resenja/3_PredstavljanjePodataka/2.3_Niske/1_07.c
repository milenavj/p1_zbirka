/*
   Napisati program koji ucitava dva stringa i ispituje najpre da li su jednaki. Ako jesu, program
   treba da izda odgovarajucu poruku, a ako nisu, treba da ispita da li je drugi podstring 
   prvog. Ukoliko jeste, program treba da ispise pocev od kog indeksa prvog
   stringa pocinje drugi string. U suprotnom, ispisati odgovarajucu poruku. Mozemo
   pretpostaviti da stringovi ne sadrze vise od 20 karaktera.
*/

#include <stdio.h>
#include <string.h>

/*
       Funkcija strcmp(s,t) je ugradjena funkcija koja utvrdjuje da li su strinovi
       s i t jednaki. Ukoliko jesu, vraca 0, a u suprotnom vraca razliku
       ASCII kodova prva dva razlicita karaktera na istim pozicijama 
       (npr strcmp("aa","ab") ce vratiti -1 a strcmp("ab","aa") 1).

       Funkcija strcmp se nalazi u zaglavlju string.h.

       Funkcija strcmp_klon je jedna implementacija funkcije strcmp.
       
       U zadacima cemo uvek koristiti ugradjenu funkciju strcmp osim ako u tekstu zadatka
       nije naglaseno da se ona ne sme koristiti. Funkcija strcmp_klon sluzi da pokaze na koji
       nacin radi ugradjena funkcija strcmp.
    
       Ugradjena funkcija strcmp poziva se na isti nacin kao funkcija strcmp_klon:
       strcmp(s1,s2) 
       gde poredimo stringove s1 i s2. 

*/

int strcmp_klon(char s1[], char s2[])
{
  int i;
  for(i=0; s1[i]==s2[i];i++)
    if (s1[i]=='\0')
      return 0;
      
  return s1[i] - s2[i];
}

int main()
{
   char s1[21];
   char s2[21];
   char* p;
      
   printf("Unesi dva stringa:");   
   scanf("%s%s",s1,s2);

   /*                 
       Funkcija strstr(s,t) je ugradjena funkcija koja utvrdjuje da li je string t
       podstring stringa t i ako jeste, vraca pokazivac (char*) na karakter 
       stringa s odakle pocinje prvo pojavljivanje stringa t, a NULL u suprotnom.
       
       NULL je pokazivac koji ne pokazuje ni na sta, odnosno ne sadrzi adresu
       nijedne promenljive.
       
       Podsetimo se veze nizova(a time i stringova) i pokazivaca:
       ako je string deklarisan sa s1[21], tada je njegov naziv s1
       ekvivalentan adresi prvog karaktera stringa: 
       s1 <=> &s1[0]
       i nadalje redom:
       s1+1 <=> &s1[1]
       ...
       u opstem slucaju:
       s1+i <=> &s1[i]
       
       To znaci da se indeks elementa na koji pokazuje s1+i moze
       dobiti tako sto od s1+i oduzmemo pokazivac na pocetak niza:
       s1+i-s1 <=> i. Ovako od pokazivaca na karakter u stringu
       dobijamo njegov indeks u stringu.
       
   */   

   p = strstr(s1,s2);
   
   if (strcmp_klon(s1,s2)==0)
      printf("Uneti stringovi su jednaki\n");   
   else if (p!=NULL)
      printf("%s jeste podstring od %s pocev od pozicije : %d\n", s2,s1, p-s1);
   else
      printf("%s NIJE podstring od %s\n", s2,s1);

   return 0;
}