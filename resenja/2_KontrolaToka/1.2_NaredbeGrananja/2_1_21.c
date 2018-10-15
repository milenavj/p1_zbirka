#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int k, broj;

  /* Ucitava se trazena pozicija. */
  printf("Unesite k: ");
  scanf("%d", &k);

  /* Vrsi se provera ispravnosti ulaznih podataka. */
  if (k < 1 || k > 189) {
    printf("Greska: neispravan unos pozicije.\n");
    return -1;
  }

  /* Racuna se rezultat. */
  if (k < 10) {
    /* I slucaj: trazi se jednocifreni broj. */
    printf("Na %d-toj poziciji je broj %d.\n", k, k);
  } else {
    /* II slucaj: trazi se dvocifreni broj. */

    /* Ideja: izracunati broj na koji pokazuje pozicija k. Zatim,
       ako je k parno, uzeti cifru desetica tog broja, a ako je k
       neparno, uzeti cifru jedinica tog broja.

       Na primer, za k=14 i k=15, broj koji se nalazi na ovim
       pozicijama je 12, pa u slucaju da je k=14, treba ispisati 1,
       a u slucaju da je k=15, treba ispisati 2. */

    /* Odredjivanje odgovarajuceg broja: Kada bi niz izgledao
       10111213...9899, za dato k, broj bi se dobio kao 9 + k/2 + 1 
       za neparne vrednosti k, odnosno 9 + k/2 za parne (dodaje se
       vrednost detet jer je prvi broj u nizu desetka.) Na primer:
       k=1, broj = 9 + 1/2 + 1 = 9 + 0 + 1 = 10 k=2, broj = 9 + 2/2 
       = 10 k=3, broj = 9 + 3/2 + 1 = 9 + 1 + 1 = 11 k=4, broj = 9
       + 4/2 = 11 ... Posto ovde postoji i 9 pozicija ispred,
       potrebno je i njih uzeti u obzir - odatle: broj = 9 +
       (k-9)/2 + 1 za neparne vrednosti k, odnosno broj = 9 +
       (k-9)/2 za parne vrednosti k. */
    if (k % 2 != 0) {
      broj = 9 + (k - 9) / 2;
      printf("Na %d-toj poziciji je broj %d.\n", k, broj % 10);
    } else {
      broj = 9 + (k - 9) / 2 + 1;
      printf("Na %d-toj poziciji je broj %d.\n", k, broj / 10);
    }
  }

  return 0;
}
