#include <stdio.h>

/* Funkcija broji koliko puta se realan broj x javlja u nizu unetih
   brojeva. */
int prebrojavanje(float x)
{
  float y;
  int broj_pojavljivanja = 0;

  /* Brojevi se ucitavaju sve do unosa broja nula. 
     Svaki put kada se unese broj koji je jednak broju x,
     brojac pojavljivanja se uveca za 1. */
  printf("Unesite brojeve:\n");
  while(1){
    scanf("%f", &y);
    
    if(y == 0)
      break;
    
    if (x == y)
      broj_pojavljivanja++;
  }

  return broj_pojavljivanja;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float x;
  int rezultat;

  /* Ucitava se vrednost broja x. */
  printf("Unesite broj x: ");
  scanf("%f", &x);

  /* Poziva se napisana funkcija i u promenljivoj rezultat se
     cuva njena povratna vrednost. */
  rezultat = prebrojavanje(x);
  
  /* Ispis rezultata. */
  printf("Broj pojavljivanja broja %.2f: %d\n", x, rezultat);

  return 0;
}
