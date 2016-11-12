#include <stdio.h>

int main()
{
  int dan, mesec, godina, dozvoljen_broj_dana;

  /* Citamo datum */
  printf("Unesite datum: ");
  scanf("%d.%d.%d", &dan, &mesec, &godina);

  /* Proveravamo godinu */
  if (godina < 0) {
    printf("Datum nije korektan (neispravna godina)!\n");
    return 0;
  }

  /* Proveravamo mesec */
  if (mesec < 1 || mesec > 12) {
    printf("Datum nije korektan (neispravan mesec)!\n");
    return 0;
  }

  /* Ako je mesec korektan, proveravamo broj dana */
  switch (mesec) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    /* Dozvoljeni broj dana za januar, mart, maj, jul, avgust,
       oktobar i decembar je 31 */
    dozvoljen_broj_dana = 31;
    break;
  case 2:
    /* Proveravamo da li je godina prestupna */
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
      /* Ako jeste, dozvoljeni broj dana za februar je 29 */
      dozvoljen_broj_dana = 29;
    else
      /* Ako nije, dozvoljeni broj dana za februar je 28 */
      dozvoljen_broj_dana = 28;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    /* Dozvoljeni broj dana za april, jun, septembar i novembar je
       30 */
    dozvoljen_broj_dana = 30;
    break;
  }
  /* Proveravamo dan */
  if (dan < 0 || dan > dozvoljen_broj_dana) {
    printf("Datum nije korektan (neispravan dan)!\n");
    return 0;
  }

  /* Sve provere su ispunjene pa zakljucujemo da je datum korektan */
  printf("Ispravan datum!\n");

  return 0;
}
