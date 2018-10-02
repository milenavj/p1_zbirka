#include <stdio.h>
.
int euklid(int x, int y)
{
  int r;
  /* Euklidov algoritam: http://elib.mi.sanu.ac.rs/files/journals/nm/245/nm581202.pdf */
  /* Kada promenljiva y postane 0, algoritam se zaustavlja. */
  while(y)   
  {          
    r=x%y;
    x=y;
    y=r;
  }
  
  /* U promenljivoj x se nalazi nzd. */
  return x; 
}

int main()
{
  int a,b;
  int nzd;
  
  printf("Unesite dva cela broja:");
  scanf("%d%d", &a,&b);
  
  nzd = euklid(a,b);
  
  printf("Najveci zajednicki delilac je %d\n", nzd);
  
  return 0;
}
