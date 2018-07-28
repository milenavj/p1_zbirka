#include <stdio.h>

#define MAX 1000

/* Funkcija koja ucitava elemente niza. */
void ucitaj(int a[], int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
}

/* Funkcija koja stampa elemente niza. */
void stampaj(int a[], int n)
{
   int i;
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");
}

/* Funkciju racuna sumu elemenata niza. */
int suma(int a[], int n)
{
   int i;
   int s=0;
   for(i=0;i<n;i++)
      s+=a[i];
   return s;
}


/* Funkciju koja racuna prosecnu vrednost elemenata niza. */
float prosek(int a[], int n)
{
   int i;
   int s = suma(a,n);
   return (float) s/n;
}


/* Funkciju koja izracunava maksimum elemenata niza.*/
int maksimum (int a[],int n)
{
   int m;
   int i;
   
   /* Maksimum se inicijalizuje prvim elementom niza (a[0]), a zatim se prolazi kroz ostatak niza. U svakom koraku se poredi vrednost maksimuma sa tekucim elementom niza. */
   m = a[0];
   for(i=1;i<n;i++)
      if (a[i] > m)
         m = a[i];

   /* Vraca se izracunata vrednost maksimuma. */
   return m;
}


/* Funkciju koja izracunava poziciju maksimalnog elementa u nizu. */
int pozicija_maksimuma (int a[],int n)
{
   int m;
   int m_pozicija;
   int i;

   /* Minimum se inicijalizuje prvim elementom niza (a[0]) i pamti se njegova pozicija (0), a zatim se prolazi kroz ostatak niza. U svakom koraku se poredi vrednost minimuma sa tekucim elementom niza i ukoliko je potrebno menjaju se vrednosti minimuma i njegove pozicije. */

   m = a[0];
   m_pozicija=0;
   for(i=1;i<n;i++)
      if (a[i] < m)
      {
         m = a[i];
         m_pozicija=i;
      }
   
   /* Vraca se izracunata pozicija. */
   return m_pozicija;
}



int main()
{
   int a[MAX];
   int n;
   
   /* Ucitava se dimenzija niza i proverava njena ispravnost. */
   printf("Unesite dimenziju niza:");
   scanf("%d",&n);
   if (n<1 || n>MAX)
   {
      printf("Nedozvoljena vrednost!\n");
      return -1;
   }
   
   
   /* Testira se funkcija kojom se ucitavaju elementi niza. */
   ucitaj(a,n);
   
   /* Testira se funkcija kojom se ispisuju elementi niza. */
   printf("Vreme trcanja takmicara: ");
   stampaj(a,n);

   /* Testira se funkcija kojom se izracunava suma elemenata niza. */
   printf("Ukupno vreme: %d\n", suma(a,n));
   
   /* Testira se funkcija kojom se racuna prosek elemenata niza. */
   printf("Prosecno vreme trcanja: %.2f\n", prosek(a,n));
   
   /* Testira se funkcija kojom se izracunava minimum niza. */
   printf("Maksimalno vreme trcanja: %d\n", minimum(a,n));
   
   /* Testira se funkcija kojom se izracunava pozicija maksimalnog elementa. */
   printf("Indeks pobednika: %d\n", pozicija_maksimuma(a,n));
   
   return 0;
}
