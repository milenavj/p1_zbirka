#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_DUZINA 20
#define MAKS_NISKA (MAKS_DUZINA + 1)
#define MAKS_REZULTAT (3*MAKS_DUZINA + 1)

/* Pomocna funkcija koja za prosledjeno slovo
   vraca slovo koje ide posle njega. */
char sledeci(char c)
{
  if(c == 'z')
    return 'a';
  
  if(c == 'Z')
    return 'A';
  
  return c+1;
}

/* Funkcija koja svako slovo niske s menja sa slovom
   koje se u ASCII tablici nalazi neposredno iza njega.
   Specijalan slucaj je slovo z koje treba da se zameni
   sa slovom a. Ostali karakteri ostaju nepromenjeni. */
void sifruj(char s[], char rezultat[]){
  int i, j;
  
  /* Brojac i se koristi za nisku s, a brojac j za
     rezultujucu nisku. */
  for(i=0, j=0; s[i]; i++){
    if(isalpha(s[i]))
    {
      /* Ako je s[i] slovo, onda se u rezultat upisuju 3 slova koja
         slede nakon njega. */
      rezultat[j] = sledeci(s[i]);
      rezultat[j+1] = sledeci(rezultat[j]);
      rezultat[j+2] = sledeci(rezultat[j+1]);
      j += 3;
    }
    else
    {
      /* Ako s[i] nije slovo, onda se samo prepisuje u rezultat. */
      rezultat[j] = s[i];
      j++;
    }
  }
  
  /* Na kraj rezultata se dopisuje terminalna nula. */
  rezultat[j] = '\0';
}

int main()
{
  /* Deklaracija niske. */
  char s[MAKS_NISKA];
  char rezultat[MAKS_REZULTAT];
  
  /* Ucitava se niska. */
  printf("Unesite nisku: ");
  scanf("%s", s);
  
  /* Racunanje i ispis rezultata. */
  sifruj(s, rezultat);
  printf("%s\n", rezultat);
  
  exit(EXIT_SUCCESS);
}