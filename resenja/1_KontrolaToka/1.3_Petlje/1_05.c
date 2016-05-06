/*
  Napisati program koji omogucava korisniku da unosi cele brojeve dok
  ne unese nulu. Nakon toga ispisati proizvod onih unetih brojeva koji
  su pozitivni.
*/

#include <stdio.h>
int main()
{
  int x;
  int p;
  
  p=1;
  while (1) /* izraz 1 je konstantan; razlicit je od nule sto znaci da ga tumacimo kao tacnog */
  {         
     printf("Unesi jedan ceo broj:");
     scanf("%d", &x);
     if (x==0)  /* ukoliko je uneta nula */
        break;  /* break prekidamo petlju; izvrsavanje se nastavlja od prve naredbe nakon petlje  */
        
     if (x<0)     /* ukoliko je unet negativan broj, tu vrednost ne zelimo da pomnozimo sa ukupnim proizvodom p; zato moramo nastaviti dalje */
        continue;  /* sa izvrsavanjem petlje; continue prekida trenutnu iteraciju petlje tako sto preskace sve naredbe 
                      koje nakon njega slede; izvrsavanje se nastavlja od provere uslova petlje  */
     p=p*x;
  }
  
  printf("Proizvod unetih brojeva je %d\n",p);  
  
  return 0;   
}