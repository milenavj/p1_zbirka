#include <stdio.h>

int main()
{
  /* Deklaracija broja n. */
  int n;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Slucaj kada broj n ima vrednost nula se posebno obradjuje.
     Kada ovo ne bi bilo navedeno, petlja u nastavku bi se 
     u ovom slucaju izvrsavala beskonacno. */
  if (n == 0) {
    printf("0\n");
    return 0;
  } 
  
  /* Dok god je poslednja cifra broja n nula, broj n se deli sa
      10 i na taj nacin se iz broja uklanja poslednja cifra. */
  while (n % 10 == 0)
    n = n / 10;

  /* Ispis rezultata. */
  printf("%d\n", n);

  return 0;
}
