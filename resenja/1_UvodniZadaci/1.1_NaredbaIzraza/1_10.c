#include <stdio.h>

int main() {
  /* Deklaracija potrebne promenljive. */
  unsigned int x;

  /* Promenljive koje cuvaju cifre treba da budu najmanjeg
     celobrojnog tipa jer nece sadrzati druge vrednosti osim
     jednocifrenih celih brojeva. Zbog toga se koristi tip char. */
  char cifra_jedinica, cifra_desetica, cifra_stotina;

  /* Ucitavanje trocifrenog broja. */
  printf("Unesite trocifreni broj: ");
  scanf("%u", &x);

  /* Izdvajanje cifara jedinice, desetice i stotine. */
  cifra_jedinica = x % 10;
  cifra_desetica = (x / 10) % 10;
  cifra_stotina = x / 100;

  /* Ispis rezultata.
     NAPOMENA: Kada se stampa numericka vrednost promenljive tipa
     char koristi se %d. Kada se stampa karakter ciji je ASCII 
     kod jednak vrednosti te promenljive, tada se koristi %c.
     U ovom slucaju je potrebno stampati numericku vrednost. */
  printf("Cifra jedinica: %d\n", cifra_jedinica);
  printf("Cifra desetica: %d\n", cifra_desetica);
  printf("Cifra stotina: %d\n", cifra_stotina);

  /* II nacin: Ispis rezultata bez uvodjenja dodatnih promenljivih
     cifra_jedinica, cifra_desetica i cifra_stotina:
     printf("Cifre unetog broja su %d,%d,%d\n", x%10, (x/10)%10, 
             x/100); */

  return 0;
}
