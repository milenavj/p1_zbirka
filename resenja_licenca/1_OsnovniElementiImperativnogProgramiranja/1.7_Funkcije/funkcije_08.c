/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <math.h>

/* Funkcija vraca 1 ako je broj prost, a 0 u suprotnom.  */
int prost(int x) {
  int i;

  /* Brojevi 2 i 3 su prosti. */
  if (x == 2 || x == 3)
    return 1;

  /* Parni brojevi nisu prosti. */
  if (x % 2 == 0)
    return 0;

  /* Ako se naidje na broj koji deli broj x, onda broj x nije
     prost. Provera se vrsi za sve neparne brojeve izmedju 3 i
     sqrt(x), jer kada bi x imao parnog delioca, onda bi i broj 2
     delio x, a taj uslov je vec proveren. */
  for (i = 3; i <= sqrt(x); i += 2)
    if (x % i == 0)
      return 0;

  /* Ako nijedan od prethodnih uslova nije bio ispunjen, to znaci
     da nijedan broj ne deli x, pa je on prost. */
  return 1;
}

/* Funkcija ispisuje prvih n prostih brojeva. Kljucna rec void
   oznacava da funkcija nema povratnu vrednost. */
void prvih_n_prostih(int n) {
  int broj_prostih = 0;
  int k = 2;

  /* Petlja se izvrsava sve dok se ne ispise n prostih brojeva. */
  while (broj_prostih < n) {
    /* Ako se naidje na broj koji je prost, ispisuje se njegova
       vrednost i uvecava se brojac. */
    if (prost(k)) {
      printf("%d ", k);
      broj_prostih++;
    }

    /* Prelazi se na sledeci broj. */
    k++;
    /* Napomena: Zbog prirode prostih brojeva, moze se krenuti i od
       broja tri i vrsiti uvecavanje za dva, kako bi se preskocila
       provera parnih brojeva. */
  }
  printf("\n");
}

/* Funkcija ispisuje sve proste brojeve cija je vrednost manja od
   n. */
void prosti_brojevi_manji_od_n(int n) {
  /* Ukoliko je n manje ili jednako 2, onda nema prostih brojeva
     koji su manji od njega. U tom slucaju se ispisuje odgovarajuca
     poruka i naredbom return; se izlazi iz funkcije. */
  if (n <= 2) {
    printf("ne postoje\n");
    return;
  }

  /* Za svaki broj k izmedju 2 i n-1 se vrsi provera da li je prost
     i ako jeste, ispisuje se njegova vrednost. */
  int k = 2;
  while (k < n) {
    if (prost(k))
      printf("%d ", k);
    k++;
  }
  printf("\n");
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n;

  /* Ucitavanje broja n. */
  printf("Unesite broj n:");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Ispis rezultata. */
  printf("Prvih n prostih: ");
  prvih_n_prostih(n);
  printf("Prosti manji od n: ");
  prosti_brojevi_manji_od_n(n);

  return 0;
}
