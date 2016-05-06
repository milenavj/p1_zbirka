/*
	Napisati funkciju int rotacija(int n) koja rotira cifre zadatog broja za jednu poziciju u levo. 
	Napisati program koji za brojeve koji se unose sa standardnog ulaza sve do pojave broja 0 ispisuje rezultat primene funkcije.
*/

#include<stdio.h>
#include<math.h>

int rotacija(int n){
  
  /* U promenljivoj broj pamtimo originalnu vrednost n */
  int broj, br = 0, znak;
  
  /* Odredjujemo znak broja */
  znak=(n<0) ? -1: 1; 
  
  /* I nadalje radimo sa apsolutnom vrednoscu broja */
  n=abs(n);
  
  /* U promenljivoj broj cuvamo kopiju broja n */
  broj=n;

  /* Ako je broj jednocifren, nema potrebe da ga rotiramo. */
  if(n>-10 && n < 10)
	  return n;
  
  /* Petljom izdvajamo cifru po cifru, kako bismo dosli do krajnje leve cifre broja
   (one koja treba da postane krajnje desna), npr za n = 1234, treba da dobijemo 1,
   zatim da "pomerimo" 234 u levo i da na kraj nalepimo 1 = 2341 */
  
  /* Na kraju ove petlje, u n se nalazi najlevlja cifra broja (koja treba da postane krajnje desna),
   dok se u br nalazi broj cifara unetog broja */
  while(n >=10){
	  n/=10;
	  br++;
  }
  
  /* 
   Levi deo (234) dobijamo kao n%(10^broj_cifara)
   Zatim levi deo pomnozimo sa 10, da bi dobili 2340
   Zatim na levi deo dodamo desni deo (1) koja se nalazi u promenljivoj n
   */
   
  return znak* ((broj%(int)pow(10, br))*10 + n);
}

int main(){
  
  int n;
  while(1){
	
	/* Ucitavamo broj */
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	/* Ako je uneta 0, izlazimo iz petlje */
	if(n == 0)
	  break;
	
	/* Stampamo broj rotiran za jedno mesto u levo */
	printf("%d\n", rotacija(n));
  }
  
  
  return 0;
}
