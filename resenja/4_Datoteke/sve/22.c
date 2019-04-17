#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_IME 5

typedef struct 
{
  unsigned int a, b;
  char ime[MAKS_IME];
} Pravougaonik;

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
  /* Deklaracije potrebnih promenljivih. */
  unsigned int max_pov = 0;
  Pravougaonik p;
  
  /* Proverava se broj argumenata komandne linije. */
  if (argc != 2)
    greska("Greska: neispravan poziv.\n");

  /* Ulazna datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */  
  FILE *ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.\n");

  /* Iz datoteke se citaju podaci o pravougaonicima. */
  while (fscanf(ulaz, "%u%u%s", &p.a, &p.b, p.ime) == 3) 
  {
    /* Vrsi se provera ispravnosti duzina stranica. */
    if (p.a == 0 || p.b == 0)
      greska("Greska: duzina stranice ne moze biti 0.\n");

    if (p.a == p.b)
    {
      /* Ako je u pitanju kvadrat, njegovo ime se ispisuje na
         standardni izlaz. */
      printf("%s ", p.ime);
    }
    else 
    {
      /* Ako je u pitanju pravougaonik, njegova povrsina se poredi
         sa maksimalnom. */
      if (p.a * p.b > max_pov)
        max_pov = p.a * p.b;
    }
  }

  /* Ukoliko je bilo ucitanih pravougaonika, ispisuje se povrsina
     najveceg. */
  if (max_pov != 0)
    printf("Maksimalna povrsina: %u\n", max_pov);
  else
    printf("\n");

  /* Zatvara se datoteka. */ 
  fclose(ulaz);
  return 0;
}
