#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(int a[][MAKS], int m, int n) {
  int i, j;
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int m, n, brojac, i, j, pravac;
  int gornja_granica, donja_granica, leva_granica, desna_granica;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite dimenziju matrice: ");
  scanf("%d%d", &m, &n);
  if (n <= 0 || n > MAKS || m <= 0 || m > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, m, n);

  /* Ciklicni ispis elemenata matrice: 
     Npr. za n=4, indeksi elemenata u matrici su: 
     (0,0) (0,1) (0,2) (0,3) 
     (1,0) (1,1) (1,2) (1,3)
     (2,0) (2,1) (2,2) (2,3) 
     (3,0) (3,1) (3,2) (3,3)
     Ispis treba da ide sledecim redosledom: 
     1. krece se sa leva na desno (0,0) (0,1) (0,2) (0,3) 
     2. zatim se ide na dole (1,3) (2,3) (3,3) 
     3. zatim na levo (3,2) (3,1) (3,0) 
     4. zatim na gore (2,0) (1,0) (ovde se staje jer je (0,0) vec
     ispisano) i prelazi se opet na levo. Koraci 1-4 se ponavljaju 
     dok god se ne ispisu svi elementi. Ideja je da kada se ispisu
     elementi prve vrste (kada se ide sa leva na desno), da se
     pomeri "gornja granica ispisa" za 1, kako bi se naznacilo da
     je taj red vec ispisan. Slicno, kada se vrsi ispis odozgo na
     dole, uspesno je ispisana jedna kolona pa je potrebno pomeriti
     "desnu granicu ispisa" za jedan u levo. Kada se ispise jedna
     vrsta sa desna na levo, vrsi se pomeranje donje granice ispisa
     za jedan na gore. Slicno, kada se ispise jedna kolona odozdo na
     gore, pomera se leva granica ispisa za jedan u desno. */
  gornja_granica = 0;
  donja_granica = m - 1;
  leva_granica = 0;
  desna_granica = n - 1;

  /* Promenljiva pravac govori u kom smeru ispis ide. */
  pravac = 1;

  /* Promenljive i i j su indeksi elementa koji se ispisuje. */
  i = 0;
  j = 0;
  
  printf("Ispis je:\n");
  for (brojac = 0; brojac < m * n; brojac++) {
    printf("%d ", a[i][j]);

    switch (pravac) {
      /* Ako je pravac = 1, trenutni smer ispisa je sa leva na
         desno. */
    case 1:
      /* Ako je ispisan element na desnoj granici, onda se menja
         pravac ispisa. */
      if (j == desna_granica) {
        /* Prelazi se na pravac odozgo na dole. */
        pravac = 2;
        /* Pomera se gornja granica za jedan na dole. */
        gornja_granica++;
        /* Pomera se vrednost vrste za jedan na dole. */
        i++;
      } else {
        /* Ako jos uvek nije ispisan element na desnoj granici,
           vrsi se pomeranje na sledeci element u trenutnoj vrsti. */
        j++;
      }
      break;

      /* Ako je pravac = 2, trenutni smer ispisa je odozgo na dole. 
         Slicno kao i u prethodnom slucaju, ako se dodje do donje
         granice, menja se pravac i pomera se desna granica za
         jedno mesto u levo. U suprotnom se samo prelazi na narednu 
         vrstu. */
    case 2:
      if (i == donja_granica) {
        pravac = 3;
        desna_granica--;
        j--;
      } else {
        i++;
      }
      break;

      /* Ako je pravac = 3, trenutni smer ispisa je sa desna na
         levo. Slicno kao i u prethodnom slucaju, ako se dodje do
         leve granice, menja se pravac i pomera se donja granica za 
         jedno mesto na gore. U suprotnom se samo prelazi na
         narednu kolonu. */
    case 3:
      if (j == leva_granica) {
        pravac = 4;
        donja_granica--;
        i--;
      } else {
        j--;
      }
      break;

      /* Ako je pravac = 4, trenutni smer ispisa je odozdo na gore. 
         Slicno kao i u prethodnim slucajevima, ako se dodje do
         gornje granice, menja se pravac i pomera se leva granica
         za jedno mesto u desno. U suprotnom se samo prelazi na
         narednu vrstu. */
    case 4:
      if (i == gornja_granica) {
        pravac = 1;
        leva_granica++;
        j++;
      } else {
        i--;
      }
    }
  }
  printf("\n");

  return 0;
}
