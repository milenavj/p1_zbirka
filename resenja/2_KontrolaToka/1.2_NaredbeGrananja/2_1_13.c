#include <stdio.h>
#include <stdlib.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n;
  char jedinica, desetica, stotina;

  /* Ucitava se vrednost broja n. */
  printf("Unesite trocifreni brojedinica: ");
  scanf("%d", &n);

  /* Da bi program radio ispravno i za negativne brojeve, uzima se
     apsolutna vrednost broja n. */
  n = abs(n);

  /* Vrsi se provera ispravnosti ulaznih podataka. */
  if (n < 100 || n > 999) {
    printf("Greska: niste uneli trocifreni broj.\n");
    return -1;
  }

  /* Izdvajaju se cifre broja n. */
  jedinica = n % 10;
  desetica = (n / 10) % 10;
  stotina = n / 100;

  /* Ispis rezultata. */
  if (n == jedinica * jedinica * jedinica +
      desetica * desetica * desetica + stotina * stotina * stotina)
    printf("Broj je Armstrongov.\n");
  else
    printf("Broj nije Armstrongov.\n");

  return 0;
}
