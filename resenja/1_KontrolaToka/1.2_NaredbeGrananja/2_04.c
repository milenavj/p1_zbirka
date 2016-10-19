#include <stdio.h>

int main()
{
   int x;
   float rx;
   
   printf("Unesite jedan ceo broj:");
   scanf("%d",&x);
   
   /*
      Obratiti paznju:
      x==0 - relacija jednakosti 
             (da li je promenljiva x jednaka nuli)
      x=0  - naredba dodele 
             (promenljiva x dobija vrednost nula)
   */

   /*
      Proveravamo da li je uneti broj jednak nuli. Ako
      jeste, prekidamo sa daljim izvrsavanjem programa
      navodjenjem naredbe return. Argument -1 u naredbi
      return oznacava da program nije uspesno zavrsen            
   */
   if (x==0)
   {
      printf("Nedozvoljeno deljenje nulom\n");
      return -1;
   }
      
   /*
      Primenom operatora / na argumente 1 i x dobijamo
      rezultat celobrojnog deljenja ovih argumenata. Da
      bismo dobili kolicnik, koji je realna vrednost, 
      neophodno je da jedan od argumenata zapisemo kao
      realnu vrednost, npr celobrojnu vrednost 1 zapisemo kao
      realnu vrednost 1.0. Ovakav postupak se naziva 
      implicitna konverzija.         
   */
   
   rx = 1.0/x;
   printf("Reciprocna vrednost unetog broja:%.4f\n",rx);
   
   return 0;
}
