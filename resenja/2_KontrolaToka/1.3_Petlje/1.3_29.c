#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, c1, c2, c3;
  int pozicija, rezultat;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Ako broj nema bar tri cifre, rezultat ima vrednost unetog
     broja. */
  if (n <= 99) {
    printf("Rezultat: %d\n", n);
    return 0;
  }

  /* Izdvajanje poslednje tri cifre polaznog broja. */
  c1 = n % 10;
  c2 = (n / 10) % 10;
  c3 = (n / 100) % 10;

  /* Poslednja cifra se uvek nalazi u rezultatu jer ona nema oba
     suseda. Zato se rezultat inicijalizuje na poslednju cifru, a
     pozicija na 10. */
  rezultat = c1;
  pozicija = 10;

  /* Petlja se izvrsava dok god broj ima bar tri cifre. */
  while (n > 99) {
    /* Provera da li c2 treba da se nadje u rezultatu. Ako
       treba, rezultat se uvecava za vrednost cifre pomnozenu sa
       vrednoscu tezine njene pozicije u rezultatu i tezina
       pozicije se mnozi sa 10. */
    if (c2 != c1 + c3) {
      rezultat += c2 * pozicija;
      pozicija *= 10;
    }

    /* Vrsi se pomeranje na sledece tri cifre polaznog broja. Iz
       polaznog broja se brise poslednja cifra. Prva i druga cifra
       su vec izracunate, samo se vrsi njihovo premestanje iz c2 i
       c3 u c1 i c2. Cifra c3 se racuna. */
    n = n / 10;
    c1 = c2;
    c2 = c3;
    c3 = (n / 100) % 10;
  }

  /* Po zavrsetku petlje, broj n je dvocifren i njegova cifra
     desetica odgovara vodecoj cifri polaznog broja. Vodeca cifra
     polaznog broja uvek treba da se nadje u rezultatu jer nema oba 
     suseda i iz tog razloga se dodaje na tekuci rezultat. */
  rezultat += (n / 10) * pozicija;

  /* Ispis rezultata. */
  printf("%d\n", rezultat);

  return 0;
}
