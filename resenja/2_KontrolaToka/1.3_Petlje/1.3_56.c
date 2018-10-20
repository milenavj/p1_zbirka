#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n;
  int i, j;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Strelica se moze posmatrati kao spojena dva pravougla trougla
     kojima se ispisuje hipotenuza i jedna kateta. */

  /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++)
      /* Proverava se da li se ispisuje karakter na hipotenuzi
         (j == i) ili da se ispisuje poslednji red (i == n-1). */
      if (j == i || i == n - 1)
        printf("*");
      else
        printf(" ");
    printf("\n");
  }

  /* Zatim se iscrtava i donji deo slike, odnosno donji trougao.
     Brojac i odredjuje koji red donjeg trougla se trentno iscrtava. 
     Kako je prvi red donjeg trougla vec iscrtan (to je poslednji
     red gornjeg trougla), brojac se postavlja na 1. */
  for (i = 1; i < n; i++) {
    for (j = 0; j < n - i; j++)
      /* Provera da li se ispisuje hipotenuza. */
      if (j == n - i - 1)
        printf("*");
      else
        printf(" ");
    printf("\n");
  }

  return 0;
}
