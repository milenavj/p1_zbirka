#include<stdio.h>
#include<math.h>

int main()
{
  int x;
  /* Brojac u petlji. */
  int i;

  /* Ucitavamo broj. */
  printf("Unesi ceo broj veci od 0: ");
  scanf("%d", &x);

  if (x <= 0) {
    printf("Neispravan unos.\n");
    return -1;
  }

  /* 1. nacin */
  printf("------------ 1. nacin ------------\n");
  for (i = 2; i < x; i++) {
    /* Proverava se da li i deli broj x i ako je to slucaj ispusje
       se i. */
    if (x % i == 0)
      printf("%d \n", i);
  }

  /* 2. nacin (brzi) -- Ne proveravaju se svi brojevi od 2 do x,
     vec se petlja izvrsava dok ne stignemo do korena broja. */
  printf("------------ 2. nacin ------------\n");
  for (i = 2; i <= sqrt(x); i++) {
    /* Proveravamo da li i deli broj x. */
    if (x % i == 0)
      /* U slucaju kada je delilac koren broja, npr. 4 za 16,
         ispisujemo ga jednom. */
      if (i == x / i)
        printf("%d \n", i);
    /* U suprotnom, npr. 2 za 16, ispisujemo i 2 i 8. */
      else
        printf("%d %d \n", i, x / i);
  }

  return 0;
}
