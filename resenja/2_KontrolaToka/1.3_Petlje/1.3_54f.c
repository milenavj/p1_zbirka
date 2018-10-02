#include <stdio.h>

int main()
{
  unsigned int n, i, j;
  char c, blanko;

  printf("Unesite broj n: ");
  scanf("%u", &n);

  printf("Unesite karakter c: ");
  /* Zbog pritiskanja tastera ENTER nakon unosa promenljive broj
     potrebno je ucitati karakter za novi red u promenljivu blanko
     pre ucitavanja karaktera kojim se iscrtava trougao. */
  scanf("%c%c", &blanko, &c);

  /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i = 0; i < n; i++) {
    /* Iscrtavaju se samo ivice trougla, ostalo se popunjava
       belinama. */
    for (j = 0; j <= i; j++)
      if (i == n - 1 || j == 0 || j == i)
        printf("%c", c);
      else
        printf(" ");
    printf("\n");
  }

  return 0;
}
