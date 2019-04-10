#include <stdio.h>
#include <stdlib.h>

#define MAKS_IME 21
#define BROJ_OCENA 9
#define MAKS_DJAKA 30

typedef struct 
{
  char ime[MAKS_IME];
  int ocena[BROJ_OCENA];
} 
Djak;

/* Funkcija proverava ispravnost date ocene. */
void provera_ocene(int ocena)
{
  if (ocena < 1 || ocena > 5) 
  {
    printf("Greska: neispravna ocena.\n");
    exit(EXIT_FAILURE);
  }
}

/* Funkcija ucitava podatke o djacima u niz. */
int ucitaj(Djak niz[])
{
  int i,j;
  
  while (i < MAKS_DJAKA) 
  {
    printf("Unesite podatke o djaku: ");
    /* Ucitavanje imena. */
    if(scanf("%s", niz[i].ime) == EOF)
        break;
    
    /* Ucitavanje ocena. */
    for (j = 0; j < BROJ_OCENA; j++) 
    {
      scanf("%d", &niz[i].ocena[j]);
      provera_ocene(niz[i].ocena[j]);
    }

    i++;
  }
  
  return i;
}

/* Funkcija racuna prosecnu ocenu datog djaka. */
float prosecna_ocena(const Djak* djak)
{
  int j;
  float suma = 0;
  for (j = 0; j < BROJ_OCENA; j++)
    suma += djak->ocena[j];

  return suma / BROJ_OCENA;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  Djak niz[MAKS_DJAKA];
  int i = 0, n, j;
  float prosek;

  /* Ucitavanje podataka o djacima. */
  n = ucitaj(niz);

  /* Ispisivanje imena nedovoljnih ucenika. */
  printf("\n\nNEDOVOLJNI: ");
  for (i = 0; i < n; i++)
    for (j = 0; j < 9; j++)
      if (niz[i].ocena[j] == 1) {
        printf("%s ", niz[i].ime);
        break;
      }
  printf("\n");

  /* Ispisivanje imena odlicnih ucenika. */
  printf("ODLICNI: ");
  for (i = 0; i < n; i++) 
  {
    prosek = prosecna_ocena(&niz[i]);
    if (prosek >= 4.5)
      printf("%s ", niz[i].ime);
  }
  printf("\n");

  return 0;
}
