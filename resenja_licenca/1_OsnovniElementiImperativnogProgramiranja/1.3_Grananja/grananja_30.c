/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include<stdlib.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int k, l, m, n;

  /* Ucitavanje vrednosti pozicija na tabli. */
  printf("Unesite (k,l): ");
  scanf("%d%d", &k, &l);

  printf("Unesite (m,n): ");
  scanf("%d%d", &m, &n);

  /* Provera ispravnosti ulaznih podataka. */
  if (k < 1 || k > 8 || l < 1 || l > 8 || 
      m < 1 || m > 8 || n < 1 || n > 8) {
    printf("Greska: neispravna pozicija.\n");
    return 1;
  }
  
  if(k == m && l == n){
    printf("Greska: pozicije moraju biti razlicite.\n");
    return 1;
  }

  /* Provera da li su (k,l) i (m,n) iste boje. Polja su iste
     boje ako su: 
     1) oba reda parna i obe kolone parne ILI 
     2) oba reda neparna i obe kolone neparne. */
  if (((k % 2 == m % 2) && (l % 2 == n % 2))
      || ((k % 2 != m % 2) && (l % 2 != n % 2)))
    printf("Polja su iste boje.\n");
  else
    printf("Polja su razlicite boje.\n");
  /* II nacin:
     if((k+l) % 2 == (m+n) % 2)
       printf("Polja su iste boje.\n");
     else
       printf("Polja su razlicite boje.\n"); */

  /* Provera da li kraljica sa (k,l) napada polje (m,n).
     Kraljica napada polje u sledecim situacijama: 
     1) Ako se nalaze u istom redu (k==m) 
     2) Ako se nalaze u istoj koloni (l==n) 
     3) Ako se nalaze na istoj dijagonali. Dijagonala moze biti:
        a) paralelna glavnoj dijagonali (k-l == m-n) 
        b) paralelna sporednoj dijagonali (k+l == m+n) */
  if ((k == m) || (l == n) || (k - l == m - n) 
      || (k + l == m + n)) {
    printf("Kraljica sa (%d, %d) ugrozava (%d, %d).\n", 
           k, l, m, n);
  }
  else {
    printf("Kraljica sa (%d, %d) ne ugrozava (%d, %d).\n", 
           k, l, m, n);
  }

  /* Provera da li konj sa (k, l) napada polje (m, n). Postoji 
     8 mogucih vrednosti za polja koja konj napada. Vrsi se
     provera da li je (m,n) jednako nekom od tih polja. */
  if ((abs(k-m) == 2 &&  abs(n-l) == 1) || (abs(n-l) == 2 && abs(m-k) == 1))
    printf("Konj sa (%d, %d) ugrozava (%d, %d).\n",
           k, l, m, n);
  else
    printf("Konj sa (%d, %d) ne ugrozava (%d, %d).\n",
           k, l, m, n);

  return 0;
}
