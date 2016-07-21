/*
  Napisati funkciju int prebrojavanje(int a[], int n) koja izracunava broj elemenata niza celih brojeva a duzine n
koji su manji od poslednjeg elementa niza. Napisati i program koji testira rad funkcije. Pretpostaviti da duzina
niza nece biti veca od 100.

 */

#include <stdio.h>
#define MAX 100

/*
 * Funkcija prebrojavanje vraca broj elemenata niza koji su manji od poslednjeg 
 * NAPOMENA: Poslednji element niza se nalazi na poziciji n-1
 */
int prebrojavanje(int a[], int n)
{
  int i;
  /*Inicijalizujemo brojac na 0*/
  int br=0;
  
  /*
   * Petljom prolazimo kroz sve clanove niza, 
   * poredimo ih sa poslednjim elementom i 
   * ukoliko su manji, uvecavamo brojac
   */
  for(i=0;i<n-1;i++){   
    if(a[i]<a[n-1]){
      br++;
	}
  }
     
  /*Vracamo izracunatu vrednost*/   
  return br;
}

int main()
{
  int a[MAX];
  int n;
  int i;
  
  printf("Unesite broj elemenata niza:");
  scanf("%d", &n);
 
  /*Provera korektnosti ulaznih podataka*/
  if(n<=0 || n>100)
  {
     printf("Greska: pogresan unos!\n");
     return 0;
  }
  
  /*Ucitavanje niza*/
  printf("Unesite elemente niza:");
  for(i=0;i<n;i++)  
   scanf("%d",&a[i]);
   
  /*Ispis rezultata*/
  printf("%d\n", prebrojavanje(a,n));
  
  return 0;
}
