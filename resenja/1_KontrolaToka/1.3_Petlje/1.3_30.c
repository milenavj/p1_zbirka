#include <stdio.h>
#include <math.h>

int main()
{
  int x;
  int broj_cifara;
  int min_stepen, max_stepen;
  int pom;
  int leva_cifra, desna_cifra;
  int indikator;

  printf("Unesite broj: ");
  scanf("%d", &x);

  /* Ako je korisnik uneo negativan broj, analizira se njegova
     apsolutna vrednost. */
  if (x < 0)
    x = -x;

  /* Odredjuje se broj cifara u zapisu broja x da bi moglo da se
     izdvajaju istovremeno cifre i sa leve i sa desne strane. */
  broj_cifara = 0;
  pom = x;
  while (pom > 0) {
    pom /= 10;
    broj_cifara++;
  }

  /* Odredjuje se stepen koji stoji uz krajnju levu cifru broja. */
  max_stepen = (int) pow(10, broj_cifara - 1);

  /* Indikator je promenljiva koja ukazuje da li je broj palindrom
     ili ne. */
  indikator = 1;
  while (x != 0 && indikator == 1) {
    /* Izdvaja se leva cifra. */
    leva_cifra = x / max_stepen;
    /* Izdvaja se desna cifra. */
    desna_cifra = x % 10;
    /* Ako su cifre razlicite, odmah se moze zakljuciti da broj
       nije palindrom i prekida se izvrsavanje petlje. */
    if (leva_cifra != desna_cifra) {
      indikator = 0;
      break;
    }
    /* Formira se nova vrednost broja x tako sto se odbacuje
       krajnja leva i krajnja desna cifra. */
    x = (x % max_stepen - x % 10) / 10;
    /* Koriguje se maksimalan stepen tako dobijenog broja - deli se 
       sa 100 jer su odbacene 2 cifre. */
    max_stepen = max_stepen / 100;
  }

  /* Ispisuje se rezultat. */
  if (indikator == 1)
    printf("Broj je palindrom!\n");
  else
    printf("Broj nije palindrom!\n");

  return 0;
}
