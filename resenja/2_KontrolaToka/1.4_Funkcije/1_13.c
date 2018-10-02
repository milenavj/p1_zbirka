#include<stdio.h>

/* Funkcija koja vraca zbir cifara datog broja x. */
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
   int suma_cifara; 
   
   do
   {
     /* Za svaki tekuci clan niza odredjuje se suma njegovih cifara, a onda ta izracunata suma upravo i postaje novi tekuci clan niza. */
     suma_cifara = zbir_cifara(x);     
     x = suma_cifara; 
   } while(x>=10);
   /* Petlja se izvrsava sve dok clan niza ne postane jednocifren. Zbir cifara jednocifrenog broja je upravo sam taj broj. */

   return (x==1);
      
}

int main()
{
   unsigned n;
   int i;
   printf("Unesi jedan neoznacen broj:");
   scanf("%u",&n);
 
	/* U petlji se ispisuju svi srecni brojevi od 1 do n. Za svaki broj od 1 do n se poziva funkcija koja vraca vrednost 1 ako je broj srecan. */  
   for(i=1;i<=n;i++)
      if (srecan(i))
         printf("%d je srecan\n", i);
     
  return 0;
}
