/*
Napisati program koji od korisnika zahteva da unese
cetvorocifreni broj. Program za taj broj proverava
da li su cifre uredjene rastuce, opadajuce ili nisu
uredjene i stampa odgovarajucu poruku na standardni
izlaz. Voditi racuna o nekorektnim unosima. Na primer,
pokretanje programa moze da izgleda ovako:

Unesi jedan cetvorocifreni broj: -1357
Cifre su mu uredjene neopadajuce.

ili ovako

Unesi jedan cetvorocifreni broj: 9952
Cifre su mu uredjene nerastuce.

ili ovako

Unesi jedan cetvorocifreni broj: 9572
Cifre su mu nisu uredjene.

Unesi jedan cetvorocifreni broj: 123
Uneti broj nije cetvorocifren.

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x;
  char c1;    /* cifre su brojevi {0,1,2,3,4,5,6,7,8,9} */
  char c10; 
  char c100; 
  char c1000;
  
  printf("Unesi jedan cetvorocifreni broj:");
  scanf("%d", &x);
  
  x=abs(x); /* u slucaju da je broj negativan, uzimamo njegovu apsolutnu vrednost 
                  kako ne bismo za cifre dobili negativne brojeve */
            /* funkcija abs nalazi se u zaglavlju stdlib.h */
  
  if (x<1000 || x>9999) 
     printf("Uneti broj nije cetvorocifren\n");
  else
  {
     c1 = x%10;
     c10 = (x/10)%10;  
     c100 = (x/100)%10;  
     c1000 = (x/1000)%10;
     
     printf("Cifre broja: %d,%d,%d,%d\n",c1000,c100,c10,c1);
     
     if (c1000<=c100 && c100<=c10 && c10<=c1)
        printf("Cifre su uredjene neopadajuce \n");
     else if (c1000>=c100 && c100>=c10 && c10>=c1)
        printf("Cifre su uredjene nerastuce \n");
     else
        printf("Cifre nisu uredjene\n");
  }   
  return 0;
}


