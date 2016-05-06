/*
Napisati funkciju koja broji neparne cifre u zapisu datog celog broja. Napisati
potom glavni program koji unosi cele brojeve dok se ne unese nula, i ispisuje
broj neparnih cifara svakog unetog broja koriscenjem napisane funkcije. 
*/

#include<stdio.h>
#include<stdlib.h>

int broj_ncifara(int x)
{
   int s=0;
   char cifra;
   x = abs(x);
   
   while(x)
   {
      cifra = x%10;
      s+=(cifra%2); /* izraz cifra%2 ima vrednost 1 kada je cifra neparna, 
                       a 0 kada je cifra parna */
      x/=10;
   }
   
   return s;
}

int main()
{
  int x;
  do
  {
     scanf("%d",&x);
     printf("Broj neparnih cifara u zapisu broja %d: %d\n", x, broj_ncifara(x));
  } while(x!=0);
  
  return 0;
}