#include <stdio.h>
#define MAX_DUZINA 20
#define MAX_BR_GRADOVA 50

typedef struct Grad{
	char ime_grada[MAX_DUZINA+1];
	float temperatura;
}Grad;


int main(){
	int n, i;
	Grad grad[MAX_BR_GRADOVA];
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<0 || n>MAX_BR_GRADOVA){
		printf("Greska: pogresan unos!\n");
		return 0;
	}
	
	for(i=0; i<n; i++){
		printf("Unesite grad i temperaturu: ");
		scanf("%s %f", grad[i].ime_grada, &grad[i].temperatura);
	}
	
	printf("Gradovi sa idealnom temperaturom za klizanje u decembru:\n");
	for(i=0; i<n; i++){
		if(grad[i].temperatura>=3 && grad[i].temperatura<=8){
			printf("%s\n", grad[i].ime_grada);
		}
	}
	
	return 0;
}

