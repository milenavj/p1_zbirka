#include <stdio.h>
#include <ctype.h>

int main()
{
    int br_cif = 0;
    
    /*
       Funkcija isdigit vraca 1 ako je
       dati karakter cifra i 0 u suprotnom.
       Nalazi se u biblioteci ctype.h.       
    */
    if (isdigit(getchar()))
        br_cif++;
    if (isdigit(getchar()))
        br_cif++;
    if (isdigit(getchar()))
        br_cif++;
    if (isdigit(getchar()))
        br_cif++;
    if (isdigit(getchar()))
        br_cif++;

    printf("%d\n", br_cif);

    return 0;
}