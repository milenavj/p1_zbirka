#include <stdio.h>
#include <stdlib.h>

/* Funkcija koja ucitava karakter po karakter sa ulaza i prebrojava
   koliko puta se pojavio karakter '.' i koliko puta se pojavio
   karakter ','. Ucitavanje se zaustavlja kada se dodje do kraja
   ulaza (EOF-a). */
void interpunkcija(int *br_tacaka, int *br_zareza) 
{
  /* Deklaracije i inicijalizacije pomocnih promenljivih. */
  int tacke = 0, zarezi = 0;
  char c;

  /* Ucitavanje i prebrojavanje trazenih karaktera. */
  while ((c = getchar()) != EOF) 
  {
    if (c == '.')
      tacke++;

    if (c == ',')
      zarezi++;
  }

  /* Smestanje rezultata na prosledjene adrese. */
  *br_tacaka = tacke;
  *br_zareza = zarezi;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int br_tacaka, br_zareza;

  /* Ucitavanje i obrada teksta. */
  printf("Unesite tekst: \n");
  interpunkcija(&br_tacaka, &br_zareza);

  /* Ispis rezultata. */
  printf("Broj tacaka: %d\n", br_tacaka);
  printf("Broj zareza: %d\n", br_zareza);

  exit(EXIT_SUCCESS);
}