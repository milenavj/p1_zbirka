#include <stdio.h>

int main(int argc, char* argv[]) {

  int i;
  int s = 0;
  
  /* char *argv[] <--- niz niski koje predstavljaju argumente navedene iza poziva programa
	 int argc     <--- ukupan broj niski (sa sve nazivom programa) navedenih prilikom pozivanja
	 	 
	 Ukoliko je program pozvan sa ./a.out 12 abc 6 5 3ab

	 argv[0] = "./a.out".
	 argv[1] = "12"
	 argv[2] = "abc"
	 argv[3] = "6"
	 argv[4] = "5"
	 argv[5] = "3ab"
	 
	 argc iznosi 6
	 
	 
	 Kako je argv[] po prirodi niz,
	 koristimo tzv. brojacku odnosno 
	 for petlju
	 i obradjujemo svaki od argumenata.	 
	*/

  /* Funkcija atoi() prihvata nisku,
	 i racuna dekadnu vrednost prosledjene niske,
	 dokle god se ona moze racunati.
	 Na primer, ukoliko je niska "-123",
	 atoi() vraca broj -123.
	 Ako je, pak, niska "123abc",
	 atoi() ce vratiti 123 
	 (prilikom prve pojave karaktera koji nije cifra, funkcija prekida izracunavanje).
	 
	 To za posledicu ima da, ukoliko je funkciji
	 prosledjeno nesto
	 sto se ne moze pretvoriti u broj,
	 na primer niska "abcd",
	 funkcija atoi() vraca 0.
	*/
  
  for(i = 1; i < argc; i++)
    s += atoi(argv[i]); /* Zbog nacina rada funkcije atoi(), mozemo je pozvati nad svim argumentima
							komandne linije, i sabrati odgovarajuce dekadne vrednosti.
							Ukoliko neki argument i nije broj, to ne predstavlja problem
							jer ce u tom slucaju odgovarajuci sabirak biti 0 
						*/
							

    printf("Zbir numerickih argumenata: %d\n", s);

  return 0;
}
