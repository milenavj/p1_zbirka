/*
 Napisati funkciju int prebrojavanje(int a[], int n) koja izracunava broj parnih elemenata niza celih brojeva a
duzine n koji prethode maksimalnom elementu niza. Napisati i program koji testira rad funkcije. Pretpostaviti
da duzina niza nece biti veca od 100.
 */

#include <stdio.h>
#define MAX 100

/*Funkcija koja vraca broj parnih elemenata niza koji se nalaze ispred najveceg elementa u nizu
 * Ideja je da prvo pronadjemo najveci element niza i njegovu poziciju, a zatim da jos jednom
 * prodjemo kroz niz sa ciljem da nadjemo sve parne brojeve koje prethode maksimalnom.
 */
int prebrojavanje(int a[], int n)
{
  int i;
  int max;
  int max_ind;
  int br = 0;
  
  /*Na pocetku postavljamo da je maksimalni element a[0] i da je odgovarajuca pozicija 0*/
  max = a[0];
  max_ind=0;
  
  /*Pronalazimo maksimum niza i pamtimo i vrednost i poziciju*/
  for(i=1;i<n-1;i++)
    if(a[i]>max)
    {
      max = a[i];
      max_ind = i;
    }
    
  /* Krecemo od pocetka niza i idemo do pozicije na kojoj se nalazi najveci element
   * i pronalazimo sve parne brojeve
   */  
  for(i=0;i<max_ind;i++)   
    if(a[i]%2==0)
      br++;
 
  return br;
}

int main()
{
  int a[MAX];
  int n;
  int i;
  
  printf("Unesite broj elemenata niza:");
  scanf("%d", &n);
  
  /*Vrsimo proveru korektnosti ulaza*/
  if(n<=0 || n>100)
  {
     printf("Greska: pogresan unos!\n");
     return 0;
  }
  
  /*Ucitavamo elemente niza*/
  printf("Unesite elemente niza:");
  for(i=0;i<n;i++)  
   scanf("%d",&a[i]);
   
  /*Ispisujemo rezultat*/
  printf("%d\n", prebrojavanje(a,n));
  return 0;
}