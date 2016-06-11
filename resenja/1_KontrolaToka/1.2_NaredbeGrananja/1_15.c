#include <stdio.h>

int main()
{
    int broj;
    scanf("%d", &broj);

    /* Uzimamo apsolutnu vrednost broja,
       jer nas interesuju cifre, ne i znak.

       Racunamo je tako sto broj negiramo
       ako je manji od nule, a ako nije
       ne menjamo ga. */
    broj = (broj < 0) ? -broj : broj;

    /* Ako broj nije cetvorocifren,
     * zavrsavamo program */
    if (broj <= 999 || broj >= 10000)
    {
        printf("-1");
        /* return u main funkciji zavrsava program,
           bilo koja vrednost koja se vrati a da
           nije 0, predstavlja gresku. Uobicajeno je
           da to bude -1, ali videcemo da postoji i
           "prenosiviji" nacin da ovo uradimo */
        return -1;
    }

    /* Izdvajamo cifre broja */
    int d = broj % 10;
    int c = (broj / 10) % 10;
    int b = (broj / 100) % 10;
    int a = broj / 1000;

    /* Pretpostavljamo da je najveca cifra a */
    int max = a;

    /* Ako je b veca od a, onda je b maksimum */
    if (b > max)
        max = b;
    /* Ako je c veca od trenutnog maksimuma, bilo
       da je on a bilo da je on b, onda je c maksimum */
    if (c > max)
        max = c;
    /* Slicno za d */
    if (d > max)
        max = d;

    /* Stampamo rezultat */
    printf("%d\n", max);

    return 0;
}