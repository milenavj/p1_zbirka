/*
Napisati funkciju koja racuna aritmeticku sredinu cifara datog celog broja.
Napisati potom glavni program koji omogucava korisniku da unese ceo broj
i racuna aritmeticku sredinu njegovih cifara primenom napisane funkcije. Ispisati
izracunatu vrednost zaokruzenu na dve decimale.
*/

#include<stdio.h>
#include<stdlib.h>

float aritmeticka_sredina(int x)
{
   int zbir_cifara=0;
   int broj_cifara=0;
   char cifra;
 
   if (x==0)     /* u slucaju da je uneta 0 */
      return 0;  /* aritmeticka sredina cifara iznosi 0 i tu vrednost vracamo */
                 
      
   x=abs(x); /* uzimamo apsolutnu vrednost broja za slucaj da je negativan */  
   
   while(x)
   {
      cifra=x%10;
      
      broj_cifara++;
      zbir_cifara+=cifra;
      
      x/=10;
   }
   
   return (0.0+zbir_cifara)/broj_cifara;  /* posto su zbir_cifara i broj_cifara celobrojne vrednosti, 
                                             neophodno je da bar jednu od njih konvertujemo u realnu 
                                             kako bismo izbegli celobrojno deljenje */
}

int main()
{
   int x;
   printf("Unesi jedan ceo broj:");
   scanf("%d",&x);
   printf("Aritmeticka sredina cifara broja %d iznosi %.2f\n", x,aritmeticka_sredina(x));
   return 0;
}