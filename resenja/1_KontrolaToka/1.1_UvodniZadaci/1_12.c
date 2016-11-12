#include <stdio.h>

int main()
{
  unsigned x;
  unsigned obrnuto_x;
  char cifra_jedinice;
  char cifra_desetice;
  char cifra_stotine;

  printf("Unesi trocifreni broj:");
  scanf("%u", &x);

  cifra_jedinice = x % 10;
  cifra_desetice = (x / 10) % 10;
  cifra_stotine = x / 100;

  obrnuto_x = cifra_jedinice * 100 +
      cifra_desetice * 10 + cifra_stotine;

  printf("Obrnuto: %u\n", obrnuto_x);

  return 0;
}
