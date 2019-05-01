#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Deklaracija potrebnih promenljivih. */
    int broj, broj_kopija;
    char cifra_jedinica, cifra_desetica, cifra_stotina, cifra_hiljada;
    char postoji_broj = 0;

    
    while(1)
    {
        /* Ucitavanje korisnickog unosa. */
        scanf("%d", &broj);

        /* Provera da li se doslo do kraja unosa. */
        if (broj == 0){
            break;
        }

        /* Cuvanje kopije broja. */
        broj_kopija = broj;

        /* Provera ispravnosti ulaza. */
        broj = abs(broj);
        if (broj < 1000 || broj > 9999){
            fprintf(stderr, "-1\n");
            exit(EXIT_FAILURE);
        }

        /* Izdvajanje cifara zadatog broja. */
        cifra_jedinica = broj % 10;
        broj /= 10;

        cifra_desetica = broj % 10;
        broj /= 10;

        cifra_stotina = broj % 10;
        broj /= 10;

        cifra_hiljada = broj;

        /* Proverava da li je cifra desetica najveca cifra. */
        if (cifra_desetica >= cifra_jedinica && cifra_desetica >= cifra_stotina && cifra_desetica >= cifra_hiljada)
        {
            /* Ako jeste, ispisuje se ucitani broj. */
            printf("%d\n", broj_kopija);
       
            /* Pamti se informacija da je broj sa ovim svojstvom pronadjen. */
            postoji_broj = 1;
        }
    }

    /*  Ako broj sa trazenim svojstvom nije pronadjen, ispisuje se odgovarajuca poruka. */
    if (!postoji_broj){
        printf("0\n");
    }

    exit(EXIT_SUCCESS);
}
