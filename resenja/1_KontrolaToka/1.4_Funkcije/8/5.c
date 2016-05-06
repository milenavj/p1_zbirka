/*
	Napisati funkciju void grafikon_h(int a, int b, int c, int d) koja vrsi horizontalno prikazivanje zadatih vrednosti. 
	Napisati program koji ucitava cetiri pozitivna cela broja i prikazuje rezultat poziva funkcije. 
	U slucaju pogresnog unosa, ispisati poruku o gresci.
*/

#include<stdio.h>

/* Funkcija koja stampa n zvezdica za kojima sledi znak za novi red */
void stampaj_zvezdice(int n){
	int i;
	for(i=0; i<n; i++)
	  printf("*");
	  
  printf("\n");
}

/* Funkcija koja crta grafikon */
void grafikon_h(int a, int b, int c, int d) 
{
  int i;
  
  /* Prvo ispisujemo a zvezdica */
  stampaj_zvezdice(a);
  
  /* Zatim u sledecem redu b zvezdica */
  stampaj_zvezdice(b);
  
  /* Zatim u sledecem redu c zvezdica */
  stampaj_zvezdice(c);
  
  /* Zatim u poslednjem redu d zvezdica */
  stampaj_zvezdice(d);
  
}

int main(){
  int a,b,c,d;
  
  /* Ucitavamo vrednosti a,b,c,d */
  printf("Unesite vrednosti: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);
  
  /* Proveravamo korektnost ulaza i ispisujemo rezultat */
  if(a <0 || b<0 || c<0 || d<0){
	printf("Greska: pogresan unos!\n");
  }else{
	grafikon_h(a,b,c,d);
  }
  
  return 0;
}
