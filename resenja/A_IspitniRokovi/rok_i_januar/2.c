#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 21

int main() {
    /* Deklaracija potrebnih promenljivih. */
    char s[MAX], c;
    int i, n;
    
    /* Ucitavanje reci i karaktera koji odredjuje tip transformacije. */
    scanf("%s %c", s, &c);
    
    /* Odredjivanje duzine reci. */
    n = strlen(s);

    /* Analiza procitanog karaktera. */
    switch(c) {
        case 'm':
            /* Zamena svih malih slova reci odgovarajucim velikim slovima. */
            for(i=0; i<n; i++) {
                if(islower(s[i])) {
                    s[i] = toupper(s[i]);
                }
            }
            break;
            
        case 'v':
            /* Zamena svih velikih slova reci odgovarajucim malim slovima. */
            for(i=0; i<n; i++) {
                if(isupper(s[i])) {
                    s[i] = tolower(s[i]);
                }
            }
            break;

        case 'o':
            /* Rec se ne menja. */
            break;
        default:
            /* Transformacija nije definisana pa se ispisuje poruka o gresci i prekida izvrsavanje programa. */
            printf("-1\n");
            exit(EXIT_FAILURE);
    }
    
    /* Ispis rezultata. */
    printf("%s\n", s);
    
    exit(EXIT_SUCCESS);
}