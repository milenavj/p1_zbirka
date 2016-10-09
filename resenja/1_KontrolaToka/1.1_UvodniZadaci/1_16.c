#include <stdio.h>

int main()
{
  /* float - realni tip jednostruke tacnosti */
  float in; 
  float cm;
  
  printf("Unesi broj inca: ");

  /* "%f" - format za unos/ispis float promenljivih */
  scanf("%f", &in);                      
  
  /* 1 inch = 2.54 cm */
  cm = in*2.54; 

  /* "%.2f" - ispis realne promenljive na 4 decimale */
  printf("%.2f in = %.2f cm\n", in, cm);
  
  return 0;  
}
