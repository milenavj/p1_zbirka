#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracija i inicijalizacija potrebnih promenljivih. */
  int n, i;
  int broj_Z = 0, broj_i = 0, broj_m = 0, broj_a = 0;
  char novi_red, c;

  /* Ucitava se broj karaktera. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */  
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Ucitavaju se karakteri. */
  for (i = 1; i <= n; i++) {
    printf("Unestite %d. karakter: ", i);
    
    /* Prvo se cita belina koja se nalazi nakon prethodnog unosa,
       pa tek posle procitane beline se cita uneseni karakter. */
    scanf("%c%c", &novi_red, &c);

    /* Obradjuje se ucitani karakter. */
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

  /* Ako su svi brojaci razliciti od nule, rec "Zima" se moze
     napisati pomocu unetih karaktera. */
  if (broj_Z && broj_i && broj_m && broj_a)
    printf("Moze se napisati rec Zima.\n");
  else
    printf("Ne moze se napisati rec Zima.\n");

  return 0;
}
