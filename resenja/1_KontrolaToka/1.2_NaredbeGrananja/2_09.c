#include <stdio.h>

int main()
{
   char c;
   printf("Unesite jedan karakter:");
   scanf("%c", &c);

   printf("Uneti karakter: %c, njegov ASCII kod: %d\n", c, c);
   
   /* 
      Razlika izmedju ASCII koda svakog malog i odgovarajuceg 
      velikog slova je konstanta koja se moze sracunati 
      izrazom 'a'-'A' (i iznosi 32) 
   */
   
   if (c>='A' && c<='Z')
      printf("odgovarajuce malo slovo: %c, njegov ASCII kod: ",
      "%d\n", c+('a'-'A'), c+('a'-'A'));
   
   if (c>='a' && c<='z')
      printf("odgovarajuce veliko slovo: %c, njegov ASCII kod: ",
      "%d\n", c-('a'-'A'), c-('a'-'A'));   
      
   return 0;
}
