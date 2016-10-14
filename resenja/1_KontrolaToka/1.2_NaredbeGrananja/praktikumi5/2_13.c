
#include <stdio.h>

int main(){
  
  int dan;

  printf("Unesite broj: ");
  scanf("%d", &dan);
  
  switch(dan)
  {
    case 1:
      printf("ponedeljak\n");
      break;
    case 2:
      printf("utorak\n");
      break;
    case 3:
      printf("sreda\n");
      break;
    case 4:
      printf("cetvrtak\n");
      break;
    case 5:
      printf("petak\n");
      break;
    case 6:
      printf("subota\n");
      break;
    case 7:
      printf("nedelja\n");
      break;
    default: 
      printf("Greska: nedozvoljeni unos!\n");
  }
  
  return 0;
}