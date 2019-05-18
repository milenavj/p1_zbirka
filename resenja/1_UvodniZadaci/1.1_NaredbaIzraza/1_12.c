#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int x, obrnuto_x;
  char cifra_jedinice, cifra_desetice, cifra_stotine;

  /* Ucitavanje neoznacenog trocifrenog broja. */
  printf("Unesite trocifreni broj: ");
  scanf("%u", &x);

  /* Izdvajanje pojedinacnih cifara broja. */
  cifra_jedinice = x % 10;
  cifra_desetice = (x / 10) % 10;
  cifra_stotine = x / 100;

  /* Formiranje rezultujuceg broja. */
  obrnuto_x = cifra_jedinice * 100 + cifra_desetice * 10 + cifra_stotine;

  /* Ispis rezultata. */
  printf("Obrnuto: %u\n", obrnuto_x);

  return 0;
}
