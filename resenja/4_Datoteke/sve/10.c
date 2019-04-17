#include <stdio.h>
#include <string.h>
#include <stdlib.h>
    
#define MAKS_NISKA 21
    
/* Funkcija rotira nisku s duzine n za jedno mesto u desno. */
void rotiraj_za_1(char *s, int n)
{
  int i;
  char c = s[0];
  
  for (i = 0; i < n - 1; i++)
    s[i] = s[i + 1];
  
  s[n - 1] = c;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  char s[MAKS_NISKA];
  int n, i;
  FILE *izlaz;

  /* Datoteka rotacije.txt se otvara za pisanje i proverava se da
     li je datoteka uspesno otvorena. */
  izlaz = fopen("rotacije.txt", "w");
  if (izlaz == NULL) 
  {
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke.");
    exit(EXIT_FAILURE);
  }
  
  /* Ucitava se rec koju je potrebno rotirati. */
  printf("Unesite rec: ");
  scanf("%s", s);
 
  /* Izracunava se duzina reci. */
  n = strlen(s);
  
  /* U petlji se uneta rec rotira za 1 i ispisuje u datoteku. 
     Postupak se ponavlja n puta. */
  for (i = 0; i < n; i++) 
  {
    fprintf(izlaz, "%s\n", s);
    rotiraj_za_1(s, n);
  }
  
  /* Zatvara se datoteka. */ 
  fclose(izlaz);
  
  return 0;
}