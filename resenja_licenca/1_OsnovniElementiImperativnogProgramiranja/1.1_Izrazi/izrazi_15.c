/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int n, novi_broj;
  unsigned int levi, desni, m;

  /* Ucitavanje brojeva n i m. */
  printf("Unesite pozitivan ceo broj: ");
  scanf("%u", &n);
  printf("Unesite pozitivan dvocifreni broj: ");
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
     brojeva 12, 67 i 345. Ovo se radi mnozenjem delova
     odgovarajucim stepenom broja 10 i njihovim sabiranjem. */
  novi_broj = levi * 100000 + m * 1000 + desni;

  /* Ispis rezultata. */
  printf("Rezultat: %u\n", novi_broj);

  return 0;
}
