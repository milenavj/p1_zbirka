#include <stdio.h>

#define MAX 100

int main()
{
  /* Niz karaktera. */
  char karakteri[MAX];
  char c;
  int i, n;


  for(i=0;i<MAX;i++)
  {
    /* Ucitava se karakter po karakter sa standardnog ulaza sve dok se ne unese * ili se ne prekoraci maksimalni broj karaktera.s */
    printf("Unesite karakter: ");
    scanf("%c", &c);

    /* Cita se znak za novi red nakon unesenog karaktera. */
    getchar();

    /* Ukoliko je unet karakter * prekida se dalje citanje i izlazi se iz petlje. */
    if(c == '*')
      break;

    /* Inace, procitani karakter se smesta u niz. */
    karakteri[i] = c;
  }

  /* Broj unetih karaktera je nakon izlaska iz petlje i-1. */
  n = i-1;

  /* Ispisuju se karakteri u obrnutom redosledu. */
  for(i=n;i>=0;i--)
  {
    printf("%c ", karakteri[i]);
  }
  printf("\n");

  
  return 0;
}
