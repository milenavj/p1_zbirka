#include <stdio.h>

int main()
{
    int br1, br2, br3;
    scanf("%d%d%d", &br1, &br2, &br3);

    if (br1 > 999 || br1 < 100 || br2 > 999 || br2 < 100 
            || br3 > 999 || br3 < 100) 
    {
        printf("Nekorektan unos\n");
        return -1;
    }

    int max1 = br1;
    if (br2 > max1)
        max1 = br2;
    if (br3 > max1)
        max1 = br3;

    /* Ako je br1 vec najveci, onda pretragu
       za sledecim najvecim krecemo od br2 */
    int max2 = br1 != max1 ? br1 : br2;
    if (br1 > max2 && br1 != max1)
        max2 = br1;
    if (br2 > max2 && br2 != max1)
        max2 = br2;
    if (br3 > max2 && br3 != max1)
        max2 = br3;

    int rez = max1*1000 + max2;
    printf("%d\n",rez);

    return 0;

}