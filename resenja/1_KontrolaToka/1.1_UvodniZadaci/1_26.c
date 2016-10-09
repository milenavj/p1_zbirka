
#include<stdio.h>

int main()
{
  int a, b, c;
  float as;
  
  printf("Unesite tri cela broja:");
  scanf("%d%d%d",&a,&b,&c);
  
  /* pogresan nacin: as = (a+b+c)/3; 
     
     Ukoliko podelimo zbir a+b+c sa 3, to ce biti primena 
     operatora / na dva cela broja. Na ovaj nacin izracunacemo 
     koliko iznosi a+b+c celobrojno podeljeno sa 3. To znaci da 
     ce za unete vrednosti 11, 5 i 4 aritmeticka sredina biti 
     6.00. Zaista, zbir 11+5+4 iznosi 20, a kada 20 celobrojno 
     podelimo sa 3 dobijamo 6. Ovu celobrojnu vrednost dodeljujemo 
     realnoj promenljivoj as, cime se ona konvertuje u 6.000000 i 
     ispisujemo je zaokruzenu na dve decimale. Izlaz iz programa bi 
     bio pogresan: 6.00.
  
     Da bismo dobili kolicnik prilikom primene operatora / na dva 
     cela broja, a ne celobrojno deljenje, jedan argument mora da 
     bude realan broj. Jedan nacin je da umesto sa celobrojnom 
     trojkom (3) deljenje izvedemo sa realnom trojkom (3.0):   
  */
  as=(a+b+c)/3.0; 
  
  
  /*
     Trazeni kolicnik mozemo dobiti na razne nacine:
     as=1.0*(a+b+c)/3;
     ili
     as=(0.0+a+b+c)/3;
     ili
     as=((float)(a+b+c))/3;
     itd.
  */
  
  printf("Aritmeticka sredina unetih brojeva je %.2f\n", as);
  return 0;
}