/*
Napisati funkciju koja ispituje da li je dati ceo broj prost. Funkcija treba
da vrati 1 ako je broj prost i 0 u suprotnom. Napisati potom glavni program
koji za uneti ceo broj n ispisuje prvih n prostih brojeva.
*/

#include <stdio.h>
#include <math.h>

int prost (int x) /* 1-broj je prost, 0-broj nije prost */
{
  int i;

  if (x==2 || x==3) /* brojevi 2 i 3 su prosti */
    return 1;       
      
  if (x%2==0)       /* parni brojevi nisu prosti */
    return 0;
  
  for (i=3; i<=sqrt(x);i+=2) /* trazimo delioca */
    if (x%i==0) /* ako je pronadjen, to znaci da broj nije prost */
      return 0; /* zavrsavamo funkciju */

  /* ukoliko izvrsavanje funkcije dodje do poslednje naredbe return, 
     to znaci da broj nije ispunio nijedan od prethodnih uslova 
     (nije ni 2, ni 3, ni paran, niti ima ijednog delioca), odakle
     sledi da je prost i zbog toga vracamo 1
  */      
  return 1;
}

int main()
{
  int n;
  scanf("%d",&n);
  int i,j;
  
  i=1; /* kandidat za prost broj */
  j=0; /* brojac prostih brojeva */
  while(j<n)
  {
     if (prost(i))         /* ako je broj prost */
     {
        printf("%d\n", i); /* stampamo ga i */
        j++;               /* uvecavamo brojac prostih brojeva */
     }
     i++; /* bilo da je i prost ili ne, uvecavamo ga za 1 i nastavljamo sa sledecom iteracijom */
  }
  
  return 0;
}