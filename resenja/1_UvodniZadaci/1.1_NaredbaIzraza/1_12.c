#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int x;
  unsigned int obrnuto_x;
  char cifra_jedinice;
  char cifra_desetice;
  char cifra_stotine;

  /* Ucitava se neoznacen trocifreni broj. */
  printf("Unesite trocifreni broj: ");
  scanf("%u", &x);

  /* Izdvajaju se pojedinacne cifre broja. */
  cifra_jedinice = x % 10;
  cifra_desetice = (x / 10) % 10;
  cifra_stotine = x / 100;

  /* Formira se rezultujuci broj. */
  obrnuto_x = cifra_jedinice * 100 + cifra_desetice * 10 + cifra_stotine;

  /* Ispis rezultata. */
  printf("Obrnuto: %u\n", obrnuto_x);

  return 0;
}
