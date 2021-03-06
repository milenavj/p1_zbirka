/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAKS 2000

/* Funkcija ispisuje elemente niza dimenzije n. */
void ispis(int niz[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

/* Funkcija ubacuje element x na kraj niza i vraca novu dimenziju
   niza. */
int ubaci_na_kraj(int niz[], int n, int x) {
  if (n == MAKS) {
    printf("Greska: prekoracen je maksimalan broj elemenata niza.");
    exit(EXIT_FAILURE);
  }

  niz[n] = x;
  return n + 1;
}

/* Funkcija ubacuje element x na pocetak niza i vraca novu dimenziju
   niza. */
int ubaci_na_pocetak(int niz[], int n, int x) {
  if (n == MAKS) {
    printf("Greska: prekoracen je maksimalan broj elemenata niza.");
    exit(EXIT_FAILURE);
  }

  int i;
  /* Prvo se svi elementi niza pomere za jednu poziciju u desno da
     bi se oslobodio prostor za prvi element niza. Poslednji
     element niza se pomera sa pozicije (n-1) na poziciju (n).
     Slicno se pomeraju i ostali elementi. */
  for (i = n; i > 0; i--)
    niz[i] = niz[i - 1];

  /* Na prvu poziciju se upisuje novi element. Bitan je redosled
     naredbi: ako bi prvo bio upisan novi element, a tek onda
     izvrseno pomeranje, element na poziciji niz[0] bi bio obrisan
     i ne bi mogao biti upisan na poziciju niz[1]. */
  niz[0] = x;

  return n + 1;
}

/* Funkcija ubacuje element x na neku poziciju u nizu i vraca novu
   dimenziju niza. */
int ubaci_na_poziciju(int niz[], int n, int x, int pozicija) {
  if (n == MAKS) {
    printf("Greska: prekoracen je maksimalan broj elemenata niza.");
    exit(EXIT_FAILURE);
  }

  int i;
  /* Prvo se svi elementi niza od pozicije do kraja pomere za jedno 
     mesto u desno da bi se oslobodio prostor za novi element niza. */
  for (i = n; i > pozicija; i--)
    niz[i] = niz[i - 1];

  /* Na poziciju se upisuje novi element. */
  niz[pozicija] = x;

  return n + 1;
}

/* Funkcija brise prvi element niza i vraca novu dimenziju niza. */
int brisi_prvog(int niz[], int n) {
  if (n == 0) {
    printf("Greska: nije moguce brisanje iz praznog niza.\n");
    exit(EXIT_FAILURE);
  }

  int i;
  /* Svi elementi niza pomeraju se za jedno mesto u levo. */
  for (i = 0; i < n - 1; i++)
    niz[i] = niz[i + 1];

  return n - 1;
}

/* Funkcija brise poslednji element niza i vraca novu dimenziju
   niza. */
int brisi_poslednjeg(int niz[], int n) {
  if (n == 0) {
    printf("Greska: nije moguce brisanje iz praznog niza.\n");
    exit(EXIT_FAILURE);
  }

  /* Dovoljno je smanjiti dimenziju niza, elemente niza nije
     potrebno brisati. */
  return n - 1;
}

/* Funkcija brise element x i vraca novu dimenziju niza. 
   Pretpostavlja se da element ima samo jedno pojavljivanje. */
int brisi_element(int niz[], int n, int x) {
  int i, j;

  /* Prvo treba pronaci poziciju elementa u nizu. */
  for (i = 0; i < n; i++)
    if (niz[i] == x)
      break;

  /* Provera da li element postoji u nizu. Ako je brojac stigao do
     kraja niza, onda element ne postoji u nizu. */
  if (i == n) {
    printf("Klijent sa rednim brojem %d ne postoji u nizu.\n", x);
    return n;
  }

  /* Ukoliko element postoji u nizu, svi elementi niza nakon njega
     se pomeraju za jedno mesto u levo. */
  for (j = i; j < n - 1; j++)
    niz[j] = niz[j + 1];

  return n - 1;
}

int main() {
  int n, niz[MAKS], i, klijent, pozicija;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite trenutni broj klijenata: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  printf("Unesite niz sa rednim brojevima klijenata: ");
  for (i = 0; i < n; i++)
    scanf("%d", &niz[i]);

  /* Ubacivanje klijenta na kraj. */
  printf("Unesite broj klijenta kojeg treba ubaciti u niz: ");
  scanf("%d", &klijent);
  n = ubaci_na_kraj(niz, n, klijent);
  printf("Niz nakon ubacivanja klijenta:\n");
  ispis(niz, n);

  /* Ubacivanje klijenta na pocetak. */
  printf("Unesite prioritetnog klijenta kojeg treba"
         "ubaciti u niz: ");
  scanf("%d", &klijent);
  n = ubaci_na_pocetak(niz, n, klijent);
  printf("Niz nakon ubacivanja klijenta:\n");
  ispis(niz, n);

  /* Ubacivanje klijenta na zadatu poziciju. */
  printf("Unesite prioritetnog klijenta kojeg treba ubaciti "
         "u niz i njegovu poziciju:");
  scanf("%d%d", &klijent, &pozicija);
  if (pozicija < 0 || pozicija > n) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  } else {
    n = ubaci_na_poziciju(niz, n, klijent, pozicija);
    printf("Niz nakon ubacivanja klijenta:\n");
    ispis(niz, n);
  }

  /* Brisanje prvog klijenta. */
  n = brisi_prvog(niz, n);
  printf("Niz nakon odlaska klijenta:\n");
  ispis(niz, n);

  /* Brisanje poslednjeg klijenta. */
  n = brisi_poslednjeg(niz, n);
  printf("Niz nakon odlaska klijenta:\n");
  ispis(niz, n);

  /* Brisanje klijenta sa datim rednim brojem. */
  printf("Unesite redni broj klijenta koji je napustio red: ");
  scanf("%d", &klijent);
  n = brisi_element(niz, n, klijent);
  printf("Niz nakon odlaska klijenta:\n");
  ispis(niz, n);

  exit(EXIT_SUCCESS);
}
