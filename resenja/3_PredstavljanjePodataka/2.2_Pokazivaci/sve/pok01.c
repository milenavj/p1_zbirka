#include <stdio.h>
#include <stdlib.h>

/* Argumenti funkcije uredi_pogresno, promenljive a i b,
   predstavljaju lokalne promenljive za ovu funkciju i prestaju da
   postoje po zavrsetku funkcije. Zbog toga se efekti razmene
   vrednosti promenljivih a i b u slucaju da je a>b ne vide u
   glavnom programu. 
   void uredi_pogresno(int a, int b) { 
     int pom;
     if (a > b) { 
       pom = a; 
       a = b; 
       b = pom; 
     } 
   } */

/* Argumenti funkcije uredi, promenljive pa i pb, takodje su
   lokalne promenljive za ovu funkciju i prestaju da postoje kada
   se funkcija zavrsi. Razlika je u tome sto su one adrese 
   promenljivih a i b koje zelimo da razmenimo u slucaju da je a>b.

   Promenljivoj a se pristupa preko pokazivacke promenljive pa sa
   *pa i slicno, promenljivoj b sa *pb.

   Vrednosti promenljivih *pa i *pb se razmenjuju kao i vrednosti
   bilo koje dve celobrojne promenljive. */
void uredi(int *pa, int *pb) {
  int pom;
  if (*pa > *pb) {
    pom = *pa;
    *pa = *pb;
    *pb = pom;
  }
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a, b;

  /* Ucitavanje vrednosti dva cela broja. */
  printf("Unesite dva broja:");
  scanf("%d%d", &a, &b);

  /* Neispravan nacin: 
     uredi_pogresno(a, b); 
     printf("Uredjene promenljive: %d, %d\n", a, b); */

  /* Funkcija uredi kao argumente prima dve pokazivacke promenljive 
     (int*,int*). Zbog toga je u pozivu funkcije neophodno
     proslediti adrese promenljivih koje zelimo da uredimo rastuce:
     &a i &b. */
  uredi(&a, &b);
  printf("Uredjene promenljive: %d, %d\n", a, b);

  exit(EXIT_SUCCESS);
}
