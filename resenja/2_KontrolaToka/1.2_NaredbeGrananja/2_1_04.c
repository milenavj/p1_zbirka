#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a, b, c, suma;

  /* Ucitavanje ulaznih vrednosti. */
  printf("Unesite tri cela broja:");
  scanf("%d%d%d", &a, &b, &c);

  /* Inicijalizovanje sume na nulu. */
  suma = 0;

  /* Na sumu se dodaju vrednosti onih brojeva cija je vrednost
     pozitivna. Uvecavanje je moguce uraditi na dva nacina: 
     I nacin: suma = suma + vrednost; 
     II nacin: suma += vrednost; */
  if (a > 0)
    suma = suma + a;

  if (b > 0)
    suma += b;

  if (c > 0)
    suma += c;

  /* Ispis rezultata. */
  printf("Zbir pozitivnih: %d\n", suma);

  return 0;
}
