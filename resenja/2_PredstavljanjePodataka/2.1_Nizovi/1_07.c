/*
   a) Napisati funkciju koja ucitava sadrzaj niza.
   b) Napisati funkciju koja stampa sadrzaj niza.
   c) Napisati funkciju koja racuna sumu elemenata niza.   
   d) Napisati funkciju koja racuna prosecnu vrednost elemenata niza.
   e) Napisati funkciju koja izracunava minimum elemenata niza.
   f) Napisati funkciju koja izracunava poziciju maksimalnog elementa u nizu.
   g) Napisati program koji testira prethodne funkcije.

*/

#include <stdio.h>
#define MAX 100

/* a) */
void ucitaj(int a[], int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("Unesi element na poziciji %d:",i);
      scanf("%d",&a[i]);
   }
}

/* b) */
void stampaj(int a[], int n)
{
   int i;
   for(i=0;i<n;i++)
      printf("%d\t",a[i]);
   printf("\n");
}

/* c) */
int suma(int a[], int n)
{
   int i;
   int s=0;
   for(i=0;i<n;i++)
      s+=a[i];
   return s;
}


/* d) */
float prosek(int a[], int n)
{
   int i;
   int s = suma(a,n);
   return (float) s/n;
}


/* e) */
int minimum (int a[],int n)
{
   int m;
   int i;
   m = a[0];

   /* 
      minimum inicijalizujemo na prvi element niza (a[0])
      u svakom koraku poredimo vrednost minimuma
      sa jednim elementom niza, iduci redom; s obzirom
      da je minimum inicijalizovan na a[0], nema potrebe
      porediti a[0] sa a[0] i zbog toga indeksiranje krece
      od 1         
   */

   for(i=1;i<n;i++)
      if (m>a[i])
         m = a[i];

   return m;
}


/* f) */
int max_pozicija (int a[],int n)
{
   int m;
   int m_poz;
   int i;
   m = a[0];
   m_poz=0;
   

   for(i=1;i<n;i++)
      if (m<a[i])
      {
         m = a[i];
         m_poz=i;
      }
   
   return m_poz;
}



int main()
{
   int a[MAX];
   int n;
   printf("Unesi dimenziju niza:");
   scanf("%d",&n);
  
   if (n<1 || n>MAX)
   {
      printf("Nekorektan unos\n");
      return -1;
   }

   ucitaj(a,n);
   printf("Ucitani niz:");
   stampaj(a,n);

   printf("Suma elemenata niza: %d\n", suma(a,n));
   printf("Prosecna vrednost elemenata niza: %.2f\n", prosek(a,n));
   printf("Minimumalni element niza: %d\n", minimum(a,n));
   printf("Indeks maksimalnog elementa niza: %d\n", max_pozicija(a,n));
   
   return 0;
}