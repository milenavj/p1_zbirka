#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Struktura koja opisuje kutiju. */
typedef struct
{
    int sirina, duzina, visina;
} Kutija;

/* Funkcija koja proverava da li se u zadatu kutiju koja se nalazi u nizu kutija na poziciji j mogu 
smestiti preostale kutije. Povratna vrednost funkcije je 1 ako kutije mogu da se smeste, a u suprotnom 0. */
int smesti(Kutija kutije[], int n, Kutija *kutija, int j)
{
    int i;

    /* Uporedjuju se dimenzije zadate j-te kutije sa dimenzijama svih preostalih kutija. */ 
    for (i = 0; i < n; i++)
    {
        if (i != j && (kutije[i].sirina >= kutija->sirina || kutije[i].duzina >= kutija->duzina || kutije[i].visina >= kutija->visina))
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    /* Deklaracija potrebnih promenljivih. */
    Kutija kutije[MAX];
    int i, n;

    /* Ucitavanje broja kutija i provera ispravnosti unosa. */
    scanf("%d", &n);
    if (n <= 0 || n > MAX)
    {
        printf("-1\n");
        exit(EXIT_FAILURE);
    }

    /* Ucitavanje dimenzija kutija uz proveru ispravnosti unos. */
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &kutije[i].sirina, &kutije[i].duzina, &kutije[i].visina);
        if (kutije[i].sirina <= 0 || kutije[i].duzina <= 0 || kutije[i].visina <= 0)
        {
            printf("-1\n");
            exit(EXIT_FAILURE);
        }
    }

    /* Za svaku kutiju se proverava trazeno svojstvo. */
    for (i = 0; i < n; i++)
    {
        /* Ukoliko u i-tu kutiju mogu da se smeste preostale kutije, izracunava se i ispisuje njena zapremina. */
        if (smesti(kutije, n, &kutije[i], i))
        {
            printf("%d\n", kutije[i].sirina * kutije[i].duzina * kutije[i].visina);
            exit(EXIT_SUCCESS);
        }
    }

    /* U suprotnom, zakljucujemo da ne postoji kutija sa trazenim svojstvom. */
    printf("0\n");

    exit(EXIT_SUCCESS);
}
