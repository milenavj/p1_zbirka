#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int dan, mesec, godina;
  int prethodni_dan, prethodni_mesec, prethodni_godina;

  /* Ucitavanje datuma. */
  printf("Unesite datum: ");
  scanf("%d.%d.%d.", &dan, &mesec, &godina);

  /* Racunanje dana, meseca i godine prethodnog dana. */
  prethodni_dan = dan - 1;
  prethodni_mesec = mesec;
  prethodni_godina = godina;

  /* Ako je potrebno, vrse se korekcije. */
  if (prethodni_dan == 0) {
    prethodni_mesec = mesec - 1;
    if (prethodni_mesec == 0) {
      prethodni_mesec = 12;
      prethodni_godina = godina - 1;
    }

    switch (prethodni_mesec) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      prethodni_dan = 31;
      break;
    case 2:
      if ((prethodni_godina % 4 == 0 && prethodni_godina % 100 != 0)
          || prethodni_godina % 400 == 0)
        prethodni_dan = 29;
      else
        prethodni_dan = 28;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      prethodni_dan = 30;
    }
  }

  /* Ispis rezultata. */
  printf("Prethodni datum: %d.%d.%d.\n",
         prethodni_dan, prethodni_mesec, prethodni_godina);

  return 0;
}
