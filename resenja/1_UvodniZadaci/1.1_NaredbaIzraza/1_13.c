#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, broj_obrnuto, broj_zamena;
  char jedinice, desetice, stotine, hiljade;
  int proizvod_cifara, razlika_cifara, suma_kvadrata;

  /* Ucitava se jedan neoznacen broj. */
  printf("Unesite cetvorocifreni broj: ");
  scanf("%u", &n);

  /* Izdvajaju se cifre ucitanog broja. */
  jedinice = n % 10;
  desetice = (n / 10) % 10;
  stotine = (n / 100) % 10;
  hiljade = n / 1000;

  /* Izracunava se proizvod cifara. */
  proizvod_cifara = jedinice * desetice * stotine * hiljade;
  printf("Proizvod cifara: %d\n", proizvod_cifara);

  /* Izracunava se razlika sume krajnjih i srednjih cifara. */
  razlika_cifara = (hiljade + jedinice) - (stotine + desetice);
  printf("Razlika sume krajnjih i srednjih: %d\n", razlika_cifara);

  /* Izracunava se suma kvadrata cifara. */
  suma_kvadrata = jedinice * jedinice + desetice * desetice + 
		  stotine * stotine + hiljade * hiljade;
  printf("Suma kvadrata cifara: %d\n", suma_kvadrata);

  /* Izracunava se broj zapisan istim ciframa ali u obrnutom
     redosledu */
  broj_obrnuto = jedinice * 1000 + desetice * 100 + stotine * 10 + hiljade;
  printf("Broj u obrnutom poretku: %u\n", broj_obrnuto);

  /* Izracunava se broj u kojem su cifra jedinica i cifra stotina
     zamenile mesta */
  broj_zamena = hiljade * 1000 + jedinice * 100 + desetice * 10 + stotine;
  printf("Broj sa zamenjenom cifrom jedinica i stotina: %u\n", broj_zamena);

  return 0;
}
