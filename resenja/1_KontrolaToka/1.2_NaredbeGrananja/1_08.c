
/*
Napisati program koji za karakter koji ucitava jedan karakter i :
- u slucaju da je uneta cifra, ispisuje nju i njen ascii kod 
- u slucaju da je uneto malo slovo, ispisuje njega, njegov ascii kod, odgovarajuce veliko slovo i njegov ascii kod
- u slucaju da je uneto veliko slovo, ispisuje njega, njegov ascii kod, odgovarajuce malo slovo i njegov ascii kod
- u ostalim slucajevima, ispisuje uneti karakter i njegov ascii kod 
*/
#include <stdio.h>
int main()
{
   char c;
   printf("Unesi jedan karakter:");
   scanf("%c", &c);

   if (c>='0' && c<='9')
      printf("cifra:%c ascii:%d\n",c,c);
   else if (c>='A' && c<='Z')
      printf("veliko slovo:%c ascii:%d odgovarajuce malo:%c, ascii:%d\n",c,c,c-'A'+'a',c-'A'+'a'); /* Razlika izmedju ascii koda svakog malog i odgovarajuceg velikog slova 
                                                                                                      je konstanta koja se moze sracunati izrazom 'a'-'A' (i iznosi 32) */
   else if (c>='a' && c<='z')
      printf("malo slovo:%c ascii:%d odgovarajuce veliko:%c, ascii:%d\n",c,c,c-'a'+'A',c-'a'+'A');
   else
      printf("karakter:%c ascii:%d\n",c,c);
   
   return 0;
}
