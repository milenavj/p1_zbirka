#include <stdio.h>
int main()
{
  int x;
  /* U promenljivoj p pamtimo prozivod. */
  int p;
  /* U promenljivoj u proveravamo da li
   * su brojevi uopste uneseni. Na pocetku
   * pretpostavljamo da nisu i postavljamo je na 0.
   */
  int u = 0;
  
  p=1;
  /* Izraz 1 je konstantan, razlicit je od nule 
   * sto znaci da je to tacan izraz. Uslov petlje je 
   * uvek tacan!
   */
  printf("Unesite brojeve:");
  while (1) 
  {         
     scanf("%d", &x);
     /* Proveravamo da li je uneta nula. */
     if (x==0)  
        /* Naredba break prekida petlju. Izvrsavanje 
         * se nastavlja od prve naredbe nakon petlje.
         */
        break;  
     
     /* Ako je makar 1 broj razlicit od 0 unesen promenljiva
      * ce biti postavljena na 1.
      */
     u = 1; 
     /* Ako je unet negativan broj, taj broj se ne mnozi
      * sa ukupnim proizvodom p; zato se nastavlja dalje.
      */        
     if (x<0)     
       /* Naredba continue prekida trenutnu iteraciju petlje 
        * tako sto preskace sve naredbe koje nakon njega slede. 
        * Izvrsavanje se nastavlja od provere uslova petlje.
        */
        continue;  
     p=p*x;
  }
  
  if (u == 1)
	printf("Proizvod pozitivnih unetih brojeva je %d.\n",p);  
  else
	printf("Nisu uneseni brojevi.\n");
  
  return 0;   
}
