#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAKS_LINIJA 81

/* Funkcija koja ucitava liniju maksimalne duzine n i upisuje
   je u s. Funkcija ne smesta znak za novi red na kraj linije. */
int ucitaj_liniju(char s[], int n)
{
  int i = 0;
  int c;

  /* Ucitava se karakter po karakter dok se ne unese novi red
     ili oznaka za kraj ulaza ili dok se ne dostigne maksimalan
     broj karaktera. */
  while ((c = getchar()) != '\n' && i < n-1 && c != EOF) {
    s[i] = c;
    i++;
  }

  /* Maksimalan broj karaktera za liniju je n-1 jer na kraju
     treba ostaviti i jedno mesto za terminalnu nulu. */
  s[i] = '\0';
  
  return i;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  char linija[MAKS_LINIJA], najduza_linija[MAKS_LINIJA];
  int duzina_najduze = 0, duzina;

  /* U petlji se ucitavaju linije sve dok se ne unese prazna linija.
     Ukoliko se unese linija koja je duza od trenutno najduze,
     vrsi se azuriranje duzine najduze linije, kao i same linije. */
  while ((duzina = ucitaj_liniju(linija, MAKS_LINIJA)) > 0) {
    if (duzina_najduze < duzina) {
      duzina_najduze = duzina;
      strcpy(najduza_linija, linija);
    }
  }

  /* Ispis rezultata. */
  if(duzina_najduze == 0)
    printf("Nije uneta nijedna linija.\n");
  else
    printf("%s\n%d\n", najduza_linija, duzina_najduze);

  exit(EXIT_SUCCESS);
}
