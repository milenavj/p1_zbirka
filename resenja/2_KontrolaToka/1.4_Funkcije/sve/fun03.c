#include <stdio.h>

/* Funkcija koja racuna zbir delilaca broja x. */ 
int zbir_delilaca(int x) {
  int i;
  
  /* Inicijalizacija zbira na 0. */
  int zbir = 0;

  /* Svaki broj i izmedju 1 i sqrt(x) koji deli broj x se dodaje
     u zbir. Ako je u pitanju broj koji za koji vazi da je i*i 
     jednako x, onda se dodaje samo vrednost i, a ako nije, onda
     se pored vrednosti i dodaje i x/i. 
     Na primer, za x=6, kada je i=2, dodaju se i 2 i 6/2 = 3, a za
     x = 4, kada je i=2, dodaje se samo 2. */
  for (i = 1; i*i <= x; i++) {
    if (x % i == 0)
    {
      zbir += i;
      if(i != x/i)
        zbir += x/i;
    }
  }
  
  /* Povratna vrednost funkcije je dobijeni zbir. */ 
  return zbir;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int k, i;

  /* Ucitava se broj k. */ 
  printf("Unesite broj k:");
  scanf("%d", &k);

  /* Vrsi se provera ispravnosti ulaznih podataka. */
  if (k <= 0){
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Za svaki broj od 1 do k se ispisuje zbir delilaca. */ 
  for (i = 1; i <= k; i++)
    printf("%d ", zbir_delilaca(i));
  printf("\n");

  return 0;
}