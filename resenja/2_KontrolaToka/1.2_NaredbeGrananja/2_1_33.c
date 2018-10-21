#include<stdio.h>
#include<stdlib.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int k, l, m, n;

  /* Ucitavaju se vrednosti pozicija na tabli. */
  printf("Unesite (k,l): ");
  scanf("%d%d", &k, &l);

  printf("Unesite (m,n): ");
  scanf("%d%d", &m, &n);

  /* Vrsi se provera ispravnosti ulaznih podataka. */
  if (k < 1 || k > 8 || l < 1 || l > 8 || 
      m < 1 || m > 8 || n < 1 || n > 8) {
    printf("Greska: neispravna pozicija.\n");
    return -1;
  }
  
  if(k == m && l == n){
    printf("Greska: pozicije moraju biti razlicite.\n");
    return -1;
  }

  /* Proverava se da li su (k,l) i (m,n) iste boje. Polja su iste
     boje ako su: 1) oba reda parna i obe kolone parne ILI 2) oba
     reda neparna i obe kolone neparne. */
  if (((k % 2 == m % 2) && (l % 2 == n % 2))
      || ((k % 2 != m % 2) && (l % 2 != n % 2)))
    printf("Polja su iste boje.\n");
  else
    printf("Polja su razlicite boje.\n");

  /* Proverava se da li kraljica sa (k,l) napada polje (m,n).
     Kraljica napada polje u sledecim situacijama: 
     1) Ako se nalaze u istom redu (k==m) 
     2) Ako se nalaze u istoj koloni (l==n) 
     3) Ako se nalaze na istoj dijagonali. Dijagonala moze biti:
        a) paralelna glavnoj dijagonali (abs(k-l) == abs(m-n)) 
        b) paralelna sporednoj dijagonali (k+l == m+n) */
  if ((k == m) || (l == n) || (abs(k - l) == abs(m - n)) 
      || (k + l == m + n)){
    printf("Kraljica sa (%d, %d) ugrozava (%d, %d).\n", 
           k, l, m, n);
  }
  else {
    printf("Kraljica sa (%d, %d) ne ugrozava (%d, %d).\n", 
           k, l, m, n);
  }

  /* Proverava se da li konj sa (k, l) napada polje (m, n). Postoji 
     8 mogucih vrednosti za polja koja konj napada. Vrsi se
     provera da li je (m,n) jednako nekom od tih polja. */
  int uslov = 0;
  if (((m == k + 2) || (m == k - 2)) && 
      ((n == l - 1) || (n == l + 1))){
    uslov = 1;
  }
  else if (((n == l - 2) || (n == l + 2)) && 
           ((m == k + 1) || (m == k - 1))){
    uslov = 1;
  }
  
  if (uslov)
    printf("Konj sa (%d, %d) ugrozava (%d, %d).\n",
           k, l, m, n);
  else
    printf("Konj sa (%d, %d) ne ugrozava (%d, %d).\n",
           k, l, m, n);

  return 0;
}
