#include <stdio.h>

int main()
{
  unsigned int n, i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);
 
  for(i=1; i<=(n+1)/2; i++)
  {
    for(j=i; j<=n+1-i; j++)
      printf("%d ", j);
  }
  
  return 0;
}