#include <stdio.h>
int main()
{
  int x;

  /* U promenljivoj p se cuva prozivod. */
  int p;

  /* Promenljiva u sluzi za proveru da li su brojevi uopste
     uneseni. Na pocetku se pretpostavlja da nisu i postavlja se na 
     0. */
  int u = 0;

  /* Promenljiva unesen_pozitivan sluzi za proveru da li su
     pozitivni brojevi uopste uneseni. Na pocetku se pretpostavlja
     da nisu i postavlja se na 0. */
  int unesen_pozitivan = 0;

  p = 1;

  /* Izraz 1 je konstantan, razlicit je od nule sto znaci da je to
     tacan izraz. Uslov petlje je uvek tacan! */
  printf("Unesite brojeve:");

  while (1) {
    scanf("%d", &x);

    /* Proveravanje da li je uneta nula. */
    if (x == 0)

      /* Naredba break prekida petlju. Izvrsavanje se nastavlja od 
         prve naredbe nakon petlje. */
      break;

    /* Ako je makar 1 broj razlicit od 0 promenljiva u ce biti
       postavljena na 1. */
    u = 1;

    /* Ako je unet negativan broj, taj broj se ne mnozi sa ukupnim
       proizvodom p; zato se nastavlja dalje. */
    if (x < 0)
      /* Naredba continue prekida trenutnu iteraciju petlje tako
         sto preskace sve naredbe koje nakon njega slede.
         Izvrsavanje se nastavlja od provere uslova petlje. */
      continue;

    /* Ako je makar jedan broj pozitivan, promenljiva
       unesen_pozitivan se postavja na 1. */
    unesen_pozitivan = 1;
    p = p * x;
  }

  if (u == 0)
    printf("Nisu uneseni brojevi.\n");
  else if (unesen_pozitivan == 0)
    printf("Nisu uneseni pozitivni brojevi. \n");
  else
    printf("Proizvod pozitivnih unetih brojevi je %d.\n", p);

  return 0;
}
