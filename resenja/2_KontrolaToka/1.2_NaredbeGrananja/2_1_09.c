#include <stdio.h>
#include <ctype.h>

int main()
{
  /* I nacin ucitavanja ulaza: koriscenjem funkcije getchar()
     Funkcija getchar cita jedan karakter sa ulaza i vraca njegov
     ASCII kod. Napomena: beline su takodje karakteri i nece
     automatski biti preskocene. Iz tog razloga se getchar poziva 5 
     puta u ovom primeru. Posto je poznato da su drugi i cetvrti
     karakter beline, nema potrebe da se cuva povratna vrednost tih 
     poziva. */
  int c1, c2, c3;
  printf("Unesite karaktere: ");
  c1 = getchar();
  getchar();
  c2 = getchar();
  getchar();
  c3 = getchar();

  /* II nacin ucitavanja ulaza: koriscenjem funkcije scanf()
     Beline se navode kao deo ocekivanog formata ulaza. 
     char c1, c2, c3; 
     scanf("%c %c %c", &c1, &c2, &c3); */

  /* Pogresan nacin ucitavanja ulaza: 
     scanf("%c%c%c", &c1, &c2, &c3); 
     U ovom slucaju ce u c1 biti upisan prvi karakter, u c2
     belina i u c3 drugi karakter. */

  /* Karakteri koji predstavljaju cifre su u ASCII tablici takodje
     smesteni sekvencijalno. Na primer, '0' ima ASCII kod 48, '1'
     49, ..., '9' ima ASCII kod 57.

     Odavde, ako se proverava da li je karakter cifra, dovoljno je
     proveriti da li se njegov ASCII kod nalazi izmedju '0' i '9'.

     Dodatno, ako je potrebno izracunati dekadnu vrednost karaktera 
     koji je cifra, dovoljno je od ASCII koda tog karaktera,
     oduzeti ASCII kod karaktera '0'. Na primer, '4'-'0' = 52 - 48
     = 4. */
  if (c1 < '0' || c1 > '9') {
    printf("Greska: prvi karakter nije cifra.");
    return -1;
  }

  /* Racuna se zbir ASCII kodova. */
  int zbir = c1 + c2 + c3;

  /* Racuna se vrednost prve cifre. */
  int vrednost_prve_cifre = c1 - '0';

  /* Ispis rezultata. */
  printf("Rezultat: %d\n", vrednost_prve_cifre * zbir);

  return 0;
}
