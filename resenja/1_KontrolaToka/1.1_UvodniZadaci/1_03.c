/*
   Napisati program koji sa standardnog ulaza ucitava realnu vrednost izrazenu
   u incima, konvertuje tu vrednost u centimetre i ispisuje je na standardni izlaz
   zaokruzenu na dve decimale.
*/
#include <stdio.h>

int main()
{
  float in;
  float cm;
  
  printf("Unesi broj inca: ");
  scanf("%f", &in);                      /* "%f" specifikator za unos/ispis float promenljivih */
  
  cm = in*2.54; /* 1 inch = 2.54 cm */
  
  printf("%.2f in = %.2f cm\n", in, cm); /* "%.4f" - ispis realne promenljive na 4 decimale */
  
  return 0;  
}