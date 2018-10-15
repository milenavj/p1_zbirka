#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  char c1, c2, c3;
  unsigned int broj_cifara = 0;
  unsigned int proizvod_cifara = 1;

  /* Ucitavaju se tri karaktera. */
  printf("Unesite karaktere: ");
  scanf("%c %c %c", &c1, &c2, &c3);

  /* Racuna se proizvod onih karaktera koji su cifre. */
  if (c1 >= '0' && c1 <= '9') {
    proizvod_cifara *= (c1 - '0');
    broj_cifara++;
  }

  if (c2 >= '0' && c2 <= '9') {
    proizvod_cifara *= (c2 - '0');
    broj_cifara++;
  }

  if (c3 >= '0' && c3 <= '9') {
    proizvod_cifara *= (c3 - '0');
    broj_cifara++;
  }

  /* Ispis rezultata. */
  if (broj_cifara == 0)
    printf("Medju unetim karakterima nema cifara.\n");
  else
    printf("Proizvod cifara: %u\n", proizvod_cifara);

  return 0;
}
