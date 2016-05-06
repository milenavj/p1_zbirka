/* Napisati program koji proverava da li je dati prirodan broj palindrom. Broj
je palindrom ako se isto cita i sa leve i sa desne strane. */

#include <stdio.h>
#include <math.h>

int main() {

  int x;
  int broj_cifara;
  int min_stepen, max_stepen;
  int pom;
  int leva_cifra, desna_cifra;
  int indikator;
  
  printf("Unesite broj: ");
  scanf("%d", &x);
  
  /* Ako je korisnik uneo negativan broj, analiziramo njegovu apsolutnu
   * vrednost 
   */
  if(x < 0) 
    x=-x;
 
  
    /* Odredjujemo broj cifara u zapisu broja x 
      kako bismo mogli da izdvajamo istovremeno cifre i sa leve i sa desne
      strane
    */
    broj_cifara = 0;
    pom = x;
    while(pom > 0) {
      pom /= 10;
      broj_cifara++;
    }
    
    /* Odredjujemo stepen koji stoji uz krajnju levu cifru broja */
    max_stepen = (int) pow (10, broj_cifara-1);
  
    /* Indikator je promenljiva koja ce nam ukazivati da li je broj 
     * palindrom ili ne 
     */
    indikator=1;
    while(x!=0 && indikator==1){
        /* Izdvajamo levu cifru */
        leva_cifra=x/max_stepen;
        /* Izdvajamo desnu cifru */
        desna_cifra=x%10;
        /* Ako su cifre razlicite, odmah mozemo da zakljucimo da 
         * broj nije palindrom i da prekinemo izvrsavanje petlje */
        if(leva_cifra!=desna_cifra){
          indikator=0;
          break;
        }
        /* Formiramo novu vrednost broja x tako sto odbacujemo
         * krajnju levu i krajnju desnu cifru */
        x=(x%max_stepen-x%10)/10;
        /* I korigujemo maksimalan stepen tako dobijenog broja - 
         * delimo sa 100 jer smo odbacili 2 cifre */
        max_stepen=max_stepen/100;
    }
    
    /* Ispisujemo rezultat */
    if(indikator==1)
      printf("Broj je palindrom!\n");
    else
      printf("Broj nije palindrom!\n");
    
  
  return 0;
}
