#include <stdio.h>
#include <math.h>

/* Funkcija vraca 1 ako je broj prost, a 0 u suprotnom.  */
int prost (int x) 
{
  int i;

  /* Brojevi 2 i 3 su prosti. */
  if (x==2 || x==3) 
    return 1;       
      
  /* Parni brojevi nisu prosti. */
  if (x%2==0)       
    return 0;
  
  /* Dovoljno je proveravati da li delioc datog broja postoji u intervalu od 3 do korena iz tog broja. */
  for (i=3; i<=sqrt(x);i+=2) 
    /* Ako neki broj i deli broj x, onda on nije prost i izlazi se iz funkcije. */
    if (x%i==0) 
      return 0; 

  /* Ako ni jedan od prethodnih uslova nije bio ispunjen, to znaci da ni jedan broj ne deli x, pa je on prost. */      
  return 1;
}

int main()
{
  int n;
  scanf("%d",&n);
  int i,j;
  
  /* Tekuci broj za koji se ispituje da li je prost. */
  i=1; 
  /* Brojac prostih brojeva. */
  j=0; 
  while(j<n)
  {
     /* Poziva se funkcija da se odredi da li je tekuci broj i prost. */
     if (prost(i))         
     {
        /* Ako jeste, stampa se i uvecava se brojac prostih brojeva. */
        printf("%d\n", i); 
        j++;               
     }
     /* U narednoj iteraciji ispituje se sledeci broj. */
     i++; 
  }
  
  return 0;
}
