#include <stdio.h>

#define MAX 100

int main()
{
  int a[MAX];
  int b[MAX];
 
  /* Rezultujuci niz ima najvise 2*MAX elemenata */
  int c[2*MAX];
  
  int n;
  int i,j;
  
  
  /* Ucitava se dimenzija nizova i proverava njena ispravnost */
  printf("Unesite dimenziju nizova:\n");
  scanf("%d", &n);
  if (n<1 || n>MAX)
  {
    printf("Nedozvoljena vrednost!\n");
    return -1;
  }
 
  /* Ucitavaju se elementi prvog niza */
  printf("Unesite elemente niza a:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d", &a[i]);
  }
  
  /* Ucitavaju se elementi drugog niza */
  printf("Unesite elemente niza b:\n");          
  for(i=0;i<n;i++)
  {
    scanf("%d", &b[i]);
  }

  /*
    Formira se treci niz. 
    Koriste se dva indeksa:
      
      - indeks i pomocu kojeg se pristupa elementima nizova a i b i 
      koji treba uvecati za 1 nakon svake iteracije 
  
      - indeks j pomocu kojeg se pristupa elementima rezultujuceg niza c;
      s obzirom da se u svakoj iteraciji u niz c smestaju dva elementa, jedan iz niza a i jedan iz niza b, 
      indeks j se uvecava za 2 nakon svake iteracije
  */  
  for(i=0,j=0;i<n;i++,j+=2)
  {
    c[j]=a[i];
    c[j+1]=b[i];
  }
  
  /* Ispisuju se elementi rezultujuceg niza */
  printf("Rezultujuci niz:\n");          
  for(i=0;i<2*n;i++)
     printf("%d ",c[i]);     
  printf("\n");
 
  return 0;
}