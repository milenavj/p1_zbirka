#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije n*n. */
void ucitaj(int a[][MAKS], int n)
{
  int i, j;
  
  printf("Unesite elemente matrice:\n");
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      scanf("%d", &a[i][j]);
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int n, i, j;
  int maksimalni_zbir, trenutni_zbir = 0, indeks_kolone;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite dimenziju matrice: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS)
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, n);

  /* Maksimalni zbir se inicijalizuje na vrednost zbira prve
     kolone. U ovom slucaju bi bilo pogresno da se maksimalni
     zbir inicijalizuje na nulu jer moze da se desi da su svi
     elementi matrice negativni.
     Drugi nacin da se ispravno inicijalizuje maksimalni zbir
     jeste da mu se dodeli vrednost konstante INT_MIN cija se
     definicija nalazi u zaglavlju limits.h. */
  for(i=0; i<n; i++)
      trenutni_zbir += a[i][0];

  maksimalni_zbir = trenutni_zbir;
  indeks_kolone = 0;

  /* Racuna se zbir svake sledece kolone i azurira se vrednost
     maksimalnog zbira. */
  for(j=1; j<n; j++)
  {
      /* Racuna se zbir kolone j. */
      trenutni_zbir = 0;
      for(i=0; i<n; i++)
          trenutni_zbir += a[i][j];

      /* Ukoliko je taj zbir veci od trenutno maksimalnog zbira, 
         azurira se vrednost maksimalnog zbira i pamti se tekuca
         kolona. */
      if (trenutni_zbir > maksimalni_zbir)
      {
          maksimalni_zbir = trenutni_zbir;
          indeks_kolone = j;
      }
  }

  /* Ispis rezultata. */
  printf("Indeks kolone je: %d\n", indeks_kolone);

  return 0;
}
