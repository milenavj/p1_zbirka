#include <stdio.h>
#include <ctype.h> // !!!

// Upotreba funkcija isalpha, isdigit, toupper, tolower

// isalpha( karakter ) - funkcija vraca vrednost razlicitu od 0 ako je karakter slovo (malo ili veliko), inace 0
// isdigit( karakter ) - funkcija vraca vrednost razlicitu od 0 ako je karakter cifra, inace 0
// isupper( karakter ) - funkcija vraca vrednost razlicitu od 0 ako je karakter veliko slovo, inace 0
// islower( karakter ) - funkcija vraca vrednost razlicitu od 0 ako je karakter malo slovo, inace 0
// toupper( karakter ) - ukoliko je karakter malo slovo, funkcija vraca odgovarajuce veliko slovo,
//                       inace vraca isti karakter
// tolower( karakter ) - ukoliko je karakter veliko slovo, funkcija vraca odgovarajuce malo slovo,
//                       inace vraca isti karakter

int main()
{
    char c;
    char veliko_slovo;
    char malo_slovo;
    
    printf("Unesite karakter: ");
    scanf("%c",&c);
    
    if(isalpha(c))
    {
        printf("Karakter %c je slovo\n",c);
        
	if(isupper(c))
		printf("Veliko slovo\n");
	else
		printf("Malo slovo\n");

        veliko_slovo = toupper(c); // malo -> veliko slovo
        malo_slovo = tolower(c);   // veliko -> malo slovo
        
        printf("Veliko slovo: %c, malo slovo: %c\n", veliko_slovo, malo_slovo);
        
    }
    else if(isdigit(c))
        printf("Karakter %c je cifra\n",c);
    else
        printf("Karakter %c je znak\n",c);
    
    
    
    printf("============Bez koriscenja funkcija============\n");
    
    // Isti rezultat bez koriscenja ugradjenih funkcija
    
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        printf("Karakter %c je slovo\n",c);

	if(c >= 'A' && c <= 'Z')
		printf("Veliko slovo\n");
	else
		printf("Malo slovo\n");
        
        if(c >= 'a' && c <= 'z')
	{
            veliko_slovo = c - ('a' - 'A');
	    malo_slovo = c;
	}
        else if(c >= 'A' && c <= 'Z')
	{
            malo_slovo = c + ('a' - 'A');
	    veliko_slovo = c;
	}
        
        
        printf("Veliko slovo: %c, malo slovo: %c\n", veliko_slovo, malo_slovo);
    }
    else if(c >= '0' && c <= '9')
        printf("Karakter %c je cifra\n",c);
    else
        printf("Karakter %c je znak\n",c);
    

    return 0;
}
