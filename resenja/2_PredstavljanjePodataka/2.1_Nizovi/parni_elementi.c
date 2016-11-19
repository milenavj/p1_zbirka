#include <stdio.h>

#define MAX 100

int main()
{
  int a[MAX];
  int n;
  int i;

  /* Ucitava se dimenzija niza i proverava se njena ispravnost. */
  printf("Unesi dimenziju niza:\n");
  scanf("%d", &n);
  if (n<1 || n>MAX)
  {
    printf("Nedozvoljena vrednost!\n");
    return -1;
  }

  /* Ucitavaju se elementi niza */
  printf("Unesi elemente niza:\n");
  for (i=0; i<n; i++)
  {
    scanf("%d", &a[i]); 
  }

  /* Ispisuju se elementi niza na parnim pozicijama */
  printf("Elementi niza na parnim pozicijama:\n");
  for (i=0; i<n; i+=2)
  {
    printf("%d ", a[i]);
  }
  printf("\n");

  /* Ispisuju se parni elementi niza */
  printf("Parni elementi niza:\n");
  for (i=0; i<n; i++){
    if (a[i]%2==0){
      printf("%d ", a[i]);
    }
  }
  printf("\n");
   
  
  return 0;
}
