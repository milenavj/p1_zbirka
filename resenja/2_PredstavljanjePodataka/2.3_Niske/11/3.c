/*
  Napisati funkciju int prebrojavanje_cifre(char s[], int n) koja izracunava broj cifara u nizu karaktera a duzine n. 
  Napisati i program koji testira rad funkcije. Pretpostaviti da duzina niza ne ́ce biti ve ́ca od 100.
 */

#include <stdio.h>
#include <ctype.h>
#define MAX 100

/* Funkcija koja prebrojava koliko ima cifara u datom nizu karaktera */
int prebrojavanje(char a[], int n)
{
  int i;
  int br = 0;
 
  /*Prolazimo kroz niz i proveravamo da li je trenutni karakter cifra i ukoliko jeste, uvecavamo brojac*/
  /*Funkcija isdigit vraca 1 ukoliko je prosledjeni karakter cifra, a 0 u suprotnom 
	i nalazi se u zaglavlju ctype.h
   */
  for(i=0;i<n;i++)   
    if(isdigit(a[i]))
      br++;
      
  return br;
}

int main()
{
  char a[MAX];
  int n;
  int i;
  
  printf("Unesite broj elemenata niza:");
  scanf("%d", &n);
  
  /*Vrsimo proveru korektnosti ulaza*/
  if(n<=0 || n>MAX)
  {
     printf("Greska: pogresan unos!\n");
     return 0;
  }
  
  /*Ucitavamo elemente niza*/
  printf("Unesite elemente niza:");
  for(i=0;i<n;i++)  
  {
  /*Kako su elementi niza karakteri, neophodno je da u svakoj iteraciji preskocimo karakter koji oznacava belinu ili novi red*/
   getchar();
   /*A da zatim ucitamo sam karakter u niz*/
   scanf("%c",&a[i]);
  } 
  
  /*Ispisujemo rezultat*/
  printf("Broj cifara je: %d\n", prebrojavanje(a,n));
  return 0;
}
