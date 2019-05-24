#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 31

/* Funkcija ispisuje odgovarajucu poruku na standardni izlaz za greske i prekida izvrsavanje programa. */
void greska()
{
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
  /* Deklaracije potrebnih promenljivih. */
  int godina;
  int tekuca_godina;
  char ime[MAX];
  char tekuce_ime[MAX];

  /* Proverava broja argumenata komandne linije. */
  if (argc != 3)
  {
    greska();
  }

  /* Provera da li je prvi argument komandne linije -y. */
  if (!strcmp(argv[1], "-y"))
  {
    /* Ako jeste, ocitava se godina koja se ocekuje kao drugi argument. */
    godina = atoi(argv[2]);

    /* Sve do kraja unosa ucitavaju se podaci o osvajacima. */
    while (scanf("%d %s", &tekuca_godina, tekuce_ime) == 2)
    {
      /* Ako uneta godina odgovara trazenoj godini, ispisuje se ime osvajaca. */
      if (tekuca_godina == godina)
      {
        printf("%s\n", tekuce_ime);
      }
    }

    exit(EXIT_SUCCESS);
  }

  /* Provera da li je prvi argument komandne linije -w. */
  if (!strcmp(argv[1], "-w"))
  {
    /* Ako jeste, ocitava se ime osvajaca koje se ocekuje kao drugi argument. */
    strcpy(ime, argv[2]);

    /* Sve do kraja unosa ucitavaju se podaci o osvajacima. */
    while (scanf("%d %s", &tekuca_godina, tekuce_ime) == 2)
    {
      /* Ako uneto ime odgovara imenu osvajaca, ispisuje se godina. */
      if (!strcmp(ime, tekuce_ime)){
        printf("%d ", tekuca_godina);
      }
    }
    putchar('\n');

    exit(EXIT_SUCCESS);
  }

  /* Ako prvi argument komandne linije nije ni -y ni -w, program nije korektno pozvan. */
  greska();

}
