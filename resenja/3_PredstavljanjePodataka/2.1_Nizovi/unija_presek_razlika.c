#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAKS 500

/* Funkcija koja ucitava elemenate niza i vrsi proveru ispravnosti
   ulaza. Kao povratnu vrednost vraca dimenziju ucitanog niza. */
int ucitavanje(int niz[])
{
  int i, n;

  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Nedozvoljena dimenzija niza.\n");
    exit(EXIT_FAILURE);
  }

  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &niz[i]);

  return n;
}

/* Funkcija koja vraca 1 ukoliko broj x postoji u nizu, 0 inace. */
int postoji(int niz[], int n, int x)
{
  int i;

  for (i = 0; i < n; i++)
    if (niz[i] == x)
      return 1;

  return 0;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS], b[MAKS], unija[2 * MAKS], presek[MAKS],
      razlika[MAKS];
  int i, n_a, n_b, n_unija, n_presek, n_razlika;

  /* Unose se dva niza. */
  n_a = ucitavanje(a);
  n_b = ucitavanje(b);

  /* Brojaci elemenata u nizovima unija, presek i razlika. */
  n_unija = 0;
  n_presek = 0;
  n_razlika = 0;

  for (i = 0; i < n_a; i++) {
    /* Ukoliko se element a[i] ne nalazi u uniji, dodaje se u uniju 
       i povecaca se brojac elemenata u nizu unija. */
    if (postoji(unija, n_unija, a[i]) == 0) {
      unija[n_unija] = a[i];
      n_unija++;
    }

    /* Ukoliko se element a[i] nalazi u nizu b i ne postoji u nizu
       presek, dodaje se presek i povecava se brojac elemenata u
       nizu presek. */
    if (postoji(b, n_b, a[i]) == 1
        && postoji(presek, n_presek, a[i]) == 0) {
      presek[n_presek] = a[i];
      n_presek++;
    }

    /* Ukoliko element a[i] ne postoji u nizu b i ne postoji u nizu 
       razlika, dodaje se u razliku i povecava se brojac elemenata
       u nizu razlika. */
    if (postoji(b, n_b, a[i]) == 0
        && postoji(razlika, n_razlika, a[i]) == 0) {
      razlika[n_razlika] = a[i];
      n_razlika++;
    }
  }

  /* Elemente niza b koji nisu uneti u uniju dodaju se u uniju. */
  for (i = 0; i < n_b; i++)
    if (postoji(unija, n_unija, b[i])) {
      unija[n_unija] = b[i];
      n_unija++;
    }

  /* Ispis rezultata. */
  printf("Unija: ");
  for (i = 0; i < n_unija; i++)
    printf("%d ", unija[i]);
  printf("\nPresek: ");
  for (i = 0; i < n_presek; i++)
    printf("%d ", presek[i]);
  printf("\nRazlika: ");
  for (i = 0; i < n_razlika; i++)
    printf("%d ", razlika[i]);

  exit(EXIT_SUCCESS);
}
