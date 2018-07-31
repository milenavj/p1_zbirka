#include <stdio.h>

/* Funkcija racuna faktorijel broja. */
int faktorijel(int x) {

  int f = 1;
  while(x) { 
    f *= x;
    x--; 
  }
  return f;
}

int main() {

  int x, y;
  
  printf("Unesite dva broja: ");
  scanf("%d%d", &x, &y);
  
  /* Faktorijel je funkcija koja veoma brzo raste, tj. s povecanjem broja x, drasticno brzo uvecava se i vrednost x!. Tip podatka int ima ogranicenje u velicini broja koji moze da sadrzi. Za 13! i vece, int ne bi mogao da sacuva sve cifre potrebne za zapis tako velikog broja, te bi doslo do prekoracenja. Faktorijel nije definisan nad skupom negativnih celih brojeva. */
  if(x < 0 || y < 0 || x > 12 || y > 12) {
    printf("Greska: pogresan unos!\n");
  }
  else{
  printf("%d\n", faktorijel(x) + faktorijel(y));
  }
  return 0;
}
