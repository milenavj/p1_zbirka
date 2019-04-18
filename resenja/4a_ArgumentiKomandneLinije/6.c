#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  /* Deklaracije potrebnih promenljivih. */
  int i, j;

  /* Ukoliko ima jedan ili nijedan argument, onda ne moze da bude
     duplikata. */
  if (argc < 2) 
  {
    printf("Medju argumentima nema istih.\n");
    return 0;
  }

  /* Za svaki argument komandne linije se proverava da li postoji
     neki od argumenata koji mu je jednak. */
  for (i = 0; i < argc; i++) 
  {
    /* Za fiksirano argv[i] se vrsi provera svih argumenata koji se
       nalaze nakon njega. */
    for (j = i+1; j < argc; j++)
      if (strcmp(argv[i], argv[j]) == 0) 
      {
        printf("Medju argumentima ima istih.\n");
        return 0;
      }
  }

  /* Ukoliko se prethodna petlja zavrsila, a nije se izaslo iz
     programa, znaci da medju argumentima nema istih. */
  printf("Medju argumentima nema istih.\n");
  
  return 0;
}
