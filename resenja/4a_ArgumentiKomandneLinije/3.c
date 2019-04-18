#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  /* Deklaracije potrebnih promenljivih. */
  int n, i;

  /* Proverava se broj argumenata komandne linije. */
  if (argc != 2) 
  {
    printf("Greska: neispravan poziv.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitava se broj n i uzima se njegova apsolutna vrednost. */
  n = atoi(argv[1]);
  n = abs(n);

  /* Ispis rezultata. */
  for (i = (-1) * n; i <= n; i++)
    printf("%d ", i);
  printf("\n");

  return 0;
}
