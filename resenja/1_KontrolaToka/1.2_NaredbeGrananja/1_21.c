#include <stdio.h>

// Za uneti redni broj dana u nedelji ispisati njegov naziv

int main()
{
    int broj_dana;

    printf("Unesite broj dana: ");
    scanf("%d",&broj_dana);

    switch(broj_dana)
    {
        case 1: printf("Dan je ponedeljak\n");
                break; // Obavezan izlazak iz case-a!
        case 2: printf("Dan je utorak\n");
                break; // Obavezan izlazak iz case-a!
        case 3: printf("Dan je sreda\n");
                break; // Obavezan izlazak iz case-a!
        case 4: printf("Dan je cetvrtak\n");
                break; // Obavezan izlazak iz case-a!
        case 5: printf("Dan je petak\n");
                break; // Obavezan izlazak iz case-a!
        case 6: printf("Dan je subota\n");
                break; // Obavezan izlazak iz case-a!
        case 7: printf("Dan je nedelja\n");
                break; // Obavezan izlazak iz case-a!
        default: printf("Lose unet broj!\n"); // Ako ni jedna provera ne prolazi
    }

    return 0;
}