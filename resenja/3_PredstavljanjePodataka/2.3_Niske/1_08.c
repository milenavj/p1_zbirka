/*
   Napisati program koji za uneti string s i karakter c utvrdjuje
   da li se c pojavljuje u stringu s i ukoliko se pojavljuje,
   ispisuje indeks prvog pojavljivanja a u suprotnom ispisuje
   odgovarajucu poruku. Mozemo pretpostaviti da string ima najvise
   20 karaktera.
*/

#include <stdio.h>
#include <string.h>

int main()
{
   char s[21];
   char c;
   char* p;   
   
   printf("Unesi karakter:");
   c=getchar();
   printf("Unesi string:");
   scanf("%s", s);
   
   /*
     Da smo ucitavali obrnutim redom (prvo string pa karakter)
     to bismo realizovali na sledeci nacin:
     printf("Unesi string:");
     scanf("%s",s);
     getchar();
     printf("Unesi karakter:");
     c=getchar();
     
     Dodatni getchar() bi sluzio da "pokupi" karakter kojim
     razdvajamo unos stringa i karaktera (razmak, novi red ili 
     slicno).
   
   */   
   
   /*
      Funkcija strchr(s,c) je ugradjena funkcija koja vraca pokazivac
      na prvi karakter u stringu s koji je jednak karakteru c, ako takav
      postoji, a NULL u suprotnom.
      
      Indeks od pokazivaca dobijamo na isti nacin kao u prethodnom zadatku
      sa strstr.
   */
   
   p = strchr(s,c);
   if(p!=NULL)
      printf("%c se pojavljuje u %s na poziciji %d\n", c, s, p-s);
   else
      printf("%c se NE pojavljuje u %s\n",c, s);
      
   return 0;
}
