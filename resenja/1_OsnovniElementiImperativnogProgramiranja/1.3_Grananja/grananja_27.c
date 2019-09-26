#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int dan, mesec, godina, dozvoljeni_broj_dana;

  /* Ucitavanje datuma. */
  printf("Unesite datum: ");
  scanf("%d.%d.%d", &dan, &mesec, &godina);

  /* Provera korektnosti vrednosti unete godine. */
  if (godina < 0) {
    printf("Datum nije korektan.\n");
    return 0;
  }

  /* Provera korektnosti vrednosti unetog meseca. */
  if (mesec < 1 || mesec > 12) {
    printf("Datum nije korektan.\n");
    return 0;
  }

  /* Provera korektnosti vrednosti unetog dana. */
  switch (mesec) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    /* Dozvoljeni broj dana za januar, mart, maj, jul, avgust,
       oktobar i decembar je 31. */
    dozvoljeni_broj_dana = 31;
    break;
  case 2:
    /* Dozvoljeni broj dana za februar je 28 ili 29 u zavisnosti od 
       toga da li je godina prestupna ili ne. */
    if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
      dozvoljeni_broj_dana = 29;
    else
      dozvoljeni_broj_dana = 28;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    /* Dozvoljeni broj dana za april, jun, septembar i novembar je
       30. */
    dozvoljeni_broj_dana = 30;
    break;
  }

  if (dan < 0 || dan > dozvoljeni_broj_dana) {
    printf("Datum nije korektan.\n");
    return 0;
  }

  /* Kako su sve provere korektnosti prosle, datum se smatra
     korektnim. */
  printf("Datum je korektan.\n");

  return 0;
}
