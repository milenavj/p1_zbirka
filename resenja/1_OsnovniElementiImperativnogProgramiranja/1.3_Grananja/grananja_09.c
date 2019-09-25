#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  unsigned int broj_cifara = 0;
  unsigned int proizvod_cifara = 1;
  int c1, c2, c3;

  /* I nacin ucitavanja ulaza: koriscenjem funkcije getchar()
     Funkcija getchar cita jedan karakter sa ulaza i vraca njegov
     ASCII kod. Napomena: razmaci su takodje karakteri i nece
     automatski biti preskoceni. Iz tog razloga se getchar poziva 5 
     puta u ovom primeru. Posto je poznato da su drugi i cetvrti
     karakter blanko znaci, nema potrebe da se cuva povratna 
     vrednost tih poziva. */
  printf("Unesite karaktere: ");
  c1 = getchar();
  getchar();
  c2 = getchar();
  getchar();
  c3 = getchar();

  /* II nacin ucitavanja ulaza: koriscenjem funkcije scanf()
     Blanko znaci se navode kao deo ocekivanog formata ulaza. 
     char c1, c2, c3; 
     scanf("%c %c %c", &c1, &c2, &c3); */

  /* Pogresan nacin ucitavanja ulaza: 
     scanf("%c%c%c", &c1, &c2, &c3); 
     U ovom slucaju ce u c1 biti upisan prvi karakter, u c2
     blanko i u c3 drugi karakter. */

  /* Karakteri koji predstavljaju cifre su u ASCII tablici takodje
     smesteni sekvencijalno. Na primer, '0' ima ASCII kod 48, '1'
     49, ..., '9' ima ASCII kod 57.

     Odavde, ako se proverava da li je karakter cifra, dovoljno je
     proveriti da li se njegov ASCII kod nalazi izmedju '0' i '9'.

     Dodatno, ako je potrebno izracunati dekadnu vrednost karaktera 
     koji je cifra, dovoljno je od ASCII koda tog karaktera,
     oduzeti ASCII kod karaktera '0'. Na primer, '4'-'0' = 52 - 48
     = 4. */

  /* Racunanje proizvoda onih karaktera koji su cifre. */
  if (c1 >= '0' && c1 <= '9') {
    proizvod_cifara *= (c1 - '0');
    broj_cifara++;
  }

  if (c2 >= '0' && c2 <= '9') {
    proizvod_cifara *= (c2 - '0');
    broj_cifara++;
  }

  if (c3 >= '0' && c3 <= '9') {
    proizvod_cifara *= (c3 - '0');
    broj_cifara++;
  }

  /* Ispis rezultata. */
  if (broj_cifara == 0)
    printf("Medju unetim karakterima nema cifara.\n");
  else
    printf("Proizvod cifara: %u\n", proizvod_cifara);

  return 0;
}
