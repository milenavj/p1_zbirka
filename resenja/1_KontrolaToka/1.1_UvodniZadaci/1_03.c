#include <stdio.h>

int main()
{
  
  float in; /* float - realni tip jednostruke tacnosti */
  float cm;
  
  printf("Unesi broj inca: ");
  scanf("%f", &in);                      
  /* "%f" - format za unos/ispis float promenljivih */
  
  cm = in*2.54; /* 1 inch = 2.54 cm */
  
  printf("%.2f in = %.2f cm\n", in, cm); /* "%.2f" - ispis realne promenljive na 4 decimale */
  
  return 0;  
}