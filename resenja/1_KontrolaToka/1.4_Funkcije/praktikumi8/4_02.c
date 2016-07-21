#include <stdio.h>

/* Funkcija koja racuna apsolutnu vrednost */
unsigned int apsolutna_vrednost(int x){
  /* Kako funkcija vraca unsigned, a x je tipa int, vrsimo kastovanje rezultata u tip unsigned */
  return (unsigned)(x<0?-x:x);
}

int main(){
	int n;

	/* Ucitavamo broj */
	printf("Unesite broj: ");
	scanf("%d", &n);

	/* Ispisujemo njegovu apsolutnu vrednost */
	printf("Apsolutna vrednost: %u\n", apsolutna_vrednost(n));
	
	return 0;
}


