#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int n;
  int i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Prva petlja oznacava broj 'serija' koje ce se ispisati. Na
     primer, za n=5, prva serija je 1 2 3 4 5, druga serija je 2 3
     4 i treca serija je 3. Kako se u svakoj sledecoj seriji broj
     brojeva smanjuje za 2, do 0 karaktera u seriji se dolazi posle 
     n/2 koraka, ali zaokruzeno navise (5/2 = 2.5 --> 3), a to je
     isto sto i celobrojno (n+1)/2. */
  for (i = 1; i <= (n + 1) / 2; i++) {
    /* U svakoj seriji se ispisuju brojevi izmedju i i n-i+1. */
    for (j = i; j <= n + 1 - i; j++)
      printf("%d ", j);
  }
  
  /* II nacin: 
  int levo = 1, desno = n-1;
  while (levo <= desno) {
    // Ispis jedne serije. 
    for (j = levo; j <= desno; j++)
      printf(" %d", j);
    
    // Pomeranje leve i desne granice. 
    levo++;
    desno--;
  } */

  return 0;
}
