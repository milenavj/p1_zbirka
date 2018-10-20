#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int x;
  int najmanji, najveci;

  printf("Unesite brojeve: ");
  /* Prvi broj se ucitava izvan petlje zbog inicijalizacije
     najvece i najmanje vrednosti. 
     Napomena: Ovde bi inicijalizacija najveci=-1 bila pogresna
     jer moze da se desi da su svi uneti brojevi negativni i manji
     od -1 i onda bi najveci i nakon izvrsavanja tela petlje ostao
     -1. */
  scanf("%d", &x);
  najveci = x;
  najmanji = x;

  if(x == 0)
  {
    printf("Nisu unete nadmorske visine.");
    return 0;
  }
  
  /* Za svaki ucitani broj se proverava da li je manji od najmanjeg
     ili veci od najveceg i vrsi se azuriranje odgovarajucih
     vrednosti. Petlja se prekida kada se unese broj 0.*/
  while (1) {
    scanf("%d", &x);
    
    if(x == 0)
        break;
    
    if (x > najveci)
      najveci = x;

    if (x < najmanji)
      najmanji = x;
  }
  
  /* Ispis rezultata. */
  printf("Razlika: %d\n", najveci - najmanji);

  return 0;
}
