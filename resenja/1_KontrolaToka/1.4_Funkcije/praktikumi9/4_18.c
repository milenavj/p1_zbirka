#include <stdio.h>

/* Funkcija racuna n-ti clan Fibonacijevog niza.
 * Clanovi ovog niza zadaju se rekurzivno tj. u zavisnosti od prethodnih clanova.
 * Fibonacijevi brojevi od 0. do 47. se mogu smestiti u tip int, a kako n moze uzimati vrednosti
 * od 1 do 50, povratni tip funkcije je long int. 
 */
long int fibonaci(int n) {

  int i;

  /* f0 i f1 su prva dva clana niza */
  int f0 = 1; 
  int f1 = 1;
  /* promenljiva u kojoj se cuvaju opsti clanovi: n+2, n+1. i n-ti clan */
  long int fn2, fn1, fn;
  
  /* ukoliko treba vratiti nulti ili prvi clan,
   * njih ne treba racunati
   * jer su vec dati.
   */
  if(n == 0 || n == 1)
    return 1;

  /* postavljamo prethodne clanove niza */
  fn = f0;
  fn1 = f1;
  /* racunamo od drugog clana, pa dok ne dodjemo do n-tog */
  for(i = 2; i <= n; i++) {
  
    /* izracunamo n+2-i clan niza sabiranjem prethodna dva clana */
    fn2 = fn1 + fn; 
    /* promenimo prethodne clanove niza, zbog naredne iteracije */
    fn =  fn1;
    fn1 = fn2;
  }
  
  return fn2;
}

int main() {
  
  int n;
  printf("Unesite broj n: ");
  scanf("%d", &n);
  
  /* Provera vrednosti za broj n */
  if(n <0 || n > 50) {
    printf("Greska: nedozvoljena vrednost!\n");
  }
  else{  
  	printf("%ld\n", fibonaci(n));
  }
  
  return 0;
}
