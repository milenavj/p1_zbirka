#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  char karakteri[MAKS];
  char c;
  int i, n;

  /* Ucitava se karakter po karakter sa standardnog ulaza sve dok 
     se ne unese * ili se ne prekoraci maksimalni broj karaktera. */
  for (i = 0; i < MAKS; i++) 
  {  
    printf("Unesite karakter: ");
    scanf("%c", &c);
    /* Cita se znak za novi red nakon unetog karaktera. */
    getchar();

    /* Ukoliko je unet karakter * izlazi se iz petlje. */
    if (c == '*')
      break;

    /* Procitani karakter se smesta u niz. */
    karakteri[i] = c;
  }

  /* Broj unetih karaktera nakon izlaska iz petlje je i. */
  n = i;

  /* Ispis karaktera u obrnutom redosledu. */
  for (i = n-1; i >= 0; i--)
    printf("%c ", karakteri[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
