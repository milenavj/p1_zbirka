/* Resenje pod b). */

#include <stdio.h>

int main()
{

  /* Promenljive koje oznacavaju granice intervala. */
  int n, m;
  /* Promenljiva koja oznacava trenutno ispisani broj intervala. */
  int i;

  printf("Unesi dva cela broja: ");
  scanf("%d%d", &n, &m);

  if (m < n) {
    printf
        ("Neispravan unos. Nisu dobro zadate granice intervala!\n");
    return -1;
  }


  /* naredba i=n se izvrsava jednom, pre prve iteracije */
  for (i = n; i <= m; i++)      /* uslov petlje i<=m se proverava
                                   pre svake iteracije */
    printf("%d ", i);           /* naredba i++ se izvrsava nakon
                                   svake iteracije */

  printf("\n");


  return 0;
}
