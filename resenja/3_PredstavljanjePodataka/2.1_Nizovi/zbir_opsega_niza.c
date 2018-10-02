#include<stdio.h>

#define MAX 100

/* Funkcija racuna zbir elemenata niza od pozicije i do pozicije j. */
int zbir(int a[], int n, int i, int j){
  int k;
  
  /* Zbir elemenata niza iz zadatog opsega. */
  int z = 0;
  
  /* Obilaze se elementi niza. */
  for(k=i; k<=j; k++){
	z+=a[k];
  }
  
  /* Vraca se izracunata vrednost. */ 
  return z;
}

int main(){
  
  int n, i, j;
  int a[MAX];
  
  /* Ucitava se broj elemenata niza i proverava se njegova ispravnost. */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  if(n <= 0 || n > MAX)
  {
	printf("Greska: Nedozvoljena vrednost!\n");
	return 0;
  }
  
  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:");
  for(i=0; i<n; i++)
	scanf("%d", &a[i]);
  
  /* Ucitavaju se vrednosti granica. */
  printf("Unesite vrednosti za i i j: ");
  scanf("%d%d", &i, &j);
  
  /* Proverava se korektnost zadatog intervala. */
  if(i < 0 || j < 0 || i > n-1 || j > n-1 || i > j){
	printf("Greska: Nekorektne vrednosti granica!\n");
	return 0;
  }
  
  /* Ispisuje se rezultat poziva funkcije. */
  printf("Zbir je: %d", zbir(a,n,i,j));
  
  return 0;
}
