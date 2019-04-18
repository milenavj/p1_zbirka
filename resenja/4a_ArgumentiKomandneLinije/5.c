#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  /* Deklaracija potrebnih promenljivih. */
  int i, br = 0;
  
  /* Prebrojavaju se argumenti koji sadrze karakter @. */
  for (i = 1; i < argc; i++)
    if (strchr(argv[i], '@') != NULL)
      br++;

  /* Ispis rezultata. */
  printf("%d\n", br);

  return 0;
}
