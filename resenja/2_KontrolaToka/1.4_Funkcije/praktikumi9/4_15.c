#include <stdio.h>

/* Funkcija racuna broj x na n-ti stepen. */
int stepen(int x, int n) {

  int i; 
  int st = 1;
  
  for(i = 1; i <= n; i++)
    st *= x;
  
  return st;
}

/* Funkcija odredjuje broj cifara broja. */
int broj_cifara(int x)
{
	int i=0;

	while(x)
	{
		i++;
		x /= 10;
	}

	return i;
}

/* Funkcija proverava da li je broj Armstrongov. */
int armstrong(int x) {

	/* U y se cuva zbir i-tih stepena cifara. */
	int suma = 0;
	/* Stepen za koji se proverava. */
	int i = broj_cifara(x); 
	/* Prilikom izdvajanja cifara, broj x se menja i zato se koristi dodatna promenljiva u kojoj se cuva vrednost x pre promena. */
	int original = x; 
 
	while(x) {
      /* Za svaku izdvojenu cifru Racunanje stepen i dodaje na ukupnu sumu. */
		suma += stepen(x % 10, i);
		x /= 10;
	}

   /* Nakon rada petlje x je postao 0 pa se zato poredjenje vrsi sa pomocnom promenljivom. Ukoliko je broj Armstrongov izracunata suma i originalan broj su jednaki. */
	return original == suma;
}

int main() {

  int x;
  printf("Unesite broj: ");
  scanf("%d", &x);
  
  if(armstrong(x))
    printf("Broj je Armstrongov!\n");
  else
    printf("Broj nije Armstrongov!\n");
  
  return 0;
}
