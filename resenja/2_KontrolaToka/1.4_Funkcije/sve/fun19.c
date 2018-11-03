#include<stdio.h>

/* Funkcija koja vraca zbir cifara datog broja x. */
int zbir_cifara(int x)
{
  int zbir = 0;
  while (x) {
    zbir += x%10;
    x /= 10;
  }
  return zbir;
}

/* Funkcija koja vraca 1 ako je broj srecan, a 0 u suprotnom. */
int srecan(int x)
{
  /* Dok god u broju x ima vise od 2 cifre, vrednost broja x se
     zamenjuje sa zbirom njegovih cifara. Na primer, za pocetno
     x = 7698, nakon prve iteracije x postaje 7+6+9+8 = 30, nakon
     druge iteracije x postaje 3 + 0 = 3 i zatim se izlazi iz
     petlje. */
  while(x <= 10)
    x = zbir_cifara(x);
  
  /* Broj je srecan ako na kraju x ima vrednost 1. */
  return (x == 1);
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, i;
  
  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if(n <= 0)
  {
    printf("Greska: neispravan unos.\n");
    return -1;
  }
  
  /* Ispisuju se svi srecni brojevi manji ili jednaki n. */
  printf("Srecni brojevi: ");
  for (i = 1; i <= n; i++)
    if (srecan(i))
      printf("%d ", i);

  printf("\n");
  return 0;
}
