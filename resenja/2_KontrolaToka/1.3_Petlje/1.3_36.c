#include <stdio.h>

int main()
{
  /* Promenljiva i je brojac. */
  int n, i;
  /* Brojaci za svaki od samoglasnika. */
  int broj_a = 0, broj_e = 0, broj_i = 0, broj_o = 0, broj_u = 0;
  /* Promenljiva c je tekuci ucitani karakter. */
  char c, belina;

  printf("Unesite broj n: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Neispravan unos.\n");
    return -1;
  }

  for (i = 0; i < n; i++) {
    /* Prvo se cita belina koja se nalazi nakon prethodnog unosa,
       pa tek posle procitane beline se cita uneseni karakter. */
    scanf("%c%c", &belina, &c);

    /* Provera da li je ucitani karakter samoglasnik. */
    switch (c) {
    case 'a':
    case 'A':
      broj_a++;
      break;
    case 'e':
    case 'E':
      broj_e++;
      break;
    case 'i':
    case 'I':
      broj_i++;
      break;
    case 'o':
    case 'O':
      broj_o++;
      break;
    case 'u':
    case 'U':
      broj_u++;
      break;
    }
  }

  printf("samoglasnik a: %d\n", broj_a);
  printf("samoglasnik e: %d\n", broj_e);
  printf("samoglasnik i: %d\n", broj_i);
  printf("samoglasnik o: %d\n", broj_o);
  printf("samoglasnik u: %d\n", broj_u);

  return 0;
}
