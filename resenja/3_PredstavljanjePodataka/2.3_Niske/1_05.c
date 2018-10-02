/* 
  Napisati program koji pretvara nisku u ceo broj.
  Npr. za ulaz "-1238" se generise rezultat -1238
  Pogledati funkcije atoi i atof koje postoje u biblioteci stdlib.h
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 10
/*
  String b se sastoji od karaktera koji
  cine jedan ceo broj, onim redom kojim
  se karakteri pojavljuju u zapisu broja.
  
  Ako je prvi karakter stringa b '-',
  to znaci da je broj negativan i 
  funkcija znak_broja vraca -1
    
  U suprotnom, broj je pozitivan i 
  funkcija znak_broja vraca 1  
  
*/

int znak_broja(char b[])
{
   if(b[0]=='-')
      return -1;
   return 1;
}


/*
  Funkcija formiraj_broj na osnovu
  karaktera koji cine broj iz stringa
  b vraca ceo broj koji odgovara 
  zapisu datom u stringu b.
  
  Ako su cifre broja a,b,c i d, tada
  broj mozemo kreirati kao:
  a*10^3 + b*10^2 + c*10^1 + d*10^0
  
  Medjutim, efikasnije je koristiti
  Hornerovu semu:
  
  10*(10*(10*(10*0 + a)+b)+c)+d    
  
*/

int formiraj_broj(char b[])
{
   int i;
   int n=0;
   int znak = znak_broja(b);
   
   /*
     Ako je broj negativan, cifre u nizu b
     pocinju od indeksa 1
   */

   i=0;
   if(znak==-1)
      i=1;

   /*
     Funkcija isdigit proverava da li je broj 
     cifra. Nalazi se u biblioteci ctype.h
     
     Proveravamo da li je karakter u zapisu
     broja cifra kako bismo se osigurali
     od nekorektnog unosa, npr ako korisnik
     unese -123abc. Ovaj unos je moguc jer
     se vrsi sa scanf("%s",broj), gde unosimo
     karaktere do prvog blanko znaka
     
     Ako naidjemo na karakter koji nije cifra,
     prekidamo petlju
     
   */
   for(; b[i]!='\0'; i++)
      if(isdigit(b[i]))
         n = n*10 + b[i] - '0';
      else
         break;
         
   /* Formirani broj mnozimo znakom: */      
   
   n*=znak;
   return n;
 
}

int main()
{
   char broj[MAX];
   int n;
	
   /* Ucitavamo broj: */
   scanf("%s", broj);
        
   /* Ispisujemo rezultat: */
   printf("Broj zapisan kao int: %d\n", formiraj_broj(broj));

   return 0;
}