#include <stdio.h>
#include <string.h>

#define MAX_DUZINA 21
#define MAX_BR_VOCKI 50

typedef struct vocka
{
  char ime[MAX_DUZINA];
  float vitamin;
} VOCKA;


int main()
{
  VOCKA vocke[MAX_BR_VOCKI];
  int i = 0, n, max_vocka;
  char ime[MAX_DUZINA];

  /*
    Ucitavamo podatke o vockama i smestamo ih u niz
    sve dok ne unesemo rec KRAJ ili ucitamo MAX_BR_VOCKI vocki.
  */
  do
  {
    printf("Unesite ime vocke i njenu kolicinu vitamina C: ");
    scanf("%s",ime);
    /*
      Kada unesemo rec KRAJ prekidamo petlju.
    */
    if(strcmp(ime, "KRAJ") == 0)
      break;

    /*
      Inace ucitavamo i kolicinu vitamina
      i tu vrednost smestamo u vocku na poziciji i
    */
    strcpy(vocke[i].ime,ime);
    scanf("%f",&vocke[i].vitamin);
    i++;
  }
  while(i<MAX_BR_VOCKI);

  n = i;

  /*
    Pretpostavicemo da prva vocka ima najvise vitamina. 
    Procicemo kroz niz vocki i ukoliko naidjemo na vocku koja ima vise vitamina
    od one koja trenutno ima najvise, azuriracemo vrednosti maksimalne vocke.
    
    Sve vreme cuvamo indeks vocke sa najvise vitamina C.
  */
  
  max_vocka = 0;
  for(i=1;i<n;i++)
    if(vocke[i].vitamin > vocke[max_vocka].vitamin)
    {
      max_vocka = i;
    }

  printf("Voce sa najvise C vitamina je: %s\n", vocke[max_vocka].ime);
  
  return 0;
}
