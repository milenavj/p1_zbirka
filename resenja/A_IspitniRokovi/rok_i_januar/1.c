#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int x, abs_x;
  int cifra_jedinica, cifra_desetica, cifra_stotina;

  /* Ucitavanje brojeva sve do kraja ulaza. */
  while (scanf("%d", &x) != EOF) {

    /* Izracunavanje apsolutne vrednosti tekuceg broja. */
    abs_x = x < 0 ? -x : x;

    /* Provera da li je u pitanju trocifren broj. */
    if (abs_x < 100 || abs_x > 999) {
      printf("-1\n");
      exit(EXIT_FAILURE);
    }

    /* Izdvajanje cifara broja. */
    cifra_jedinica = abs_x % 10;
    cifra_desetica = (abs_x / 10) % 10;
    cifra_stotina = abs_x / 100;

    /* Provera da li su cifre broja uredjene rastuce. */
    if (cifra_jedinica > cifra_desetica
        && cifra_desetica > cifra_stotina) {
      printf("%d ", x);
    }
  }
  printf("\n");

  exit(EXIT_SUCCESS);
}
