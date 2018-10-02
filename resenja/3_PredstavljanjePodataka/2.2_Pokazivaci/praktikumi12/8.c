#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int indikator = 0;
  int i,j;
  /*
    Ukoliko imamo samo jedan argument komandne linije,
    ispisujemo da nema istih i zavrsavamo program.
  */
  if(argc < 2)
  {
    printf("Medju argumentima nema istih.\n");
    return -1;
  }

  /*
    Prolazimo kroz niz argumenata i za svaki posebno proverimo
    da li medju ostalima postoji neki koji mu je jednak i ako postoji
    ispisujemo poruku i zavrsavamo program.
    Ako smo izasli iz prve petlje to znaci da nismo pronasli dva ista elementa
    i ispisujemo odgovarajucu poruku.
  */
  for(i=0;i<argc;i++)
  {
    for(j=0;j != i && j<argc; j++)
      if(strcmp(argv[i], argv[j]) == 0)
      {
        printf("Medju argumentima ima istih.\n");
        return 0;
      }
  }

  printf("Medju argumentima nema istih.\n");
  return 0;
}
