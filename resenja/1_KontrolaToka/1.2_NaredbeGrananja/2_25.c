
#include <stdio.h>
#include <math.h>
int main(){
	float x; 
	int k;
	float F;
	
	printf("Unesite redom x i k: ");
	scanf("%f %d", &x, &k);
	
    /* Proveravamo vrednost za k */
	if(k<1 || k>3){
		printf("Greska: nedozvoljena vrednost za k!\n");
		return 0;
	}
	printf("F(%f,%d)=", x, k);
	
    /* Analiziramo moguce slucajeve */
	if(k==1){
		F=2*cos(x)-x*x*x;
	}
	else{
		if(k==2){
			x=2*cos(x)-x*x*x;
			F=2*cos(x)-x*x*x;
		}
		else{
				x=2*cos(x)-x*x*x;
				x=2*cos(x)-x*x*x;
				F=2*cos(x)-x*x*x;
			}
		
	}
	
	/* Ispisujemo rezultat */
	printf("%f\n", F);

	return 0;
}
