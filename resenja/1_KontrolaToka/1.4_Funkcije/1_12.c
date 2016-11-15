#include<stdio.h>
#include<math.h>

/* Funkcija racuna vrednost e^x kao parcijalnu sumu reda
 suma(x^n/n!), gde indeks n ide od  
 od 0 do beskonacno, pri cemu se sumiranje vrsi dok
 je razlika sabiraka u redu po apsolutnoj vrednosti
 manja od eps. */
double e_na_x(double x, double eps)
{
  double s=1;
  double clan=1;
  int n=1;

  /* 
     parcijalnu sumu formiramo tako sto u svakoj iteraciji petlje 
     promenljivoj s dodamo jedan sabirak sume oblika (x^n)/n! koji
     cuvamo u promenljivoj clan
     
     svaki sabirak mozemo da dobijemo na osnovu prethodnog tako sto
     ga pomnozimo sa x i podelimo sa n, koje predstavlja redni broj
     sabirka u sumi
     
     prvi sabirak (kome odgovara n=0) iznosi 1; zbog toga promenljive
     s i clan inicijalizujemo na vrednost 1
     
     sumiranje se sprovodi dogod je sabirak po apsolutnoj vrednosti
     veci od trazene tacnosti eps     
  */
  
  do
  {
     clan = (clan*x)/n;   
     s += clan;           
     n++;     
  } while(fabs(clan)>eps);

  return s;
}

int main()
{
  double x,eps;
  printf("x=");
  scanf("%lf", &x);
  printf("eps=");
  scanf("%lf", &eps);

  printf("e^%f=%f\n", x, e_na_x(x,eps));
  return 0;
}
