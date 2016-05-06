/*
  Napisati program koji ucitava dimenziju n dva celobrojna niza a i b (oba niza su iste dimenzije), 
  zatim ucitava elemente oba niza i formira treci niz c tako sto naizmenicno rasporedjuje
  elemente nizova a i b unutar njega: a_0,b_0,a_1,b_1,...,a_(n-1),b_(n-1). Program treba
  da ispise elemente novog niza c na standardni izlaz. Mozemo pretpostaviti da je maksimalni
  broj elemenata u nizovima a i b 100.   
*/

#include <stdio.h>
#define MAX 100

int main()
{
  int a[MAX];
  int b[MAX];
  int c[2*MAX];
  
  int n;
  int i,j;
  
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
  
  printf("\nUnesi elemente niza b:\n");          
  for(i=0;i<n;i++)
  {
    printf("b[%d]=",i);
    scanf("%d", &b[i]);
  }

  /*
    Koristimo dva indeksa: 
    1. i, sa kojim pristupamo
       elementima niza a i b, i koji uvecavamo za 1 
       nakon svake iteracije, 
    2  j, sa kojim pristupamo
       elementima niza c; s obzirom da u svakoj 
       iteraciji dodeljujemo vrednost za dva
       elementa niza c (c[j] i c[j+1]), indeks
       j uvecavamo za 2 nakon svake iteracije    
  */  
  for(i=0,j=0;i<n;i++,j+=2)
  {
    c[j]=a[i];
    c[j+1]=b[i];
  }
  
  printf("\nNiz c:\n");          
  for(i=0;i<2*n;i++)
     printf("c[%d]=%d\n",i,c[i]);
     
  return 0;
}