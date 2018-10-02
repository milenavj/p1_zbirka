#include<stdio.h>
#include<stdlib.h>

/* Funkcija odredjuje broj neparnih cifara u zapisu datog celog broja. */
int broj_neparnih_cifara(int x)
{
   int broj_neaprnih_cifara=0;
   /* Pomocna promenljiva u koju se smesta izdvojena cifra. */
   char cifra;
   /* Posmatra se pozitivna vrednost broja. */
   x = abs(x);
   
   while(x)
   {
		/* Izdvaja se poslednja cifra broja. */
      cifra = x%10;
      /* Moze se izbeci koriscenje naredbe if pomocu narednog izraza. Naime, vrednost izraza cifra%2 je 1 kada je cifra neparna, odnosno 0 kada je parna. Tako ce na broj neparnih cifara biti dodata jednica ako je cifra neparna, a ako je parna bice dodata 0, sto jeste zeljeno ponasanje. */
      broj_neparnih_cifara+=(cifra%2); 
      x/=10;
   }
   
   return broj_neparnih_cifara;
}

int main()
{
  int x;
  do
  {
     scanf("%d",&x);
     printf("%d\n", broj_ncifara(x));
  } while(x!=0);
  
  return 0;
}
