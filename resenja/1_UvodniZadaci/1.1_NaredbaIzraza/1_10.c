#include <stdio.h>

int main()
{
  /* Deklaracija promenljive u koju ce se upisati pozitivan trocifren broj. */
  unsigned int x;

  /* Promenljive koje cuvaju cifre treba da budu najmanjeg celobrojnog tipa jer nece sadrzati druge vrednosti osim jednocifrenih celih brojeva. Zbog toga se koristi tip char. */
  char cifra_jedinice, cifra_desetice, cifra_stotine;

  /* Ucitava se trocifren broj. */
  printf("Unesite trocifreni broj: ");
  scanf("%u", &x);

  /* Izdvajaju se cifre jedinice, desetice i stotine. */
  cifra_jedinice = x % 10;
  cifra_desetice = (x / 10) % 10;
  cifra_stotine = x / 100;

  /* Ispis rezultata.
    NAPOMENA: Kada se stampa numericka vrednost promenljive tipa char koristi se %d. Kada se stampa karakter ciji je ASCII kod jednak vrednosti te promenljive, tada se koristi %c. U ovom slucaju je potrebno stampati numericku vrednost. */
  printf("jedinica %d, desetica %d, stotina %d\n", cifra_jedinice,
         cifra_desetice, cifra_stotine);

  /* II nacin: Ispis rezultata bez uvodjenja dodatnih promenljivih cifra_jedinice, cifra_desetice i cifra_stotine:

     printf("Cifre unetog broja su %d,%d,%d\n", x%10, (x/10)%10, x/100); */
  
  return 0;
}
