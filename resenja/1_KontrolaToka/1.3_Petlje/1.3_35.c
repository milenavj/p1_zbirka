#include <stdio.h>

int main()
{
  char c;

  /* Inicijalizacija brojaca na 0. */
  int br_v = 0;
  int br_m = 0;
  int br_c = 0;
  int br_b = 0;
  int br_k = 0;
  int suma = 0;

  /* Petlja se zavrsava kada korisnik ne unese karakter, vec zada
     konstantu EOF . Ova konstanta se zadaje kombinacijom tastera
     CTRL+D. U tom slucaju, getchar() vraca -1. */
  while ((c = getchar()) != EOF) {
    if (c >= 'A' && c <= 'Z')
      br_v++;
    else if (c >= 'a' && c <= 'z')
      br_m++;
    else if (c >= '0' && c <= '9') {
      br_c++;
      /* Kada od promenljive tipa char oduzimamo karakter (ili neku 
         drugu promenljivu tipa char), zapravo se vrsi oduzimanje
         njihovih ascii vrednosti i dobija se broj. */
      suma = suma + c - '0';
    } else if (c == '\t' || c == '\n' || c == ' ')
      br_b++;

    br_k++;
  }

  printf("velika: %d, mala: %d, cifre: %d, beline: %d \n", br_v,
         br_m, br_c, br_b);
  printf("suma cifara: %d\n", suma);

  return 0;
}
