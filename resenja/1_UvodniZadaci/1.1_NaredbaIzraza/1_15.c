#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, novibroj;
  unsigned int levi, desni, m;

  /* Ucitavaju se brojevi n i m. */
  printf("Unesite pozitivan ceo broj: ");
  scanf("%u", &n);
  printf("Unesite pozitivan dvocifreni broj:");
  scanf("%u", &m);

  /* Levi deo rezultata su sve cifre levo od cifre stotina.
     Na primer, ako je n=12345, levi deo rezultata je 12. 
     On se dobija deljenjem unetog broja sa 1000. */
  levi = n / 1000;
  
  /* Desni deo rezultata su sve cifre desno od cifre hiljada.
     Za n=12345, desni deo rezultata je 345. */
  desni = n % 1000;
  
  /* Srednji deo rezultata je broj m.
     U navedenom primeru, rezultat se dobija nadovezivanjem 
     brojeva 12, 67 i 345. Ovo se radi mnozenjem delova sa
     odgovarajucim stepenom broja 10 i njihovim sabiranjem. */
  novibroj = levi * 100000 + m * 1000 + desni;

  /* Ispis rezultata. */
  printf("Novi broj je %u\n", novibroj);

  return 0;
}
