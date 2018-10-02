#include<stdio.h>
#include<math.h>

int rotacija(int n){
  
  int broj, br = 0, znak;
  
  /* Ako je broj jednocifren, nema potrebe da se rotira. */
  if(n>-10 && n < 10)
	 return n;

  /* Odredjivanje znaka broja. */
  znak=(n<0) ? -1: 1; 
  
  /* Nadalje se radi sa apsolutnom vrednoscu broja. */
  n=abs(n);
  
  /* U promenljivoj broj se cuva kopija broja n. */
  broj=n;
  
  /* Izdvaja se cifra po cifra, sve do krajnje leve cifre broja (one koja treba da postane krajnje desna), npr za n = 1234, treba da se izdvoji prvi broj = 1 i ostatak = 234, a zatim na kraj ostataka treba dodati prvu cifru = 2341. */
  
  /* Nakon zavrsetka ove petlje, u parametru n se nalazi najlevlja cifra broja (koja treba da postane krajnje desna), dok se u parametru br nalazi broj cifara unetog broja. */
  while(n >=10){
	  n/=10;
	  br++;
  }
  
  /* Ostatak (234) se dobija kao n%(10^broj_cifara). Zatim se ostatak pomnozi sa 10, da bi se broj uvecao za jednu, poslednju cifru (2340). Na kraju, na dobijeni broj se doda (sabre) prvi broj koji se nalazi u parametru n. */
   
  return znak* ((broj%(int)pow(10, br))*10 + n);
}

int main(){
  
  int n;
  while(1){
	
	/* Unos broja. */
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	/* Broj 0 oznacava kraj unosa. */
	if(n == 0)
	  break;
	
	/* Poziv funkcije i stampanje broja rotiranog za jedno mesto u levo. */
	printf("%d\n", rotacija(n));
  }
  
  
  return 0;
}
