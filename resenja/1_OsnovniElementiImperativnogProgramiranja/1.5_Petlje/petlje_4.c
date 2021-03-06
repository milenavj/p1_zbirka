#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, m, i;

  /* Ucitavanje vrednosti granica intervala. */
  printf("Unesite granice intervala: ");
  scanf("%d%d", &n, &m);

  /* Provera ispravnosti ulaznih podataka. */
  if (m < n) {
    printf("Greska: pogresan unos granica.\n");
    return 1;
  }

  /* a) I nacin: Koriscenjem while petlje. */
  /* Inicijalizacija brojaca na levu granicu intervala. */
  i = n;

  /* Ispis svih vrednosti brojaca izmedju leve i desne granice 
     intervala, ukljucujuci i same granice. */
  while (i <= m) {
    printf("%d ", i);
    i++;
  }

  /* b) II nacin: Koriscenjem for petlje.

     Naredba i=n se izvrsava jednom, pre prve iteracije. Uslov
     petlje i<=m se proverava pre svake iteracije. Naredba i++ se
     izvrsava nakon svake iteracije.

     for (i = n; i <= m; i++){
       printf("%d ", i); 
     } */

  /* c) III nacin: Koriscenjem do while petlje.

     Uslov petlje se proverava na kraju svake iteracije. Zbog toga
     se do while petlja izvrsava bar jednom, cak i u slucaju da
     uslov petlje nikada nije ispunjen. U ovom slucaju je to
     ispravno jer je poznato da ce interval imati bar jedan
     element. U opstem slucaju to ne mora da vazi.

     i = n; 
     do { 
       printf("%d ", i); 
       i++; 
     } while (i <= m); */

  printf("\n");

  return 0;
}
