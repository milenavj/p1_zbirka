/* Za ceo broj k izmedu 1 i 189 koji se unosi sa standardnog ulaza, odrediti
cifru koja se nalazi na k-toj poziciji
niza 12345678910111213....9899 u kom su redom ispisani brojevi od 1 do 99. */


#include <stdio.h>


int main(){
  int k, n, broj;
  
  printf("Unesite k: ");
  scanf("%d", &k);
 
  if(k<10){
    /* Trazi se jednocifren broj */
    printf("Na %d-toj poziciji je broj %d.\n", k, k);
  }
  else
    /* Trazi se dvocifreni broj */
    if(k>=10 && k<=189){
      
      /* Odredjujemo broj dvocifrenih brojeva koji se mogu zapisati pomocu
          k cifara */
      
        if(k%2!=0){
          /* Ako je k neparan broj, zapisan je ceo broj dvocifrenih brojeva */
          /* 9 oduzimamo jer je 9 broj cifara potrebnih za zapis jednocifrenih 
           * brojeva */
          n=(k-9)/2; 
          
          /* Broj o kojem se radi je */
          broj=9+n; 
          
          /* Ujedno, za neparno k se trazi cifra jedinica izdvojenog broja */
          printf("Na %d-toj poziciji je broj %d.\n", k, broj%10);
                  
        }
        else{
          /* Ako je k paran broj, zapisan je ceo broj dvocifrenih brojeva i
          zapoceto je sa zapisom sledeceg */
          /* 9 oduzimamo jer je 9 broj cifara potrebnih za zapis jednocifrenih 
           * brojeva */
          n=(k-9)/2 +1; 
          
          /* Broj o kojem se radi je */
          broj= 9 + n; 
          
          /* Ujedno, za parno k se trazi cifra desetica izdvojenog broja */
          printf("Na %d-toj poziciji je broj %d.\n", k, broj/10);
          
        }
    }
    else{
      printf("Greska: Nedozvoljena vrednost broja k!\n");
    }
  
  return 0;
}
