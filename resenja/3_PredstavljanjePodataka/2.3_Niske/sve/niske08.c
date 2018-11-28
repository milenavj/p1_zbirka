#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAKS_LINIJA 101

/* Funkcija ucitava liniju maksimalne duzine n i upisuje je u s.
   Funkcija ne smesta znak za novi red na kraj linije. */
void ucitaj_liniju(char s[], int n)
{
  int i = 0;
  int c;

  /* Ucitava se karakter po karakter dok se ne unese novi red
     ili oznaka za kraj ulaza ili dok se ne dostigne maksimalan
     broj karaktera. */
  while ((c = getchar()) != '\n' && i < n-1 && c != EOF) 
  {
    s[i] = c;
    i++;
  }

  /* Maksimalan broj karaktera za liniju je n-1 jer na kraju
     treba ostaviti i jedno mesto za terminalnu nulu. */
  s[i] = '\0';
}

/* Funkcija uklanja beline sa kraja niske s. */
void skrati(char s[])
{
  int i;
  /* Vrsi se prolazak kroz nisku sa desna na levo i trazi se pozicija
     prvog karaktera koji nije belina. 
     
     Funkcija isspace proverava da li je dati karakter neka od belina
     (blanko, tab ili novi red) i njena deklaracija se nalazi u
     zaglavlju ctype.h. */
  for (i = strlen(s) - 1; i >= 0; i--)
    if (!isspace(s[i]))
      break;
  
  /* Nakon izlaska iz petlje, brojac i se nalazi na poziciji prvog
     karaktera sa desne strane koji nije belina. Iz tog razloga se
     na poziciju i+1 upisuje terminalna nula kao oznaka da se sada
     tu nalazi kraj niske. */
  s[i + 1] = '\0';
}

int main()
{
  /* Deklaracija niske. */
  char s[MAKS_LINIJA];
  
  /* Ucitava se cela linija sa ulaza. */
  printf("Unesite nisku:\n");
  ucitaj_liniju(s, MAKS_LINIJA);
  
  /* NAPOMENA: 
     Postoji vise nacina za ucitavanje cele linije sa standardnog
     ulaza koriscenjem funkcija iz standardne c biblioteke. Jedan od
     njih je koriscenjem funkcije gets:
     gets(s);
     Postoje razlozi zasto ova funkcija nije bezbedna za koriscenje
     i oni ce biti objasnjeni u kasnijim poglaljima.
     U poglavlju "Datoteke" ce biti predstavljeni i bezbedni nacini 
     da se to uradi koriscenjem nekih drugoh funkcija. */
  
  /* Ispis rezultata. */
  printf("Ucitana niska:\n*%s*\n", s);
  skrati(s);
  printf("Izmenjena niska:\n*%s*\n", s);
  
  exit(EXIT_SUCCESS);
}
