/* 
Napisati funkciju void dupliranje(char t[], char s[]) koja na osnovu niske s formira nisku t tako sto duplira svaki
karakter niske s. Napisati i program koji ucitava nisku maksimalne duzine 20 karaktera i testira rad napisane funkcije.
*/

#include <stdio.h>
#define MAX_DUZINA 20

void dupliranje(char t[], char s[]){
	int i, j;
	
	/* Brojac i oznacava tekucu poziciju u niski s */
	/* Brojac j oznacava tekucu poziciju u niski t */
	for(i=0, j=0; s[i]!='\0'; i++, j+=2){
		t[j]=s[i];
		t[j+1]=s[i];
	}
	
	/* Upisujemo terminirajucu nulu u novodobijenu nisku */
	t[j]='\0';
}


int main(){
	int n;
	char s[MAX_DUZINA+1], t[2*MAX_DUZINA+1];

	/* Ucitavamo nisku */	
	printf("Unesite nisku: ");
	scanf("%s", s);

	/* Pozivamo funkciju za dupliranje */
	dupliranje(t, s);
	
	/* Ispisujemo dobijenu nisku */
	printf("%s\n", t);
	
	return 0;
}

