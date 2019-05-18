#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int dan, mesec;

  /* Ucitavanje datuma koji je zadat u formatu: dan.mesec. */
  printf("Unesite dan i mesec");
  scanf("%d.%d.", &dan, &mesec);

  /* Racunanje godisnjeg doba. */
  switch (mesec) {
  case 1:
  case 2:
    /* Ako je mesec januar ili februar, onda je sigurno u pitanju
       zima. */
    printf("zima\n");
    break;
  case 3:
    /* Ako je mesec mart, onda se godisnje doba odredjuje u
       zavisnosti od dana u mesecu. */
    if (dan < 21)
      printf("zima\n");
    else
      printf("prolece\n");
    break;
  case 4:
  case 5:
    /* Ako je mesec april ili maj, onda je sigurno u pitanju
       prolece. */
    printf("prolece\n");
    break;
  case 6:
    /* Ako je mesec jun, onda se godisnje doba odredjuje u
       zavisnosti od dana u mesecu. */
    if (dan < 21)
      printf("prolece\n");
    else
      printf("leto\n");
    break;
  case 7:
  case 8:
    /* Ako je mesec jul ili avgust, onda je sigurno u pitanju 
       leto. */
    printf("leto\n");
    break;
  case 9:
    /* Ako je mesec septembar, onda se godisnje doba odredjuje u
       zavisnosti od dana u mesecu. */
    if (dan < 23)
      printf("leto\n");
    else
      printf("jesen\n");
    break;
  case 10:
  case 11:
    /* Ako je mesec oktobar ili novembar, onda je sigurno u pitanju 
       jesen. */
    printf("jesen\n");
    break;
  case 12:
    /* Ako je mesec decembar, onda se godisnje doba odredjuje u
       zavisnosti od dana u mesecu. */
    if (dan < 22)
      printf("jesen\n");
    else
      printf("zima\n");
  }

  return 0;
}
