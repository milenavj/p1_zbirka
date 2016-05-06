/*

a) Napisati funkciju sve_parne_cifre koja ispituje da li se dati ceo broj sastoji iskljucivo iz parnih cifara. Funkcija treba
da vrati 1 ako su sve cifre broja parne i 0 u suprotnom. 

b) Napisati funkciju sve_cifre_jednake koja ispituje da li su sve cifre datog celog broja jednake. Funkcija treba
da vrati 1 ako su sve cifre broja jednake i 0 u suprotnom. 

c) Napisati potom glavni program koji na uneti ceo broj primenjuje napisane funkcije i ispisuje odgovarajuce poruke. 

Na primer, za uneti broj 222, program treba da ispise:
Sve cifre broja su parne.
Sve cifre broja su jednake.

A za uneti broj -284:
Sve cifre broja su parne.
Broj sadrzi razlicite cifre

*/
#include <stdio.h>
#include <stdlib.h>

int sve_parne_cifre(int x) /* funkcija vraca 1 ako su sve cifre broja parne i 0 u suprotnom*/
{
  char d;
  x=abs(x);       /* uzimamo apsolutnu vrednost broja za slucaj da je broj negativan */
  while (x>0)
  {
    d=x%10;       /* izdvajamo cifru broja */
    
    if (d%2==1)   /* u slucaju da je neparna, to znaci da nisu sve cifre broja parne */
      return 0;   /* vracamo 0 */
      
    x/=10;        /* "uklanjamo" poslednju cifru broja celobrojnim deljenjem sa  10 */
  }
  
  return 1;      /* ukoliko se while petlja zavrsila, to znaci da uslov d%2==1 nije 
                    nijednom bio ispunjen i da su sve cifre broja parne; zbog toga
                    vracamo 1
                 */
  
}

int sve_cifre_jednake(int x) /* funkcija vraca 1 ako su sve cifre broja jednake i 0 u suprotnom*/
{
  char d;
  char prva_cifra;
  x=abs(x);
  prva_cifra = x%10; /* izdvajamo prvu cifru broja */
  x/=10;             /* broj delimo sa 10 jer smo prvu cifru vec izdvojili */
               
  while(x)
  {  
     d = x%10;   
     
     if (d!=prva_cifra)
        return 0;
    
     x/=10;
  }
  
  return 1;
}
main()
{
  int x;
  int d;
  
  printf("unesi ceo broj:");
  scanf("%d", &x);
  
  if (sve_parne_cifre(x))
    printf("Sve cifre broja su parne\n");
  else
    printf("Broj sadrzi bar jednu neparnu cifru\n");
    
  if (sve_cifre_jednake(x))
    printf("Sve cifre broja su jednake\n");
  else
    printf("Broj sadrzi razlicite cifre \n");

}