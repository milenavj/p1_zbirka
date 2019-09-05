#include <stdio.h>
#include <stdlib.h>

/* Funkcija racuna aritmeticku sredinu cifara datog celog broja. */
float aritmeticka_sredina(int x) {
  /* Aritmeticka sredina broja 0 je 0. */
  if (x == 0)
    return 0;

  /* Deklaracija i inicijalizacija brojaca. */
  int zbir_cifara = 0;
  int broj_cifara = 0;

  /* Uzima se apsolutna vrednost broja x kako bi program ispravno
     radio i za negativne brojeve. */
  x = abs(x);

  /* Sve dok ima neobradjenih cifara, na zbir se dodaje poslednja
     cifra, brojac cifara se uvecava za 1 i sa broja x se uklanja
     poslednja cifra. */
  while (x) {
    zbir_cifara += x % 10;
    broj_cifara++;
    x /= 10;
  }

  /* Kao povratna vrednost funkcije se vraca odgovarajuci 
     kolicnik. */
  return (float) zbir_cifara / broj_cifara;
}

int main() {
  /* Deklaracija potrebne promenljive. */
  int x;

  /* Ucitavanje vrednosti broja x. */
  printf("Unesite broj: ");
  scanf("%d", &x);

  /* Ispis rezultata. */
  printf("Aritmeticka sredina: %.3f\n", aritmeticka_sredina(x));

  return 0;
}
