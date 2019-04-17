#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAKS_LINIJA 81
#define MAKS_NISKA 21
    
/* Funkcija prebrojava koliko linija datoteke ulaz se zavrsava
   niskom s. */    
int brojLinija(FILE * ulaz, char *s)
{
  char linija[MAKS_LINIJA];
  int broj_linija = 0;
  int duzina_s = strlen(s);
  int duzina_linije;
  
  /* Iz datoteke se cita linija po linija, sve dok se ne dodje
     do kraja datoteke. */
  while (fgets(linija, MAKS_LINIJA, ulaz) != NULL) 
  {
    /* Racuna se duzina procitane linije. */
    duzina_linije = strlen(linija);
    
    /* Sklanja se znak za novi red sa kraja linije. */
    if (linija[duzina_linije - 1] == '\n') 
    {
      linija[duzina_linije - 1] = '\0';
      duzina_linije--;
    }
    
    /* Poredi se kraj linije sa niskom s. 
       Kraj linije se moze dobiti tako sto se izvrsi 'pomeranje' u
       desno do kraja linije, a zatim 'pomeranje' u levo onoliko
       mesta koliko je dugacka niska s.
       Na primer, ako je linija "abcdefghijk", a niska s "ab", 
       onda sa linija + duzina_linije se vrsi pomeranje na karakter
       iza karaktera 'k', a sa:
       linija + duzina_linije - duzina_s na karakter 'j'.
       Ukoliko se funkcija strcmp pozove sa:
       strcmp(linija + duzina_linije - duzina_s, s),
       vrsice se poredjenje niske "jk" i "ab", sto je i bio cilj. */
    if (strcmp(linija + duzina_linije - duzina_s, s) == 0)
      broj_linija++;
  }
  
  /* Kao povratna vrednost se vraca broj linija koje se zavrsavaju
     niskom s. */
  return broj_linija;
}
 
int main()
{
  FILE *ulaz;
  char s[MAKS_NISKA];
  
  /* Otvara se datoteka ulaz.txt i proverava se da li je otvaranje
     proslo uspesno. */
  ulaz = fopen("ulaz.txt", "r");
  if (ulaz == NULL) 
  {
    fprintf(stderr, "Greska: neuspesno otvaranje ulazne "
                    "datoteke.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Ucitava se niska s. */ 
  printf("Unesite nisku s: ");
  scanf("%s", s);
  
  /* Ispis rezultata. */ 
  printf("Broj linija: %d\n", brojLinija(ulaz, s));
  
  /* Zatvara se datoteka. */ 
  fclose(ulaz);
 
  return 0;
}