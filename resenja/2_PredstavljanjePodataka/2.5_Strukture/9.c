#include <stdio.h>
#include <math.h>

#define MAX 50

typedef struct lopta {
  int poluprecnik; 
  enum {plava, zuta, crvena, zelena} boja; 
} LOPTA;

float zapremina(LOPTA l) {
 return pow(l.poluprecnik, 3)*4/3*M_PI;
}


float ukupna_zapremina(LOPTA lopte[], int n) {
  
  int i;
  float z = 0;
  
  for(i = 0; i < n; i++)
    z += zapremina(lopte[i]);
    
  return z;
}

/* 
	Funkcija je opstija od trazene i broji sve lopte odredjene boje u nizu lopti.
	U zavisnosti od prosledjene boje funkciji, funkcija vraca odgovarajuci broj.
*/
int broj_lopti_u_boji(LOPTA lopte[], int n, int boja) {

  int br = 0;
  int i;
  for(i = 0; i < n; i++)
    if(lopte[i].boja == boja)
      br++;
  return br;
}

int main() {

  LOPTA lopte[MAX];
  int n;
  int i;
  int boja;
  
  printf("Unesite broj lopti: ");
  scanf("%d", &n);
  
  if(n < 1 || n > MAX) {
  
    printf("Nekorektan unos.\n");
    return 0;
  }
  
  printf("Unesite dalje poluprecnike i boje lopti (1-plava, 2-zuta, 3-crvena, 4-zelena):\n");
  for(i = 0; i < n; i++) {
  
    printf("%d. lopta: ", i+1);
    scanf("%d%d", &lopte[i].poluprecnik, &boja);
	
	/* U zavisnosti od unetog celog broja,
	   bira se boja lopte.
	 */
    switch(boja) {
    
      case 1: lopte[i].boja = plava; break;
      case 2: lopte[i].boja = zuta; break;
      case 3: lopte[i].boja = crvena; break;
      case 4: lopte[i].boja = zelena; break;
      default:
	    	printf("Nekorektan unos.\n");
	    return 0;
    }
  }
    
  printf("Ukupna zapremina: %.2f\n", ukupna_zapremina(lopte, n));
 
  printf("Ukupno crvenih lopti: %d\n", broj_lopti_u_boji(lopte, n, crvena));

  return 0;
}
