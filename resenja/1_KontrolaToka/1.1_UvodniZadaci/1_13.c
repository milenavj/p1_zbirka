#include <stdio.h>

int main()
{

  unsigned n, broj_obrnuto, broj_zamena;
  char j, d, s, h;
  int proizvod_cifara, razlika_cifara, suma_kvadrata;

  /* Ucitavamo vrednost sa ulaza */
  printf("Unesite cetvorocifreni broj: ");
  scanf("%u", &n);

  /* Izdvajamo cifre broja i to redom: j -jedinice, d - desetice,
     s - stotine i h - hiljade */
  j = n % 10;
  d = (n / 10) % 10;
  s = (n / 100) % 10;
  h = n / 1000;

  /* Izracunavamo proizvod cifara */
  proizvod_cifara = j * d * s * h;
  printf("Proizvod cifara: %d\n", proizvod_cifara);

  /* Izracunavamo razliku sume krajnjih i srednjih cifara */
  razlika_cifara = (h + j) - (s + d);
  printf("Razlika sume krajnjih i srednjih: %d\n", razlika_cifara);

  /* Izracunavamo sumu kvadrata cifara */
  suma_kvadrata = j * j + d * d + s * s + h * h;
  printf("Suma kvadrata cifara: %d\n", suma_kvadrata);

  /* Odredjujemo broj zapisan istim ciframa ali u obrnutom
     redosledu */
  broj_obrnuto = j * 1000 + d * 100 + s * 10 + h;
  printf("Broj u obrnutom poretku: %u\n", broj_obrnuto);

  /* Odredjujemo broj u kojem su cifra jedinica i cifra stotina
     zamenile mesta */
  broj_zamena = h * 1000 + j * 100 + d * 10 + s;
  printf("Broj sa zamenjenom cifrom jedinica i stotina: %u\n",
         broj_zamena);


  return 0;
}
