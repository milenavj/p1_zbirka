#include <stdio.h>

int main()
{
  int a, b, max;
  printf("Unesite dva cela broja:");
  scanf("%d%d", &a, &b);

  /* Ternarni operator uslova :? koristi se u sledecem obliku:

     izraz1 ? izraz2 : izraz3;

     Izraz izraz1 se izracunava prvi. Ako je njegova vrednost
     razlicita od nule (tj. ako ima istinitosnu vrednost tacno),
     onda se izracunava vrednsot izraza izraz2 i to je vrednost
     citavog uslovnog izraza. U suprotnom, izracunava se vrednost
     izraz3 i to je vrednost citavog uslovnog izraza
  */

  max = (a > b) ? a : b;

  printf("Maksimum je %d\n", max);

  return 0;
}
