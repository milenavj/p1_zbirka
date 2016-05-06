/*
   Napisati program koji ucitava dimenziju n celobrojnog niza a i
   njegove elemente, a zatim iz niza a izbacuje sve elemente
   koji nisu deljivi svojom poslednjom cifrom, izuzev elemenata 
   cija je poslednja cifra 0 koji treba zadrzati. Program treba da ispise 
   izmenjeni niz na standardni izlaz. Mozemo pretpostaviti da niz a 
   sadrzi najvise 100 elemenata.
*/

#include <stdio.h>
#define MAX 100

int main()
{

  int a[MAX];
  
  int n;
  int i,j; 
  char poslednja_cifra;
  int novo_n;

  printf("Unesi dimenziju niza:");
  scanf("%d", &n);

  if (n<1 || n>MAX)
  {
    printf("Neispravan unos\n");
    return -1;
  }
  

  printf("\nUnesi elemente niza a:\n");
  for(i=0;i<n;i++)
  {
    printf("a[%d]=",i);
    scanf("%d", &a[i]);
  }


  /*
    Dodatni indeks j se uvecava u slucaju da element na indeksu
    i treba da ostane u nizu, tj da je deljiv svojim
    indeksom i; u suprotnom, j se nece uvecati i 
    element i ce u narednoj iteraciji biti zamenjen elementom koji
    jeste deljiv svojim indeksom
  */
  
  for(i=0,j=0;i<n;i++)  
  {
    poslednja_cifra = a[i]%10;
    
    /*
       zbog lenjog izracunavanja, ako je prvi uslov
       u disjunkciji tacan, drugi se nece ispitivati
       (jer  ce tada disjunkcija biti tacna bez obzira 
       da li je drugi uslov tacan ili ne)
    */
    if (poslednja_cifra==0 || a[i]%poslednja_cifra==0)
    {
        a[j]=a[i];
        j++;
    }
  }
  /*
    Izbacivanjem elemenata dimenzija niza se menja, odnosno
    smanjuje se za broj izbacenih elemenata
  */
  novo_n=j;

  printf("Nakon izmena:\n");
  for(i=0;i<novo_n;i++)
    printf("a[%d]=%d\n",i,a[i]);

  return 0;
}