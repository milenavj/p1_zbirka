
#include <stdio.h>

int main()
{
  
  char c1, c2, c3, c4, c5;
 
  /* Citamo karaktere */
  /* Obratiti paznju na format ucitavanja */
  printf("Unesite karaktere: ");
  scanf("%c %c %c %c %c", &c1, &c2, &c3, &c4, &c5); 
  
  /* Proveravamo da li je prvi karakter malo ili veliko slova a */
  if(c1=='a' || c1=='A')
  {
    /* Ako jeste, ispusujemo karaktere u obrnutom redosledu */
    printf("%c %c %c %c %c\n", c5, c4, c3, c2, c1); 
  }
  
  return 0;
}