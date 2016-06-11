#include <stdio.h>
#include <stdlib.h> // Potrebno za exit funkciju

// Za unetu godinu i mesec ispisuje se naziv meseca i koliko dana ima u tom mesecu te godine

int main()
{
    int godina;
    int mesec;

    int prestupna;
    

    printf("Unesite godinu: ");
    scanf("%d",&godina);

    if(godina < 0)
    {
        printf("Lose uneta godina!\n");
        exit(EXIT_FAILURE);
    }
    
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) // Provera da li je godina prestupna,
        prestupna = 1;                                              // bitno za mesec februar
    else
        prestupna = 0;

    printf("Unesite redni broj meseca: ");
    scanf("%d",&mesec);

    switch(mesec)
    {
        case 1: printf("Januar, 31 dan\n");
                break;
        case 2: 
                if(prestupna)
                    printf("Februar, 29 dana\n");
                else
                    printf("Februar, 28 dana\n");
                break;

        case 3: printf("Mart, 31 dan\n");
                break;
        case 4: printf("April, 30 dana\n");
                break;
        case 5: printf("Maj, 31 dan\n");
                break;
        case 6: printf("Jun, 30 dana\n");
                break;
        case 7: printf("Jul, 31 dan\n");
                break;
        case 8: printf("Avgust, 31 dan\n");
                break;
        case 9: printf("Septembar, 30 dana\n");
                break;
        case 10: printf("Oktobar, 31 dan\n");
                break;
        case 11: printf("Novembar, 30 dana\n");
                break;
        case 12: printf("Decembar, 31 dan\n");
                break;
        default: printf("Lose unet redni broj meseca!\n");
    }

    return 0;
}
