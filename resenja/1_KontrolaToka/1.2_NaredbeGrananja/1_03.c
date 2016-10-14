#include <stdio.h>

int main()
{
  int x;
  printf("Unesite jedan ceo broj:");
  scanf("%d",&x);
  
  if (x==0)
    printf("Broj je jednak nuli\n");
  else if (x<0)
    printf("Broj je manji od nule\n");
  else
    printf("Broj je veci od nule\n");
    
  return 0;
}