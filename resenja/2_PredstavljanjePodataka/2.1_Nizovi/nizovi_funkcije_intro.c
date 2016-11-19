#include <stdio.h>

#define MAX 100

/* a) Napisati funkciju koja ucitava elemente niza. */
void ucitaj(int a[], int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
}

/* b) Napisati funkciju koja stampa elemente niza. */
void stampaj(int a[], int n)
{
   int i;
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");
}

/* c) Napisati funkciju koja racuna sumu elemenata niza. */
int suma(int a[], int n)
{
   int i;
   int s=0;
   for(i=0;i<n;i++)
      s+=a[i];
   return s;
}


/* d) Napisati funkciju koja racuna prosecnu vrednost elemenata niza. */
float prosek(int a[], int n)
{
   int i;
   int s = suma(a,n);
   return (float) s/n;
}


/* e) Napisati funkciju koja izracunava minimum elemenata niza.*/
int minimum (int a[],int n)
{
   int m;
   int i;
   
   /* Minimum inicijalizujemo prvim elementom niza (a[0]), a zatim prolazimo kroz ostatak niza.
      U svakom koraku poredimo vrednost minimuma sa tekucim elementom niza. */
   m = a[0];
   for(i=1;i<n;i++)
      if (a[i] < m)
         m = a[i];

   /* Vraca se izracunata vrednost minimuma */
   return m;
}


/* f) Napisati funkciju koja izracunava poziciju maksimalnog elementa u nizu. */
int pozicija_maksimuma (int a[],int n)
{
   int m;
   int m_pozicija;
   int i;

   /* Maksimum inicijalizujemo prvim elementom niza (a[0]), a zatim prolazimo kroz ostatak niza.
      U svakom koraku poredimo vrednost maksimuma sa tekucim elementom niza. */

   m = a[0];
   m_pozicija=0;
   for(i=1;i<n;i++)
      if (a[i] > m)
      {
         m = a[i];
         m_pozicija=i;
      }
   
   /* Vraca se izracunata pozicija */
   return m_pozicija;
}



int main()
{
   int a[MAX];
   int n;
   
   /* Ucitava se dimenzija niza i proverava njena ispravnost */
   printf("Unesite dimenziju niza:");
   scanf("%d",&n);
   if (n<1 || n>MAX)
   {
      printf("Nedozvoljena vrednost!\n");
      return -1;
   }
   
   
   /* Testira se funkcija kojom se ucitavaju elementi niza */
   ucitaj(a,n);
   
   /* Testira se funkcija kojom se ispisuju elementi niza */
   printf("Ucitani niz: ");
   stampaj(a,n);

   /* Testira se funkcija kojom se izracunava suma elemenata niza */
   printf("Suma elemenata niza: %d\n", suma(a,n));
   
   /* Testira se funkcija kojom se racuna prosek elemenata niza */
   printf("Prosecna vrednost elemenata niza: %.2f\n", prosek(a,n));
   
   /* Testira se funkcija kojom se izracunava minimum niza */
   printf("Minimumalni element niza: %d\n", minimum(a,n));
   
   /* Testira se funkcija kojom se izracunava pozicija maksimalnog elementa */
   printf("Indeks maksimalnog elementa niza: %d\n", pozicija_maksimuma(a,n));
   
   return 0;
}