#include <stdio.h>

int kvadrat(int x) 
{
   /* Promenljive u listi argumenata funkcije, kao i one deklarisane u samoj funkciji, lokalne su za tu funkciju sto znaci da se promenljivama x i y ne moze pristupiti nigde izvan funkcije kvadrat. */
   
   int y;
   y = x*x;
   return y;
}

int main()
{
   int a,kv, kb;
   printf("Unesi ceo broj:");
   scanf("%d",&a);
   
   /* Promenljiva kv dobija povratnu vrednost funkcije kvadrat. */
   kv = kvadrat(a); 
   
   printf("Kvadrat broja %d je %d\n", a, kv);
   return 0;
}
