#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int godina;
  int mesec;
  int prestupna;

  /* Ucitava se vrednost godine. */
  printf("Unesite godinu: ");
  scanf("%d", &godina);

  /* Vrsi se provera ispravnosti ulaznih podataka. */
  if (godina < 0) {
    printf("Greska: neispravan unos godine.\n");
    return -1;
  }

  /* Vrsi se provera da li je godina prestupna, zbog februara */
  if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
    prestupna = 1;
  else
    prestupna = 0;

  /* Ucitava se redni broj meseca. */
  printf("Unesite redni broj meseca: ");
  scanf("%d", &mesec);

  /* U zavisnosti od vrednosti meseca, ispisuje se odgovarajuci
     rezultat. */
  switch (mesec) {
  case 1:
    printf("Januar, 31 dan\n");
    break;
  case 2:
    if (prestupna)
      printf("Februar, 29 dana\n");
    else
      printf("Februar, 28 dana\n");
    break;
  case 3:
    printf("Mart, 31 dan\n");
    break;
  case 4:
    printf("April, 30 dana\n");
    break;
  case 5:
    printf("Maj, 31 dan\n");
    break;
  case 6:
    printf("Jun, 30 dana\n");
    break;
  case 7:
    printf("Jul, 31 dan\n");
    break;
  case 8:
    printf("Avgust, 31 dan\n");
    break;
  case 9:
    printf("Septembar, 30 dana\n");
    break;
  case 10:
    printf("Oktobar, 31 dan\n");
    break;
  case 11:
    printf("Novembar, 30 dana\n");
    break;
  case 12:
    printf("Decembar, 31 dan\n");
    break;
  default:
    printf("Greska: neispravan unos meseca.\n");
    return -1;
  }

  return 0;
}
