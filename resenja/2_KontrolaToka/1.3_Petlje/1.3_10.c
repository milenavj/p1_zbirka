#include<stdio.h>
#include<stdlib.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int x;
  
  /* Ucitava se vrednost broja x. */
  printf("Unesi ceo broj:");
  scanf("%d", &x);

  /* Uzima se apsolutna vrednost broja da bi izdvojene cifre bile
     pozitivni brojevi. Na primer, 123%10 je 3, a -123%10 je -3. */
  x = abs(x);

  /* Slucaj kada je uneti broj 0 se posebno obradjuje. */
  if(x == 0)
  {
    printf("0\n");
    return 0;
  }
  
  /* U petlji se obradjuje cifra po cifra broja, dok god ima 
     neobradjenih cifara u broju. */
  while (x != 0) {
    /* Ispisuje se poslednja cifra broja x. */
    printf("%d ", x % 10);
    
    /* Uklanja se poslednja cifra broja x. */
    x /= 10;
  }
  printf("\n");

  return 0;
}
