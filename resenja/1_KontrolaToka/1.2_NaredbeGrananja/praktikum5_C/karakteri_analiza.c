/* Sa standarnog ulaza unosi se jedan karakter. Ako je u pitanju malo slovo,
zameniti ga odgovaraju ́im velikim slovom i ispisati na standardni izlaz. Ako je
u pitanju veliko slovo, zameniti ga odgovaraju ́im malim slovom 
i ispisati ga na standardni izlaz. Ako je u pitanju cifra ispisati poruku cifra.
Ako je u pitanju bilo koji drugi karakter, onda ga ispisati na standarni izlaz
izmedu dveju zvezdica. */

#include <stdio.h>

int main(){
  
  char c;
 
  /* Citamo karakter */
  printf("Unesite karakter: ");
  scanf("%c", &c); 
  
  /* Proveravamo da li je karakter malo slovo */
  if(c>='a' && c<='z'){
    /* I ako jeste, ispusujemo odgovarajuce veliko slovo */
    printf("%c\n", c-'a'+'A'); 
  }
  else{
    /* Proveravamo da li je karakter veliko slovo */
    if(c>='A' && c<='Z'){
      /* I ako jeste, ispusujemo odgovarajuce malo slovo */
      printf("%c\n", c-'A'+'a'); 
    }
    else{
      /* Proveravamo da li je karakter cifra */
      if(c>='0' && c<='9'){
        /* I ako jeste, ispusujemo odgovarajucu poruku */
        printf("cifra\n"); 
      }
      else{
        /* Inace ispisujemo karakter izmedju dveju zvezdica */
        printf("*%c*\n",c);
      }
    }
  }
  
  return 0;
}
