#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_DUZINA 21
#define MAKS_DUZINA_OZNAKE 3
#define MAKS_BROJ_ELEMENATA 120

/* Struktura koja opisuje hemijski element. */
typedef struct Hemijski_element
{
    char naziv[MAKS_DUZINA];
    char oznaka[MAKS_DUZINA_OZNAKE];
    int broj_neutrona;
} Hemijski_element;

int main()
{
    /* Deklaracija potrebnih promenljivih. */
    Hemijski_element elementi[MAKS_BROJ_ELEMENATA];
    int i, n;
    char naziv_trazenog_elementa[MAKS_DUZINA];
    char nadjen;

    /* Ucitavanje hemijskih elemenata. */ 
    for (i = 0; ; i++)
    {
        /* Prvo se ucitava naziv elementa. */
        scanf("%s", elementi[i].naziv);

        /* Ako je u pitanju rec kraj, ucitavanje hemijskih elemenata se prekida. */
        if (strcmp(elementi[i].naziv, "kraj") == 0)
        {
            break;
        }

        /* U suprotnom, ucitava se oznaka elementa i broj neutrona. */
        scanf("%s%d", elementi[i].oznaka, &elementi[i].broj_neutrona);
    }

    /* Poslednja vrednost brojaca i odgovara broju elemenata ucitanog niza. */
    n = i;

    /* Ucitavanje naziva trazenog elementa. */
    scanf("%s", naziv_trazenog_elementa);

    /* Provera da li se trazeni element nalazi u nizu elemenata. */
    /* Informacija da li se element nalazi u nizu ili ne bice upisana kao vrednost 1 ili 0 u promenljivu nadjen. */
    nadjen = 0;
    for (i = 0; i < n; i++)
    {
        if (strcmp(elementi[i].naziv, naziv_trazenog_elementa) == 0)
        {
            nadjen = 1;
            printf("%s %d\n", elementi[i].oznaka, elementi[i].broj_neutrona);
            break;
        }
    }

    /* Ukoliko se trazeni element ne nalazi u nizu elemenata, ispisuje se odgovarajuca poruka. */
    if (!nadjen)
    {
        fprintf(stderr, "-1\n");
    }

    return 0;
}
