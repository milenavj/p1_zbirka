#include <stdio.h>

int main()
{
  /* Promenljiva x oznacava tekuci uneti broj. */
  int n, x;
  /* Brojac. */
  int i;
  int zbir = 0;

  printf("Unesite broj n: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Neispravan unos.\n");
    return -1;
  }

  printf("Unesite n brojeva: ");

  /* Inicijalizuje se brojac sa kojim se kontrolise broj *
     ucitavanja - treba da ih bude tacno n. */
  i = 0;
  while (i < n) {
    /* Ucitava se broj. */
    scanf("%d", &x);

    /* Proverava se da li broj negativan i neparan. */
    if (x < 0 && x % 2 != 0) {
      /* Ako jeste, dodajemo ga na zbir. */
      zbir = zbir + x;
    }

    /* Uvecava se brojac iteracija. */
    i++;
  }

  /* Ispisuje se rezultat. */
  printf("%d\n", zbir);

  return 0;
}
