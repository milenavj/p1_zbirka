#include <stdio.h>
#include <stdlib.h>

#define MAX 31

int main() {
    /* Deklaracija potrebnih promenljivih. */
    char s[MAX];
    int i, max_duzina, trenutna_duzina;
    
    /* Ucitavanje niske. */
    scanf("%s", s);

    /* Odredjivanje najduze podniske karaktera koji su uredjeni rastuce. */
    max_duzina = 1;
    trenutna_duzina = 1;

    for(i=1; s[i]; i++) {
        /* Ako je ASCII kod tekuceg karaktera veci od ASCII koda prethodnog karaktera, 
        podniska je rastuca pa se njena trenutna duzina uvecava. */
        if(s[i-1] < s[i]) {
            trenutna_duzina++;
        }
        else {
            /* Ako se naislo na par karaktera koji nisu uredjeni rastuce, 
            azurira se, po potrebi, maksimalna duzina trazene podniske i resetuje se trenutna duzina. */
            if(max_duzina < trenutna_duzina) {
                max_duzina = trenutna_duzina;
            }
            
            trenutna_duzina = 1;
        }
    }

    /* Postupak azuriranja maksimalne duzine se, po potrebi, vrsi i kada se stigne do kraja niske. */
	if(max_duzina < trenutna_duzina) {
        max_duzina = trenutna_duzina;
    }
    
    /* Ispis rezultata. */    
    printf("%d\n", max_duzina);
    
    exit(EXIT_SUCCESS);
}