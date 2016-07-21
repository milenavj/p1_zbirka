#include<stdio.h>

int maksimum(int a, int b, int c, int d){
	int max;
	
	max=a;
	if(b>max)
		max=b;
	if(c>max)
		max=c;
	if(d>max)
		max=d;
		
	return max;
}

/* Funkcija koja iscrtava vertikalni grafikon */
void grafikon_v(int a, int b, int c, int d){
  int i, max;
  
  /* Na pocetku je potrebno pronaci najvecu od ove cetiri vrednosti */
  max=maksimum(a, b, c, d);
    
  /* Grafikon ukupno ima max horizontalnih linija */
  for(i=0; i<max; i++){
	
    /* U svakoj od horizontalnih linija se nalazi po 4 polja:
	 	polje za a,b,c i d uspravnu liniju.
	 	U svako od polja treba da se upise ili * ili belina,
	 	u zavisnosti od vrednosti a i toga u kojoj liniji se trenutno nalazimo
	 */
	
	/* Proveravamo uslov za polje a */
	if(i<max-a)
	  printf(" ");
	else
	  printf("*");
	
	/* Proveravamo uslov za polje b */
	if(i<max-b)
	  printf(" ");
	else
	  printf("*");

	/* Proveravamo uslov za polje c */
	if(i<max-c)
	  printf(" ");
	else
	  printf("*");

	/* Proveravamo uslov za polje d */
	if(i<max-d)
	  printf(" ");
	else
	  printf("*");
	
	/* Na kraju svake horizontalne linije stampamo novi red */
	printf("\n");
  }
}

int main(){
  int a,b,c,d;
  
  /* Ucitavamo vrednosti a,b,c,d */
  printf("Unesite vrednosti: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);
  
  /* Proveravamo korektnost ulaza i stampamo grafikon */
  if(a <0 || b<0 || c<0 || d<0)
	printf("Greska: pogresan unos!\n");
  else
	grafikon_v(a,b,c,d);
  
  return 0;
}
