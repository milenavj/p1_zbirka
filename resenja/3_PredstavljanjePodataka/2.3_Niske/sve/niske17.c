#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_NISKA 8

/* Funkcija koja proverava da li je prosledjeni karakter ispravna
   heksadekadna cifra. */
int heksa_cifra(char c){
  c = toupper(c);
  
  /* Cifra je ispravna ako je cifra ili ako je neko od slova:
     A, B, C, D, E ili F. */
  return isdigit(c) || (c >= 'A' && c <= 'F');
}

/* Funkcija koja proverava da li prosledjena niska s predstavlja
   ispravan heksadekadni broj. */
int heksadekadni_broj(char s[]){
  int i;

  /* Svaki heksadekasni broj pocinje sa 0x ili 0X. */
  if (s[0] != '0' || toupper(s[1]) != 'X')
    return 0;

  /* Za svaki karakter niske s se proverava da li predstavlja 
     ispravnu heksadekadnu cifru. Ako se naidje na neku cifru koja
     ne zadovoljava taj uslov, onda se kao povratna vrednost
     vraca nula. */
  for (i = 2; s[i]; i++)
    if (!heksa_cifra(s[i]))
      return 0;

  /* Ako su sve cifre isravne heksadekadne cifre, onda je i s
     ispravan heksadekadni broj i funkcija vraca jedninicu. */
  return 1;
}

int main()
{
  /* Deklaracija niske. */
  char s[MAKS_NISKA];

  /* Ucitava se niska. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Ispis rezultata. */
  if (heksadekadni_broj(s))
    printf("Korektan heksadekadni broj.\n");
  else
    printf("Nekorektan heksadekadni broj.\n");

  exit(EXIT_SUCCESS);
}