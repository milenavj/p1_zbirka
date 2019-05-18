#include <stdio.h>

/* Funkcija koja racuna apsolutnu vrednost. */
unsigned int apsolutna_vrednost(int x){
  /* Kako funkcija vraca unsigned, a x je tipa int, potrebno je kastovati rezultat u tip unsigned. */
  return (unsigned)(x<0?-x:x);
}

int main() {
	int n;

	/* Unos broja. */
	printf("Unesite broj: ");
	scanf("%d", &n);

	/* Ispis njegove apsolutne vrednosti. */
	printf("Apsolutna vrednost: %u\n", apsolutna_vrednost(n));
	
	return 0;
}


