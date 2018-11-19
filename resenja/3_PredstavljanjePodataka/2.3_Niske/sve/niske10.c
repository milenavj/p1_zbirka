#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_LINIJA 101

/* Funkcija ucitava liniju maksimalne duzine n i upisuje je u s.
   Funkcija ne smesta znak za novi red na kraj linije. */
void ucitaj_liniju(char s[], int n)
{
  int i = 0, c;
  
  while ((c = getchar()) != '\n' && i < n-1 && c != EOF) 
  {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
}

/* Pomocna funkcija koja proverava da li karakter c1 treba zadrzati
   ako vazi da se iza njega nalazi c2. */
int treba_zadrzati(char c1, char c2)
{  
  /* Ako neki od karaktera nije slovo, c1 se ne izbacuje. */
  if(!isalpha(c1) || !isalpha(c2))
    return 1;
  
  /* Oba karaktera se pretvaraju u veliko slovo kako bi se smanjio
     broj poredjenja. */
  c1 = toupper(c1);
  c2 = toupper(c2);
  
  /* c1 se zadrzava ako se c2 ne nalazi iza njega u abecedi. */
  return c2 <= c1;
}

/* Funkcija uklanja sva slova za koja vazi da se neposredno 
   nakon njih nalazi slovo koje je u abecedi iza njih. */
void ukloni(char s[])
{  
  int i, j;
  for(i=0, j=0; s[i]; i++){
    if(treba_zadrzati(s[i], s[i+1]))
    {
      s[j] = s[i];
      j++;
    }
  }
  s[j] = '\0';
}

int main()
{
  /* Deklaracija niske. */
  char s[MAKS_LINIJA];
  
  /* Ucitava se cela linija sa ulaza. */
  printf("Unesite nisku:\n");
  ucitaj_liniju(s, MAKS_LINIJA);

  /* Ispis rezultata. */
  ukloni(s);
  printf("%s\n", s);
  
  exit(EXIT_SUCCESS);
}
