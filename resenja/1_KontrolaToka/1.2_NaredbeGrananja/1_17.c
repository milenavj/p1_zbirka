#include <stdio.h>
#include <ctype.h>

int main()
{
    int br_a = 0;
    if (tolower(getchar()) == 'a')
        br_a++;
    if (tolower(getchar()) == 'a')
        br_a++;
    if (tolower(getchar()) == 'a')
        br_a++;
    if (tolower(getchar()) == 'a')
        br_a++;
    if (tolower(getchar()) == 'a')
        br_a++;

    printf("%d\n", br_a);

    return 0;
}