#include <stdio.h>

/*
   Argumenti funkcije uredi_pogresno, promenljive a i b,
   predstavljaju lokalne promenljive za ovu funkciju
   i prestaju da postoje po zavrsetku funkcije. Zbog toga
   se efekti razmene vrednosti promenljivih a i b u slucaju
   da je a>b vide u funkciji, ali se ne vide u glavnom programu.
*/
void uredi_pogresno(int a, int b)
{
  int t;
  
  if (a>b)
  {
     t = a;
     a = b;
     b = t;
  }
  printf("uredi_pogresno :: a=%d, b=%d\n", a, b);
  printf("uredi_pogresno :: &a=%p, &b=%p\n", &a, &b);
}

/*
   Argumenti funkcije uredi_tacno, promenljive pa i pb,
   takodje su lokalne promenljive za ovu funkciju i 
   prestaju da postoje kada se funkcija zavrsi.
   Njima prosledjujemo adrese promenljivih a i b koje zelimo
   da razmenimo u slucaju da je a>b.
   
   Promenljivoj a pristupamo preko pokazivacke promenljive
   pa sa *pa i slicno, promenljivoj pb pristupamo sa *pb.
   
   Vrednosti promenljivih *pa i *pb razmenjujemo kao
   i vrednosti bilo koje dve celobrojne promenljive.
   
*/
void uredi_tacno(int * pa, int * pb)
{
  int t;
  if (*pa>*pb)
  {
     t = *pa;
     *pa = *pb;
     *pb = t;
  }
  printf("uredi_tacno :: *pa=%d, *pb=%d\n ", *pa, *pb);  
  printf("uredi_tacno :: pa=%p, pb=%p\n ", pa, pb);  
   
}
int main()
{
  int a,b;
  
  printf("Unesi dve celobrojne promenljive:");
  scanf("%d%d",&a,&b);
  
  printf("main :: a=%d, b=%d\n", a,b);
  printf("main :: &a=%p, &b=%p\n", &a, &b);
  uredi_pogresno(a,b);  
  printf("main :: nakon uredi_pogresno, a=%d, b=%d\n", a, b);
  
  /*
     Funkcija uredi_tacno kao argument ima dve pokazivacke promenljive
     (int*,int*). Zbog toga joj je u pozivu funkcije neophodno proslediti 
     adrese promenljivih koje zelimo da uredimo rastuce, &a i &b.
  */
  
  uredi_tacno(&a, &b);
  printf("main :: nakon uredi_tacno, a=%d, b=%d\n", a, b);
  
  return 0;
}
