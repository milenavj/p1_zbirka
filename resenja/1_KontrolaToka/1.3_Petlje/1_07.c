/*
Napisati program koji omogucava korisniku da unosi karaktere dok ne zada tacku i ukoliko je karakter malo slovo,
ispisuje odgovarajuce veliko, ukoliko je karakter veliko slovo ispisuje odgovarajuce malo, a u suprotnom ispisuje
isti karakter kao i uneti.
*/

#include <stdio.h>

int main()
{
  int c;
  
   /* funkcija getchar ucitava jedan karakter. 
      naredbom dodele (c=getchar()) promenljivoj c bice dodeljena vrednost
      ascii koda unetog karaktera 
      obratiti paznju na zagrade!
  */
  while((c=getchar())!='.')   
  {                          
    if (c>='A' && c<='Z')
      putchar(c+'a'-'A'); /* Razlika izmedju ascii koda svakog malog i odgovarajuceg velikog slova 
                              je konstanta koja se moze sracunati izrazom 'a'-'A' (i iznosi 32) */
    else if (c>='a' && c<='z')
      putchar(c-'a'+'A'); 
    else
      putchar(c);
      
  }
  return 0;
}