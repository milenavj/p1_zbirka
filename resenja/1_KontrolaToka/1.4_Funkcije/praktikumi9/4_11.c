#include <stdio.h>
#include <stdlib.h>

/* Funkcija racuna aritmeticku sredinu cifara datog celog broja. */
float aritmeticka_sredina(int x) {

  /* Aritmeticka sredina broja 0 je 0. */
  if(x==0)
  	return 0;
  
  /* Brojaci sa svojim pocetnim vrednostima. */
  int zbir_cifara = 0;
  int broj_cifara = 0;

  /* U slucaju da je broj negativan, ostaci pri deljenju sa 10 bi takodje bili negativni. Stoga je zgodnije posmatrati samo apsolutnu vrednost broja. */
  x = abs(x);
  
  /* Izdvaja se cifra po cifra s kraja zapisa broja x. Uslov while(x > 0) ekvivalentan je uslovu while(x). Broj x se deli sa 10 i cifre se izdvajaju sve dok x ne postane 0. */
  while(x) {
  
    zbir_cifara += x % 10;
    broj_cifara++;
    
    x /= 10;
  }
  
  /* Da bi rezultat bio realan broj potrebno je izvrsiti kastovanje barem jednog od parametara jer su oba parametra celi brojevi. */
  return (float) zbir_cifara / broj_cifara;
}

int main() {

  int x;
  
  printf("Unesite ceo broj: ");
  scanf("%d", &x);
  
  printf("Arimeticka sredina cifara broja %d je %.3f\n", x, aritmeticka_sredina(x));
  
  /* Iako u funkciji aritmeticka_sredina broj x se menja, prosledjivanjem argumenata funkciji pravi se lokalna kopija promenljive x za tu funkciju, tako da iako je ona menjana unutar funkcije aritmeticka_sredina, promenljiva x iz funkcije main() ostaje nepromenjena. */
  
  return 0;
}
