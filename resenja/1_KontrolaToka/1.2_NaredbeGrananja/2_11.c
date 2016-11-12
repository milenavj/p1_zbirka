#include <stdio.h>
#include <ctype.h>

int main()
{
  /* Broj pojavljivanja slova a i A se inicijalizuje na 0 */
  int br_a = 0;

  /* Funkcija getchar ucitava jedan karakter. Njena povratna
     vrednost je ASCII kod ucitanog karaktera.

     Funkcija tolower za dati karakter vraca: - odgovarajuce malo
     slovo, ako je dati karakter veliko slovo - taj isti karakter,
     u suprotnom Ova funkcija je definisana u biblioteci ctype.h

     U slucaju da je uslov ispunjen, uvecavamo brojac br_a za jedan
     pomocu operatora inkrementacije ++ */
  if (tolower(getchar()) == 'a')
    br_a++;
  if (tolower(getchar()) == 'a')
    br_a++;
  if (tolower(getchar()) == 'a')
    br_a++;
  if (tolower(getchar()) == 'a')
    br_a++;
  if (tolower(getchar()) == 'a')
    br_a++;

  printf("%d\n", br_a);

  return 0;
}
