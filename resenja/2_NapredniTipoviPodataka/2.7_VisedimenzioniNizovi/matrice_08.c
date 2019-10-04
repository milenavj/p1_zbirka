#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(int a[][MAKS], int n) {
  int i, j;
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}

/* Relacija je refleksivna ukoliko je za svako i a[i][i] = 1.
   Funkcija proverava da li je relacija zadata matricom a
   refleksivna i vraca 1 ukoliko jeste, a 0 inace. */
int refleksivna(int a[][MAKS], int n) {
  int i;
  for (i = 0; i < n; i++)
    if (a[i][i] != 1)
      return 0;

  return 1;
}

/* Relacija je simetricna ukoliko za svaki par i, j vazi da je
   a[i][j] = a[j][i]. Funkcija proverava da li je relacija zadata
   matricom a simetricna i vraca 1 ukoliko jeste, a 0 inace. */
int simetricna(int a[][MAKS], int n) {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if (a[i][j] != a[j][i])
        return 0;

  return 1;
}

/* Relacija je tranzitivna ukoliko za svaku trojku i, j, k vazi da
   ako je a[i][j] = 1 i a[j][k] = 1, onda je i a[i][k] = 1.
   Funkcija proverava da li je relacija zadata matricom a
   tranzitivna i vraca 1 ukoliko jeste, a 0 inace. */
int tranzitivna(int a[][MAKS], int n) {
  int i, j, k;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      for (k = 0; k < n; k++)
        if (a[i][j] == 1 && a[j][k] == 1 && a[i][k] == 0)
          return 0;

  return 1;
}

/* Relacija je relacija ekvivalencije ukoliko je refleksivna,
   simetricna i tranzitivna. Funkcija proverava da li je relacija
   zadata matricom a relacija ekvivalencije i vraca 1 ukoliko
   jeste, a 0 inace. */
int ekvivalencija(int a[][MAKS], int n) {
  if (refleksivna(a, n) && simetricna(a, n) && tranzitivna(a, n))
    return 1;

  return 0;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int n;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite broj vrsta matrice: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, n);

  /* Racunanje i ispis rezultata. */
  if (refleksivna(a, n))
    printf("Relacija jeste refleksivna.\n");
  else
    printf("Relacija nije refleksivna.\n");

  if (simetricna(a, n))
    printf("Relacija jeste simetricna.\n");
  else
    printf("Relacija nije simatricna.\n");

  if (tranzitivna(a, n))
    printf("Relacija jeste tranzitivna.\n");
  else
    printf("Relacija nije tranzitivna.\n");

  if (ekvivalencija(a, n))
    printf("Relacija jeste ekvivalencija.\n");
  else
    printf("Relacija nije ekvivalencija.\n");

  exit(EXIT_SUCCESS);
}
