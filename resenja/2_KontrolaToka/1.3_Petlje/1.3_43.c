#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int i;
  float suma;
  float x, eps, clan;

  /* Ucitavaju se vrednosti x i eps. */
  printf("Unesite x: ");
  scanf("%f", &x);

  printf("Unesite tacnost eps: ");
  scanf("%f", &eps);

  /* Inicijalizacije. */
  suma = 0;
  clan = 1;
  i = 1;

  /* Kako clanovi sume mogu biti negativni, potrebno je posmatrati
     apsolutnu vrednost clana. */
  while (fabs(clan) > eps) {
    suma += clan;

    /* U svakoj iteraciji se racuna novi clan i mnozi se sa -1.
       Na taj nacin se postize da je vrednost clana naizmenicno
       pozitivna i negativna. */
    clan = clan * x / i;
    clan *= -1;

    i++;
  }

  /* Ispis rezultata. */
  printf("S=%f\n", suma);

  return 0;
}
