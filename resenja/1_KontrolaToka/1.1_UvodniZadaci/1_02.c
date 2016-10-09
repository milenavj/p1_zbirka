#include <stdio.h>

int main()
{
  /* 
     Svaka promenljiva u programu mora biti deklarisana na 
     pocetku main funkcije. Deklaracija se sastoji iz naziva 
     promenljive (u ovom slucaju n) ispred kog se navodi tip 
     promenljive (u ovom slucaju celobrojni tip, int). 
  */
  
  int n; 
  
  /* 
     Vrednost promenljive se ucitava pomocu funkcije scanf koja 
     je, kao i funkcija printf, sastavni deo standardne biblioteke. 
     Argumenti funkcije scanf koji se navode u zagradama 
     ( i ) i razdvajaju zarezima, oznacavaju sledece:
     "%d" - format za tip podatka koji ce biti ucitan 
            (%d za int, svaki tip ima svoj format) 
      &n  - adresa promenljive x (o adresama ce biti vise 
            reci u narednim zadacima).
      
     Ucitavanje se vrsi sa standardnog ulaza (obicno tastatura).
   */
  printf("Unesite ceo broj: ");
  scanf("%d", &n);                                            
  
  /* 
     Funkcija printf ispisuje tekst "Uneti broj: ", a nakon toga, 
     umesto formata %d, ispisuje vrednost promenljive n. 
  */
  printf("Uneti broj: %d\n", n);
  /* Umesto formata %d, ispisuje vrednost izraza n*n. */
  printf("Kvadrat: %d\n", n*n); 
  /* Umesto formata %d, ispisuje vrednost izraza n*n*n. */                                   
  printf("Kub: %d\n", n*n*n);                                         
  
return 0;
}
