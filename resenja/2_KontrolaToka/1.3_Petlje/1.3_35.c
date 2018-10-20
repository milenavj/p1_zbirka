#include <stdio.h>

int main()
{
  /* Deklaracije i inicijalizacije. */
  char c;
  int br_v = 0;
  int br_m = 0;
  int br_c = 0;
  int br_b = 0;
  int br_k = 0;
  int suma = 0;

  /* Petlja se zavrsava kada korisnik zada konstantu oznaku za kraj
     ulaza (konstanta EOF cija je vrednost -1). Ova konstanta se
     zadaje kombinacijom tastera CTRL+D. */
  while ((c = getchar()) != EOF) {
    if (c >= 'A' && c <= 'Z')
      br_v++;
    else if (c >= 'a' && c <= 'z')
      br_m++;
    else if (c >= '0' && c <= '9') {
      br_c++;
      suma = suma + c - '0';
    } 
    else if (c == '\t' || c == '\n' || c == ' ')
      br_b++;

    br_k++;
  }

  /* Ispis rezultata. */
  printf("velika: %d, mala: %d\n", br_v, br_m);
  printf("cifre: %d, beline: %d\n", br_c, br_b);
  printf("suma cifara: %d\n", suma);

  return 0;
}
