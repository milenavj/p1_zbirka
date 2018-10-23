#include <stdio.h>

int main()
{
  /* Deklaracije i inicijalizacije. */
  char c;
  int broj_velikih = 0, broj_malih = 0;
  int broj_cifara = 0, suma_cifara = 0, broj_belina = 0;

  /* Petlja se zavrsava kada korisnik zada konstantu oznaku za kraj
     ulaza (konstanta EOF cija je vrednost -1). Ova konstanta se
     zadaje kombinacijom tastera CTRL+D. */
  while ((c = getchar()) != EOF) {
    if (c >= 'A' && c <= 'Z')
      broj_velikih++;
    else if (c >= 'a' && c <= 'z')
      broj_malih++;
    else if (c >= '0' && c <= '9') {
      broj_cifara++;
      suma_cifara = suma_cifara + c - '0';
    } 
    else if (c == '\t' || c == '\n' || c == ' ')
      broj_belina++;
  }

  /* Ispis rezultata. */
  printf("velika: %d, mala: %d\n", broj_velikih, broj_malih);
  printf("cifre: %d, beline: %d\n", broj_cifara, broj_belina);
  printf("suma cifara: %d\n", suma_cifara);

  return 0;
}
