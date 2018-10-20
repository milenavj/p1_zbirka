#include <stdio.h>

int main()
{
  /* Deklaracija i inicijalizacija potrebnih promenljivih. */
  int n, i;
  int broj_a = 0, broj_e = 0, broj_i = 0, broj_o = 0, broj_u = 0;
  char c;

  /* Ucitava se broj karaktera i vrsi se provera ispravnosti 
     ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Kako je korisnik nakon unosa broja n uneo oznaku za novi red,
     potrebno je preskociti taj novi red jer bi u suprotnom on bio
     ucitan kao prvi od n karaktera (oznaka za novi red je
     regularan karakter kao sto je to 'a' ili ' ').*/
  getchar();
  
  /* Ucitavaju se karakteri i broje se samoglasnici. */
  for (i = 0; i < n; i++) {
    scanf("%c", &c);

    switch (c) {
    case 'a':
    case 'A':
      broj_a++;
      break;
    case 'e':
    case 'E':
      broj_e++;
      break;
    case 'i':
    case 'I':
      broj_i++;
      break;
    case 'o':
    case 'O':
      broj_o++;
      break;
    case 'u':
    case 'U':
      broj_u++;
      break;
    }
  }

  /* Ispis rezultata. */
  printf("Samoglasnik a: %d\n", broj_a);
  printf("Samoglasnik e: %d\n", broj_e);
  printf("Samoglasnik i: %d\n", broj_i);
  printf("Samoglasnik o: %d\n", broj_o);
  printf("Samoglasnik u: %d\n", broj_u);

  return 0;
}
