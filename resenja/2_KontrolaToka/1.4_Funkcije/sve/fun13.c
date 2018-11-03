#include <stdio.h>
#include <stdlib.h>

/* Funkcija proverava da li su sve cifre broja x parne i vraca
   1 ako je uslov ispunjen i 0 ako nije. */
int sve_parne_cifre(int x)
{ 
  char cifra;
  x = abs(x);

  /* Ako se naidje na cifru koja nije parna, onda se kao povratna
     vrednost funkcije vraca 0. */
  while (x > 0) {
    cifra = x % 10;
    if (cifra % 2 == 1)
      return 0;
    x /= 10;
  }

  /* Ako se doslo do kraja petlje, znaci da se nije naislo ni na
     jednu neparnu cifru, sto znaci da su sve cifre parne i da 
     treba da se vrati 1. */
  return 1;
}

/* Funkcija proverava da li su sve cifre broja x jednake i vraca
   1 ako jesu, a 0 u suprotnom. */
int sve_cifre_jednake(int x)
{
  char poslednja_cifra;
  x = abs(x);
  
  /* Izdvaja se poslednja cifra broja. */
  poslednja_cifra = x % 10;
  x /= 10;

  /* Za sve ostale cifre se proverava da li su jednake poslednjoj.
     Ako se naidje na neku koja nije, onda nisu sve cifre broja
     x jednake i kao povratna vrednost se vraca 0. */
  while (x) {
    if (x % 10 != poslednja_cifra)
      return 0;

    x /= 10;
  }

  /* Ako se stiglo do kraja petlje, znaci da su sve cifre broja
     bile jednake poslednjoj cifri, pa se kao povratna vrednost
     vraca 1. */
  return 1;
}

int main()
{
  /* Deklaracija potrebne promenljive. */
  int x;

  /* Ucitava se broj x. */
  printf("Unesite broj:");
  scanf("%d", &x);

  /* U zavisnosti od povratne vrednosti napisanih funkcija
     vrsi se ispis odgovarajucih poruka. */
  if (sve_parne_cifre(x))
    printf("Sve cifre broja su parne.\n");
  else
    printf("Broj sadrzi bar jednu neparnu cifru.\n");

  if (sve_cifre_jednake(x))
    printf("Cifre broja su jednake.\n");
  else
    printf("Cifre broja nisu jednake.\n");

  return 0;
}
