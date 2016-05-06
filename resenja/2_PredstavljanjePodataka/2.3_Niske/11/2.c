/*
Napisati funkciju int prebrojavanje(int a[], int n) koja izracunava broj parnih elemenata niza celih brojeva a
duzine n koji prethode maksimalnom elementu niza. Napisati i program koji testira rad funkcije. Pretpostaviti
da duzina niza nece biti veca od 100.
*/

#include <stdio.h>
#define MAX 100

/* Funkcija pronalazi indeks maksimalnog elementa niza a duzine n */
int indeks_maksimuma(int a[], int n){
  int max;
  int max_ind;
  int i;

  /* Na pocetku postavljamo da je maksimalni element a[0] i da je odgovarajuca pozicija 0*/
  max = a[0];
  max_ind = 0;
  
  /* Pronalazimo maksimum niza i pamtimo i vrednost i poziciju*/
  for(i=1;i<n;i++)
    if(a[i]>max)
    {
      max = a[i];
      max_ind = i;
    }
    
  return max_ind;	
}

/* Funkcija koja izracunava broj parnih elemenata u nizu a duzine n */
int broj_parnih(int a[], int n){
	int i;
	int parni=0;
	
	for(i=0; i<n; i++){
		if(a[i]%2==0)
			parni++;
	}
	
	return parni;
}

/* Funkcija koja vraca broj parnih elemenata niza koji se nalaze ispred najveceg elementa u nizu */
int prebrojavanje(int a[], int n)
{
  /* Pronalazimo indeks najveceg elementa u nizu */
  int indeks;
  indeks=indeks_maksimuma(a,n);
  
  /* Izracunavamo broj parnih elemenata koji mu prethode */
  int parni;
  parni=broj_parnih(a, indeks);
  
  /* I vracamo rezultat */
  return parni;
}

int main()
{
  int a[MAX];
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
   scanf("%d",&a[i]);
   
  /*Ispisujemo rezultat*/
  printf("%d\n", prebrojavanje(a,n));
 
  return 0;
}
