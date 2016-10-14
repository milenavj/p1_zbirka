#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x;
  char c1;   
  char c10; 
  char c100; 
  char c1000;
  
  printf("Unesi jedan cetvorocifreni broj:");
  scanf("%d", &x);
  
  /* 
     Uzimamo apsolutnu vrednost unetog broja kako u slucaju
     da je negativan ne bismo za cifre dobili negativne brojeve. 
     Funkcija abs nalazi se u zaglavlju stdlib.h 
  */
  x=abs(x); 
  
  if (x<1000 || x>9999) 
  {
     printf("Uneti broj nije cetvorocifren\n");
     return -1;
  }
  
  /* Izdvajamo cifre broja. */
  c1 = x%10;
  c10 = (x/10)%10;  
  c100 = (x/100)%10;  
  c1000 = (x/1000)%10;
     
  if (c1000<=c100 && c100<=c10 && c10<=c1)
     printf("Cifre su uredjene neopadajuce \n");
  else if (c1000>=c100 && c100>=c10 && c10>=c1)
     printf("Cifre su uredjene nerastuce \n");
  else
     printf("Cifre nisu uredjene\n");
     
}


