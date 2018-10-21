#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int format, i;
  double sirina, duzina, nova_duzina;

  /* Ucitava se format papira i vrsi se provera ispravnosti
     ulaza.*/
  printf("Unesite format papira: ");
  scanf("%d", &format);

  if (format < 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* duzina/sirina = 1/sqrt(2) 
     duzina*sirina = 1000mm x 1000mm
     ---
     duzina = sirina/sqrt(2)
     duzina*sirina = 1000mm x 1000mm
     ---
     sirina*sirina/sqrt(2) = 1000*1000
     sirina*sirina = sqrt(2) * 1000 * 1000
     sirina = sqrt(sqrt(2) * 1000 * 1000)
     ---
     duzina = sirina/sqrt(2) */
  sirina = sqrt(1000 * 1000 * sqrt(2));
  duzina = sirina / sqrt(2);

  /* U petlji se racunaju duzina i sirina za uneti format. */
  for (i = 1; i <= format; i++) {
    nova_duzina = sirina / 2;
    sirina = duzina;
    duzina = nova_duzina;
  }

  /* Ispis rezultata. Napomena: duzina i sirina celi brojevi. */
  printf("%d %d\n", (int) duzina, (int) sirina);

  return 0;
}