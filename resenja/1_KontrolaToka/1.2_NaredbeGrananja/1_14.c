/*
Sa standardnog ulaza unose se jedan karakter i 8 realnih brojeva koji predstavljaju 
koordinate cetiri tacke: A(x1, y1), B(x2, y2), C(x3, y3), D(x4, y4). Na osnovu unetetog karaktera 
ispisuje se odgovarajuca poruka na standardni izlaz:
k - proverava da li su date tacke temena pravougaonika cije su stranice paralelne koordinatnim osama i 
    u slucaju da jesu, ispisuje obim datog pravougaonika; mozemo podrazumevati da ce korisnik koordinate tacaka 
    unosi redom A,B,C,D, pri cemu ABCD opisuje pravougaonik cije su stranice AB,BC,CD i DA, a dijagonale AC i BD
    na primer, tacke (1,1),(2,1),(2,2),(1,2) cine pravougaonik cije su stranice paralelne koordinatnim osama i ciji je obim 4
    a tacke (1,1),(2,2),(3,3),(4,4) ne cine pravougaonik
h - proverava da li su unete tacke kolinearne i ukoliko jesu, ispisati jednacinu prave kojoj pripadaju
    na primer, tacke (1,2),(2,3),(3,4),(4,5) su kolinearne i pripadaju pravoj y=x+1
    tacke (1,1),(1,2),(1,3),(1,4) su kolinearne i pripadaju pravoj x=1
    a tacke (1,1),(2,1),(2,2),(1,2) nisu kolinearne
j - Kramerovim pravilom proverava da li je dati sistem jednacina
x1 * p + x2 * q = x4 - x3
y1 * p + y2 * q = y4 - y3
    odredjen, neodredjen ili nema resenja, i u slucaju da je odredjen ispisati resenja. 
    na primer, za unete koordinate (1,1),(1,1),(1,0),(2,2) sistem nema resenja
               za unete koordinate (1,1),(1,1),(1,1),(1,1) sistem je neodredjen ili nema resenja
               za unete koordinate (6,1),(8,3),(10,-4),(9,1) sistem ima jedinstveno resenje 4.30, 3.10
               
*/

#include<stdio.h>
#include<math.h>
int main()
{
   char c;
   float x1,y1,x2,y2,x3,y3,x4,y4;
   float kab,kbc,kad;
   float dab,dad;
   float delta, deltap, deltaq;
   float O;
   float k,n;
   
   printf("Unesi jedan karakter:");
   scanf("%c",&c);
   
   printf("Unesi realne koordinate 4 tacke:");
   scanf("%f%f%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
   
   switch (c)   
   {
       case 'k':
          if (y1==y2 && y3==y4 && x1==x4 && x2==x3)
          {
             dab = sqrt(pow(x1-x2,2)+pow(y1-y2,2)); // funkcija pow(x,y) racuna vrednost stepene funkcije x^y
             dad = sqrt(pow(x1-x4,2)+pow(y1-y4,2)); // x i y su realne vrednosti  
             O = 2*dab + 2*dad;
             printf("Obim pravougaonika je %f\n",O);
          }
          else
             printf("Tacke ne cine pravougaonik sa stranicama koje su paralelne koordinatnim osama\n");          
          break;             
       case 'h':
          if ((x1-x2)!=0) // ukoliko se tacke A(x1,y1) i B(x2,y2) ne nalaze na pravoj koja je paralelna x osi
          {
             k = (y1-y2)/(x1-x2); //izracunamo k,n za pravu odredjenu tackama A(x1,y1) i B(x2,y2)
             n = y1-k*x1;
          
             if (y3==x3*k+n && y4==x4*k+n)   // proverimo da li tacke C(x3,y3) i D(x4,y4) nalaze na toj pravoj
                printf("Tacke su kolinearne, pripadaju pravoj y=%f*x+%f\n",k,n);
             else
                printf("Tacke nisu kolinearne\n");
          }
          else // ukoliko se A i B nalaze na pravoj koja je paralelna x osi
             if (x3==x1 && x4==x1) // proverimo da li tacke C(x3,y3) i D(x4,y4) nalaze na toj pravoj
                printf ("Tacke su kolinearne, pripadaju pravoj x=%f\n",x1);
             else
                printf("Tacke nisu kolinearne\n");
          break;
       case 'j':          
          delta = x1*y2-x2*y1;
          deltap = x2*(y4-y3)-y2*(x4-x3);         
          deltaq = x1*(y4-y3)-y1*(x4-x3);
          if (delta!=0)
              printf("Sistem ima jedinstveno resenje %.2f, %.2f\n",deltap/delta, deltaq/delta);
          else if (deltap==0 && deltaq==0)          
              printf("Sistem je neodredjen ili nema resenja.\n");
          else
              printf("Sistem nema resenja\n");
          break;
       default:
          printf("Nekorektan unos\n");
   }
   return 0;
}