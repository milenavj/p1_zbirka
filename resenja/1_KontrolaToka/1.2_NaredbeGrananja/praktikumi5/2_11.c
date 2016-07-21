/* Napisati program koji za dva data intervala realne prave (a1, b1) i (a2, b2)
odreduje:
a) duzinu zajednickog dela ta dva intervala
b) najveci interval sadrzan u datim intervalima (presek), a ako on ne postoji
dati odgovaraju ́u poruku.
c) duzinu realne prave koju pokrivaju ta dva intervala
d) najmanji interval koji sadrzi date intervale
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

  int a1, b1, a2, b2;
  int a3, b3;
  int duzina_zajednickog_dela, zajednicka_duzina;
  int x, y; // krajevi najmanjeg intervala koji pokriva oba intervala
  
  printf("Unesite redom a1, b1, a2 i b2: ");
  scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
  
  /* Presek intervala [a1, b1] i [a2, b2] 
   * racuna se kao: 
   * [a3, b3] = [max{a1,a2}, min{b1, b2}] */
  
  a3 = a1 > a2 ? a1 : a2;
  b3 = b1 < b2 ? b1 : b2;
  
  /* U ovom slucaju, presek je prazan */
  if(a3 >= b3) {
  
    duzina_zajednickog_dela = 0;
    zajednicka_duzina = abs(b1-a1) + abs(b2-a2);   
  }
  else {
  
    duzina_zajednickog_dela = abs(b3-a3);
    zajednicka_duzina = abs(b2-a1);
  }
  
  /* Racunanje "pokrivaca" */
  x = a1 < a2 ? a1 : a2;
  y = b1 > b2 ? b1 : b2;
  
  printf("Duzina zajednickog dela: %d\n", duzina_zajednickog_dela);
  
  if(a3 >= b3)
    printf("Presek intervala: prazan\n");
  else
    printf("Presek intervala: [%d, %d]\n", a3, b3);
  
  printf("Zajednicka duzina intervala: %d\n", zajednicka_duzina);
  printf("Najmanji interval: [%d, %d]\n", x, y);
  
  return 0;
}