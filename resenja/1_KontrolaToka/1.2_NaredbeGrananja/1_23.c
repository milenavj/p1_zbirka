#include <stdio.h>

// Za uneti datum odreduje ispisuje se naziv godisnjeg doba kome datum pripada

int main()
{
    int godina;
    int mesec;
    int dan;
    
    printf("Unesite datum (DD MM GGGG): ");
    scanf("%d%d%d", &dan, &mesec, &godina);
    
    if(dan < 0 || godina < 0)
        printf("Lose unet datum!\n");
    
    switch(mesec) // Dodati provere za redni broj dana!
    {
        case 1: printf("Zima\n");
                break;
                
        case 2: printf("Zima\n");
                break;
                
        case 3:
                if(dan < 21)
                    printf("Zima\n");
                else
                    printf("Prolece\n");
                break;
                
        case 4: printf("Prolece\n");
                break;
                
        case 5: printf("Prolece\n");
                break;
                
        case 6: 
                if(dan < 21)
                    printf("Prolece\n");
                else
                    printf("Leto\n");
                break;
                
        case 7: printf("Leto\n");
                break;
                
        case 8: printf("Leto\n");
                break;
                
        case 9: 
                if(dan < 23)
                    printf("Leto\n");
                else
                    printf("Jesen\n");
                break;
                
        case 10: printf("Jesen\n");
                 break;
                 
        case 11: printf("Jesen\n");
                 break;
        
        case 12:
                if(dan < 22)
                    printf("Jesen\n");
                else
                    printf("Zima\n");
                break;
                
        default: printf("Lose unet redni broj meseca!\n");
    }

    return 0;
}