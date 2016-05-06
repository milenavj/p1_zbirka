/* 
Napisati funkciju 
	void par_nepar(int a[], int n, int parni[], int* pn, int neparni[], int* nn)
koja razbija niz a na niz parnih i niz neparnih brojeva. Pokazivaci pn i nn
redom treba da sadrze broj elemenata niza parnih tj. niza neparnih elemenata.
Pretpostaviti da duzina niza a nece biti veca od 50. Napisati program koji
testira napisanu funkciju.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

/* Funkcija koja ucitava elemente niza */
void ucitaj_niz(int a[], int* pn){
  int i; 
  int n;
  
  /* Ucitavamo dimenziju niza */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  
  if(n<0 || n>MAX){
      printf("Greska: pogresna dimenzija niza!\n");
      exit(-1);
  }
  
  /* Ucitavamo elemente niza */
  printf("Unesite elemente niza: ");
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  
  *pn=n;

}

void par_nepar(int a[], int n, int parni[], int* pn, int neparni[], int* nn){

  int i, j, k;
  
  /* i - brojac niza a */
  /* j - brojac niza parnih brojeva */
  /* k - brojac niza neparnih brojeva */
  
  for(i=0, j=0, k=0; i<n; i++){
      /* Ako je element niza paran */
      if(a[i]%2==0){
          /* Smestamo ga u niz parnih brojeva i uvecavamo indeks niza j */
          parni[j]=a[i];
          j++;
      }
      else{
          /* Inace, smestamo ga u niz neparnih brojeva i uvecavamo indeks niza k */
          neparni[k]=a[i];
          k++;
      }
  }
  
  *pn=j;
  *nn=k;
  
}

/* Funkcija koja ispisuje elemente niza */
void pisi_niz(int a[], int n){
  int i;
  
  for(i=0; i<n; i++)
    printf("%d ", a[i]);
  printf("\n");  
}


int main(){
  int n, i, j, pn, nn;
  int a[MAX], parni[MAX], neparni[MAX];
  
  /* Ucitavamo niz */
  ucitaj_niz(a, &n); 
  
  /* Pozivamo funkciju koja razbija zadati niz na niz parnih i niz neparnih */
  par_nepar(a, n, parni, &pn, neparni, &nn);
   
  /* Ispisujemo dobijene nizove */
  printf("Niz parnih brojeva: ");
  pisi_niz(parni, pn);
  
  printf("Niz neparnih brojeva: ");
  pisi_niz(neparni, nn);

  return 0;
}
