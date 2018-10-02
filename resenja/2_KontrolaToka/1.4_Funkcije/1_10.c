#include <stdio.h>
#include <stdlib.h>

int sve_parne_cifre(int x) /* funkcija vraca 1 ako su sve cifre broja parne i 0 u suprotnom*/
{
  char d;
  /* Za slucaj da je broj negativan posmatra se apsolutna vrednost. */
  x=abs(x);       

  while (x>0)
  {
    /* Izdvaja se poslednja cifra broja. */
    d=x%10;       
    
    /* Ako je izdvojena cifra neparna oznacava da nisu sve cifre broja parne i funkcija vraca 0. */
    if (d%2==1)   
      return 0;   
      
    /* Poslednja cifra broja se ukklanja celobrojnim deljenjem sa 10. */
    x/=10;        
  }
  
  return 1;     
}

/* Funkcija vraca 1 ako su sve cifre broja jednake i 0 u suprotnom. */
int sve_cifre_jednake(int x) 
{
  char d;
  char prva_cifra;
  /* Posmatra se apsolutna vrednost broja. */
  x=abs(x);
  /* Izdvaja se prva cifra broja. */
  prva_cifra = x%10; 
  /* Uklanja se poslednja cifra broja tako sto se broj podeli sa 10. */
  x/=10;             
               
  while(x)
  {
	  /* Izdvaja se poslednja cifra u broju. */  
     d = x%10;   
     
     /* Ukoliko izdvojena cifra nije jednaka prvoj izdvojenoj cifri onda broj nema sve jednake cifre. */
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
