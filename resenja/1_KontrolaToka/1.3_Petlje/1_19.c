/*
   Napisati program koji za uneto n>0 ispisuje:
   a) brojeve od 1 do n*n po n u redu
   b) tablicu mnozenja od 1 do n*n
   c) tabelu koja za n=10 izgleda ovako:
  1   2   3   4   5   6   7   8   9  10
  2   3   4   5   6   7   8   9  10   1
  3   4   5   6   7   8   9  10   1   2
  4   5   6   7   8   9  10   1   2   3
  5   6   7   8   9  10   1   2   3   4
  6   7   8   9  10   1   2   3   4   5
  7   8   9  10   1   2   3   4   5   6
  8   9  10   1   2   3   4   5   6   7
  9  10   1   2   3   4   5   6   7   8
 10   1   2   3   4   5   6   7   8   9 
   d) kvadrat nxn zvezdica; za n=10:
**********
**********
**********
**********
**********
**********
**********
**********
**********
**********
   e) donjetrougaonu matricu zvezdica; za n=10:
*         
**        
***       
****      
*****     
******    
*******   
********  
********* 
**********
   f) gornjetrougaona matricu zvezdica; za n=10:
**********
 *********
  ********
   *******
    ******
     *****
      ****
       ***
        **
         *
   g) klin; za n=10:
* * * * * * * * * * 
 * * * * * * * * * 
  * * * * * * * * 
   * * * * * * * 
    * * * * * * 
     * * * * * 
      * * * * 
       * * * 
        * * 
         * 
*/
#include <stdio.h>
int main()
{
 int n;
 int i,j;
 printf("Unesi prirodan broj:");
 scanf("%d",&n);
 
 /*
   U svim varijantama zadatka potrebno je prikazati tabelu.
   Svaka tabela se sastoji iz vrsta i kolona. Tabela se stampa
   vrstu po vrstu, a unutar vrste stampa se jedno po jedno polje.
   
   Zadatak resavamo pomocu dvostrukih petlji. Brojacka promenljiva
   u spoljasnjoj petlji je i, a u unutrasnjoj j. U svakoj iteraciji
   petlje stampamo polje koje se nalazi u i-toj vrsti i j-toj
   koloni. Koja ce se vrednost nalaziti u tom polju, zavisi od
   varijante zadatka.

   Prelazak u novi red stampamo na kraju svake vrste.   
 */
 
 /* a */
 printf("brojevi od 1 do %d, po %d u redu \n",n*n,n);
 for (i=1;i<=n;i++) /* imamo n vrsta */
 {
     for (j=1; j<=n; j++) /* u svakoj vrsti imamo n elemenata*/
         printf("%3d ", (i-1)*n+j);  /* za i=1: 1,2,3,...,n */
                                      /* za i=2: 10,11,12,...,10+n */
                                      /* ... */
         
     printf("\n");  /* prethodna for petlja stampa polja jednog reda tabele 
                       na kraju svakog reda tabele neophodno je preci u novi red
                    */
                                
 }
 
 /* b */ 
 printf("tablica mnozenja od 1 do %d \n",n);
 for (i=1;i<=n;i++)
 {
     for (j=1; j<=n; j++)
         printf("%3d ", i*j);   /* u tablici mnozenja vrednost svakog polja je proizvod 
                                   vrste i kolone u kojoj se nalazi */         
     printf("\n");        
 }
 
 /* c */ 
 printf("brojevi od 1 do %d rotirani ulevo \n",n);
 for (i=1;i<=n;i++)
 {
     /* i oznacava broj vrste
        svaka vrsta je zarotirana za i-1 mesta ulevo;
        npr. za n=10, 3. red ce biti
        3 4 5 6 7 8 9 10 1 2
     */
     
     /*
        na pocetku svakog reda stampamo vrednosti od i do n
        npr. za n=10, u 3. redu prvo stampamo
        3 4 5 6 7 8 9 10
     */
     for (j=i; j<=n; j++)      
         printf("%3d ", j);
         
     /*
        nakon toga, dopunimo red vrednostima koje nedostaju
        npr. za n=10, u 3. redu to su
        1 2
     */    
     for (j=1; j<i; j++)
          printf("%3d ", j);
          
     printf("\n");        
 }
 
 /* d */
 printf("kvadrat \n");
 for (i=0; i<n; i++)
 {   
     /*
        kvadrat predstavlja tabelu sa n vrsta
        gde svaka vrsta sadrzi n polja, a svako
        polje je isto i predstavlja karakter *
     */
     for (j=0;j<n;j++)
         printf("*");
     printf("\n");        
 }
 
 /* e */
 printf("donjetrougaona matrica\n");
 for (i=0; i<n; i++)
 {
     /*
        umesto cele tabele kvadrata zvezdica, stampamo
        samo zvezdice koje se nalaze ispod glavne dijagonale,
        ukljucujuci i glavnu dijagonalu;

        za njihovu poziciju (i,j) u tabeli vazi da je 
        redni broj vrste i veci ili jednak rednom broju kolone j

     */
     for (j=0;j<n;j++)
       if (i>=j)
         printf("*");
     printf("\n");        
 }
 
 /* f */
 printf("gornjetrougaona matrica\n");
 for (i=0; i<n; i++)
 {
     /*
        umesto cele tabele kvadrata zvezdica, stampamo
        samo zvezdice koje se nalaze iznad glavne dijagonale,
        ukljucujuci i glavnu dijagonalu;

        za njihovu poziciju (i,j) u tabeli vazi da je 
        redni broj vrste i manji ili jednak rednom broju kolone j

        S obzirom da ispis zvezdica ne pocinje od pocetka reda,
        nephodno je da u slucaju da ne stampamo zvezdicu 
        odstampamo razmak kako bismo pravilno pozicionirali
        pocetak stampanja reda

     */
     for (j=0;j<n;j++)
       if (i<=j)
         printf("*");
       else
         printf(" ");
     printf("\n");        
 }
 
 /* g */
 printf("klin \n");
 for (i=0; i<n; i++)
 {
    /*
        kod klina, i-ti red pocinje sa i razmaka
        nakon cega se n-i puta stampaju zajedno zvezdica
        i razmak ("* ")
    */
    
    for (j=0; j<i;j++)
        printf(" ");
    for (j=0; j<n-i; j++)
        printf("* ");    
        
    printf("\n");
 }
  return 0;
}