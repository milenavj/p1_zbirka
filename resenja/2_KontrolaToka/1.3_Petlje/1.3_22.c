#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, i, x, rezultat;
  int x_desetica, najveca_desetica;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n < 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Ako nema unetih brojeva, ispisuje se odgovarajuca poruka. */
  if (n == 0) {
    printf("Nisu uneti brojevi.\n");
    return 0;
  }

  printf("Unesite brojeve: ");

  /* Prvi broj se ucitava pre petlje, zbog ispravne
     inicijalizacije. */
  scanf("%d", &x);
  /* Promenljiva najveca_desetica se postavlja na cifru desetica
     ucitanog broja. Napomena: pri racunanju se uzima apsolutna
     vrednost broja jer je npr. (-123/10)= -12 i -12 % 10 = -2, a
     cifra desetica treba da bude 2. */
  najveca_desetica = (abs(x) / 10) % 10;
  /* Kako je na kraju potrebno ispisati broj cija je cifra desetica
     najveca, trenutna vrednost rezultata se postavlja na vrednost
     ucitanog broja. */
  rezultat = x;

  /* Ucitavanje preostalih n-1 brojeva i u slucaju nailaska na
     broj cija je cifra desetica veca od trenutno najvece, vrsi se
     azuriranje najvece desetice i rezultata. */
  for (i = 1; i < n; i++) {
    scanf("%d", &x);

    x_desetica = (abs(x) / 10) % 10;

    if (x_desetica > najveca_desetica) {
      najveca_desetica = x_desetica;
      rezultat = x;
    }
  }

  /* II nacin: Inicijalizacija najvece desetice na neku vrednost
     koja je sigurno manja od svih vrednosti koje cifra desetica
     moze da uzme (dakle, bilo sta sto je manje od 0 jer cifra
     desetica moze imati vrednosti izmedju 0 i 9). Zatim se u
     petlji izracunava rezultat, analogno prvom nacinu.

     najveca_desetica = -1; 
     for(i=0; i<n; i++) { 
       scanf("%d", &x);
       x_desetica = (abs(x) / 10) % 10;
       if (x_desetica > najveca_desetica) { 
         najveca_desetica = x_desetica; 
         rezultat = x; 
       }  
     } */

  /* Ispis rezultata. */
  printf("Broj sa najvecom cifrom desetica: %d\n", rezultat);

  return 0;
}
