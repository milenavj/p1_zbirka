#include <stdio.h>

int main(){
  
  char c1, c2, c3, c4, c5;
  int broj_malih_slova=0;
  
  
  /* Citamo karaktere */
  printf("Unesite karaktere: ");
  scanf("%c %c %c %c %c", &c1, &c2, &c3, &c4, &c5); 
  
  /* Proveravamo da li je prvi karakter malo slovo */
  if(c1>='a' && c1<='z'){
    /* I ako jeste, uvecavamo broj malih slova */
    broj_malih_slova++;
  }

  /* Proveravamo da li je drugi karakter malo slovo */
  if(c2>='a' && c2<='z'){
    /* I ako jeste, uvecavamo broj malih slova */
    broj_malih_slova++;
  }
  
  /* Proveravamo da li je treci karakter malo slovo */
  if(c3>='a' && c3<='z'){
    /* I ako jeste, uvecavamo broj malih slova */
    broj_malih_slova++;
  }
  
  /* Proveravamo da li je cetvrti karakter malo slovo */
  if(c4>='a' && c4<='z'){
    /* I ako jeste, uvecavamo broj malih slova */
    broj_malih_slova++;
  }
  
  /* Proveravamo da li je peti karakter malo slovo */
  if(c5>='a' && c5<='z'){
    /* I ako jeste, uvecavamo broj malih slova */
    broj_malih_slova++;
  }
  
  /* Ispisujemo rezultat */
  printf("Broj malih slova: %d\n", broj_malih_slova);
   
  return 0;
}
