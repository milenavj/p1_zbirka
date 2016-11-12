/* Sa standardnog ulaza se unosi ceo broj n, a zatim i n karaktera. 
   Napisati program koji proverava da li se od unetih karaktera
   moze napisati rec Zima. */

#include <stdio.h>
#include <math.h>

int main()
{
  int n;
  int broj_Z, broj_i, broj_m, broj_a;
  char novi_red, c;
  int i;

  broj_Z = 0;
  broj_i = 0;
  broj_m = 0;
  broj_a = 0;

  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Ucitavanje karakter po karakter. */
  for (i = 0; i < n; i++) {
    printf("Unestite %d. karakter: ", i + 1);
    /* Prvo se cita belina koja se nalazi nakon prethodnog unosa,
       pa tek posle procitane beline se cita uneseni karakter. */
    scanf("%c%c", &novi_red, &c);

    /* Analiziramo karakter */
    switch (c) {
    case 'Z':
      broj_Z++;
      break;
    case 'i':
      broj_i++;
      break;
    case 'm':
      broj_m++;
      break;
    case 'a':
      broj_a++;
      break;
    }
  }

  /* Ako u unosu ima barem jedno veliko slovo z i barem po jedno
     malo slovo i, m i a, rec se moze napisati. A u suprotnom ne
     moze. */
  if (broj_Z && broj_i && broj_m && broj_a) {
    printf("Moze se napisati rec Zima.\n");
  } else {
    printf("Ne moze se napisati rec Zima.\n");
  }

  return 0;
}
