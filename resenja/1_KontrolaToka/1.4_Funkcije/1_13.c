/*
Za dati broj moze se formirati niz tako da je svaki sledeci clan niza dobijen
kao suma cifara prethodnog clana niza. Broj je srecan ako se dati niz zavrsava sa
jedinicom. Napisati program koji za uneti broj odredjuje da li je srecan.
Na primer: 
- broj 1234 je srecan jer je zbir njegovih cifara 10, dalje zbir cifara broja 10 je 1.
- broj 999 nije srecan jer je njegov zbir cifara 27, zbir cifara broja 27 je 9.
- broj 991 je srecan, zbir njegovih cifara je 19, zbir cifara broja 19 je 10, zbir cifara
broja 10 je 1.
- broj 372 nije srecan, zbir njegovih cifara je 12, zbir cifara broja 12 je 3

Napisati funkciju koja vraca 1 ako je broj srecan, a 0 u suprotnom. 

Napisati program koji omogucava korisnuku da unese prirodan broj, poziva funkciju 
i ispisuje da li je dati broj srecan. Potom traziti od korisnika da unese prirodan 
broj n i ispisati sve srecne brojeve od 1 do n.
*/

#include<stdio.h>

int zbir_cifara(int x)
{
   int s=0;
   char cifra;
   while(x)
   {
      cifra = x%10;
      s+=cifra;
      x/=10;
   }
   return s;
}

int srecan(int x)
{
   int s; /* promenljiva s sadrzi sumu cifara */
   
   do
   {
     s=zbir_cifara(x);     
     x=s; /* kada izracunamo sumu cifara, dodeljujemo je promenljivoj x jer iz te promenljive izdvajamo cifre u funkciji zbir_cifara */
   } while(x>=10);
   
   return (x==1);
      
}

int main()
{
   unsigned n;
   int i;
   printf("Unesi jedan neoznacen broj:");
   scanf("%u",&n);
   
   for(i=1;i<=n;i++)
      if (srecan(i))
         printf("%d je srecan\n", i);
     
  return 0;
}