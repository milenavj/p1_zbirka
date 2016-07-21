/* Sa standardnog ulaza se unosi cetvorocifreni pozitivan broj. Napisati program
koji racuna i ispisuje proizvod parnih cifara datog broja. Ukoliko uneti broj
nije pozitivna cetvorocifrena vrednost ispisati poruku Greska!. */

#include <stdio.h>

int main(){
  int n, j, d, s, h;
  int broj_parnih, proizvod_parnih;
  
  /* Ucitavamo broj */
  printf("Unesite broj: ");
  scanf("%d", &n);
  
  /* Proveravamo da li je unet cetvorocifreni broj */
  if(n<1000 || n>9999){
    /* Ako nije, prijavljujemo gresku */
    printf("Greska!\n");
  }
  else{
    
    /* Ako jeste: */
    
    /* Izdvajamo cifre broja:
      j -jedinice, d - desetice, s - stotine i h - hiljade 
    */
    j=n%10;
    d=(n/10)%10;
    s=(n/100)%10;
    h=n/1000;
    
    /* Inicijalizujemo broj parnih cifara na 0 */
    broj_parnih=0;
    /* Postavljamo proizvod parnih cifara na 1 (neutral za mnozenje) */
    proizvod_parnih=1;
    
    /* Proveravamo da li je cifra jedinica parna */
    if(j%2==0){
      proizvod_parnih=proizvod_parnih*j;
      broj_parnih++;
    }
    
    /* Proveravamo da li je cifra desetica parna */
    if(d%2==0){
      proizvod_parnih=proizvod_parnih*d;
      broj_parnih++;
    }
    
    /* Proveravamo da li je cifra stotina parna */
    if(s%2==0){
      proizvod_parnih=proizvod_parnih*s;
      broj_parnih++;
    }
    
    /* Proveravamo da li je cifra hiljada parna */
    if(h%2==0){
      proizvod_parnih=proizvod_parnih*h;
      broj_parnih++;
    }

    /* Proveravamo da li u zapisu broja ima parnih cifara i ispisujemo
      rezultat */
    if(broj_parnih==0){
      printf("Proizvod parnih cifara: 0\n");
    }
    else{
      printf("Proizvod parnih cifara: %d\n", proizvod_parnih);
    }
    
  }
  
  return 0;
  
}