#include <stdio.h>
#include <stdlib.h>

/* Funkcija racuna aritmeticku sredinu cifara datog celog broja */
float aritmeticka_sredina(int x) {

  /* Proveravamo slucaj broja 0 */
  if(x==0)
  	return 0;
  
  /* Brojaci sa svojim pocetnim vrednostima */
  int zbir_cifara = 0;
  int broj_cifara = 0;

  /* U slucaju da je broj negativan,
   * ostaci pri deljenju sa 10 bi takodje bili negativni
   * sto bi se moralo dodatno proveravati.
   * Stoga je zgodnije posmatrati samo apsolutnu vrednost broja.
   */
  x = abs(x);
  
  /* Izdvajamo cifru po cifru s kraja zapisa broja x.
   * Uslov while(x > 0) ekvivalentan je uslovu while(x)
   * Broj x je pozitivan (apsolutna vrednost), pa cifre izdvajati
   * sve dok ima cifara izdvajanje, tj. broj x nije deljenjem sa 10 postao 0
   */
  while(x) {
  
    zbir_cifara += x % 10;
    broj_cifara++;
    
    x /= 10;
  }
  
  /* Da nije izvrsena implicitna konverzija (kastovanje),
   * operator / obavljao bi celobrojno deljenje.
   * Zato je potrebno da bar jedan operand bude ceo broj,
   * sto je u ovom slucaju deljenik.
   * Operator kastovanja je unaran, pa ima veci prioritet od /
   */
  return (float) zbir_cifara / broj_cifara;
}

int main() {

  int x;
  
  printf("Unesite ceo broj: ");
  scanf("%d", &x);
  
  printf("Arimeticka sredina cifara broja %d je %.3f\n", x, aritmeticka_sredina(x));
  
  /* Iako smo u funkciji aritmeticka_sredina menjali broj x,
   * prosledjivanjem argumenata funkciji pravi se lokalna kopija promenljive x za tu funkciju,
   * tako da je ona menjana unutar funkcije aritmeticka_sredina,
   * a promenljiva x iz funkcije main() ostaje netaknuta.
   */
  
  return 0;
}
