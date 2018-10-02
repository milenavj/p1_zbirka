#include <stdio.h>

int main()
{
  unsigned int n, i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);


  /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i = 0; i < n; i++) {
    /* Prvo se ispisuju beline koje prethode karakterima *. */
    for (j = 0; j < n - i - 1; j++)
      printf(" ");
    /* Posle belina se ispisuje potreban broj karaktera *. */
    for (j = 0; j <= i; j++)
      printf("*");
    printf("\n");
  }

  /* Potrebno je iscrtati i donji deo slike, odnosno donji trougao.
     Brojac i odredjuje koji red donjeg trougla se trentno iscrtava. 
     * Kako je prvi red dodnjeg trougla vec iscrtan (to je poslednji
     red gornjeg trougla), brojac se postavlja na 1. */
  for (i = 1; i < n; i++) {
    /* Prvo se ispisuju beline koje prethode karakterima *. */
    for (j = 0; j < i; j++)
      printf(" ");
    /* Posle belina se ispisuje potreban broj karaktera *. */
    for (j = 0; j < n - i; j++)
      printf("*");
    printf("\n");
  }

  return 0;
}
