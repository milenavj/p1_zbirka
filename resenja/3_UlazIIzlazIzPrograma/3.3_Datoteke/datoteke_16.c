#include <stdio.h>
#include <stdlib.h>

#define MAKS_DIM 50

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz;
  float a[MAKS_DIM][MAKS_DIM];
  int i, j, n, m, k, l, suma = 0;

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen("matrica.txt", "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Ucitavanje dimenzija matrice i provera ispravnosti. */
  fscanf(ulaz, "%d%d", &n, &m);
  if (n <= 0 || n > MAKS_DIM || m <= 0 || m > MAKS_DIM)
    greska("Greska: neispravne dimenzije matrice.");

  /* Ucitavanje elemenata matrice. */
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      fscanf(ulaz, "%f", &a[i][j]);

  /* Za svaku poziciju (i,j) vrsi se provera trazenog uslova. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      /* Za poziciju (i,j) racuna se suma suseda. Ona se moze
         dobiti kao suma podmatrice 3*3 ciji je gornji levi ugao
         (i-1, j-1), a donji desni (i+1, j+1). Pri racunanju ove
         sume treba voditi racuna da se ne izadje iz granica
         originalne matrice. */
      suma = 0;
      for (k = i - 1; k <= i + 1; k++) {
        for (l = j - 1; l <= j + 1; l++) {
          /* Ako se nije izaslo iz granica originalne matrice,
             vrednost a[k][l] se dodaje na sumu. */
          if (k >= 0 && k < n && l >= 0 && l < m)
            suma += a[k][l];
        }
      }

      /* Kako suma ukljucuje i centralni element (i,j), njega je
         potrebno oduzeti jer je potrebno sumirati samo njegove
         susede. */
      suma -= a[i][j];

      /* Ako je suma suseda elementa a[i][j] jednaka njegovoj
         vrednosti, odgovarajuce pozicije i vrednost elementa se
         ispisuju na standardni izlaz. */
      if (a[i][j] == suma)
        printf("(%d, %d, %g)\n", i, j, a[i][j]);
    }
  }

  /* Zatvaranje datoteke. */
  fclose(ulaz);
  
  exit(EXIT_SUCCESS);
}
