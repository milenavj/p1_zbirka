/* 
Napisati funkciju void kopiraj_n(char t[], char s[], int n) koja kopira najvise n karaktera niske s u nisku t. 
Napisati i program koji ucitava nisku maksimalne duzine 20 karaktera i jedan ceo broj i testira rad napisane funkcije. 
*/

#include <stdio.h>
#define MAX_DUZINA 20

void kopiraj_n(char t[], char s[], int n){	
	int i;

	/* Brojac i oznacava tekucu poziciju u niski */
	/* Uslov i<n je neophodan zbog kopiranja najvise n karaktera */
	/* Uslov s[i]!='\0' (ili skraceno samo s[i]) je neophodan kako bi bili sigurni da na poziciji i postoji karakter u niski s */
	for(i=0; i<n && s[i]!='\0'; i++){
		t[i]=s[i];
	}
	
	/* Upisujemo terminirajucu nulu u novodobijenu nisku */
	t[i]='\0';
}


int main() {
	int n;
	char s[MAX_DUZINA+1], t[MAX_DUZINA+1];

	/* Ucitavamo nisku */	
	printf("Unesite nisku: ");
	scanf("%s", s);

	/* Ucitavamo broj n i proveravamo korektnost unosa */	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<0 || n>MAX){
		printf("Greska: pogresan unos!\n");
		return 0;
	}

	/* Pozivamo funkciju za kopiranje */
	kopiraj_n(t, s, n);
	
	/* Ispisujemo dobijenu nisku */
	printf("Rezultujuca niska: %s\n", t);
	
	return 0;
}
