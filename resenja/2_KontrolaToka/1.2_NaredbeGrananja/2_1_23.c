#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int dan;

  /* Ucitavanje rednog broja dana u nedelji. */
  printf("Unesite broj: ");
  scanf("%d", &dan);

  /*I nacin: koriscenjem if-else naredbe. 
  if(dan == 1)
    printf("ponedeljak\n");
  else if(dan == 2)
    printf("utorak\n");
  else if(dan == 3)
    printf("sreda\n");
  else if(dan == 4)
    printf("cetvrtak\n");
  else if(dan == 5)
    printf("petak\n");
  else if(dan == 6)
    printf("subota\n");
  else if(dan == 7)
    printf("nedelja\n");
  else
    printf("Greska: neispravan unos dana.\n"); */

  /* II nacin: koriscenjem switch naredbe.*/
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
