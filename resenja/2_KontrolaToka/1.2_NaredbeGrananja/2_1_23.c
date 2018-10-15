#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int dan;

  /* Ucitava se redni broj dana u nedelji. */
  printf("Unesite broj: ");
  scanf("%d", &dan);


  switch (dan) {
  case 1:
    /* Ako dan ima vrednost 1, ispisuje se ponedeljak. */
    printf("ponedeljak\n");

    /* Ako se naredba break ne navede, izvrsice se i sledeca
       naredba, tj. ispis ce biti "ponedeljak utorak". */
    break;
  case 2:
    /* Postupak se ponavlja i za ostale dane. */
    printf("utorak\n");
    break;
  case 3:
    printf("sreda\n");
    break;
  case 4:
    printf("cetvrtak\n");
    break;
  case 5:
    printf("petak\n");
    break;
  case 6:
    printf("subota\n");
    break;
  case 7:
    printf("nedelja\n");
    break;
  default:
    /* Ako vrednost promenljive dan nije ni jedna od vrednosti
       izmedju 1 i 7, onda je uneta vrednost neispravna. */
    printf("Greska: neispravan unos dana.\n");
  }

  return 0;
}
