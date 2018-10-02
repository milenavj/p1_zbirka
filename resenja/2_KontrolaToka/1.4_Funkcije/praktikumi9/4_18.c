#include <stdio.h>

/* Funkcija racuna n-ti clan Fibonacijevog niza. */
long unsigned fibonaci(int n) {

  int i;

  /* Prva dva clana niza su jednaki 1. */
  long unsigned f0 = 1; 
  long unsigned f1 = 1;
  /* Promenljive u kojima se cuvaju tekuci clanovi niza: n+2, n+1. i n-ti clan. */
  long int fn2, fn1, fn;
  
  /* Nulti i prvi clan Fibonacijevog niza su poznati pa ih ne treba racunati u petlji. */
  if(n == 0 || n == 1)
    return 1;

  /* Tekuci clanovi niza se postavljaju  na pocetne vrednosti. */
  fn = f0;
  fn1 = f1;
  /* Elementi niza se racunaju od drugog clana do n-tog. */
  for(i = 2; i <= n; i++) {
  
    /* Naredni clan niza (element n+2-i) se dobija sabiranjem prethodna dva clana. */
    fn2 = fn1 + fn; 
    /* Menjaju se vrednosti tekucih clanova niza zbog naredne iteracije. */
    fn =  fn1;
    fn1 = fn2;
  }
  
  return fn2;
}

int main() {
  
  int n;
  printf("Unesite broj n: ");
  scanf("%d", &n);
  
  /* Provera vrednosti za broj n. */
  if(n <0 || n > 50) {
    printf("Greska: nedozvoljena vrednost!\n");
  }
  else{  
  	printf("%lu\n", fibonaci(n));
  }
  
  return 0;
}
