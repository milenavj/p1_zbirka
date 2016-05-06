
/*
Napisati program koji poziva korisnika da unese jedan karakter i ispisuje
da li je uneti karakter samoglasnik.
*/

#include <stdio.h>

int main()
{
	char c;
	printf("Unesi jedan karakter:");
	scanf("%c", &c);
	switch(c)
	{
		case 'A' : 
		case 'E' : 
		case 'I' : 
		case 'O' : 
		case 'U' : 
		case 'a' : 
		case 'e' : 
		case 'i' : 
		case 'o' : 
		case 'u' : printf("Uneli ste samoglasnik\n");
				   break;
		default : printf("Niste uneli samoglasnik\n");
				  break;  
	}

	return 0;
}

