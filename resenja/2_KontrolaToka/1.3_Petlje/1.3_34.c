#include <stdio.h>

int main()
{
  char c;

  /* Funkcija getchar ucitava jedan karakter. Naredbom dodele
     (c=getchar()) promenljivoj c bice dodeljena vrednost ascii
     koda unetog karaktera. Obratiti posebnu paznju na zagrade. */

  while ((c = getchar()) != '.') {
    if (c >= 'A' && c <= 'Z')
      /* Razlika izmedju ascii koda svakog malog i odgovarajuceg
         velikog slova je konstanta koja se moze sracunati izrazom
         'a'-'A' (i iznosi 32). */
      putchar(c + 'a' - 'A');
    else if (c >= 'a' && c <= 'z')
      putchar(c - 'a' + 'A');
    else
      putchar(c);
  }

  return 0;
}
