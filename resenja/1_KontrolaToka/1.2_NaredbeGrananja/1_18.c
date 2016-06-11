#include <stdio.h>
#include <ctype.h>

int main()
{
    int br_cif = 0;
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