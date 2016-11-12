#include <stdio.h>

int main()
{
  char c;

  printf("Unesite karakter: ");
  scanf("%c", &c);

  if (c >= 'a' && c <= 'z')
    printf("%c\n", c - 'a' + 'A');
  else if (c >= 'A' && c <= 'Z')
    printf("%c\n", c - 'A' + 'a');
  else if (c >= '0' && c <= '9')
    printf("cifra\n");
  /* Ako nijedan od prethodnih uslova nije ispunjen, bice izvrsena
     naredba u else grani */
  else
    printf("*%c*\n", c);

  return 0;
}
