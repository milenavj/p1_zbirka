#include <stdio.h>
#include <stdlib.h>

#define MAKS_NISKA 10

/* Funkcija koja racuna broj cifara broja n. */
int broj_cifara(int n)
{
  int i = 0;
  do{
    i++;
    n/=10;
  }while(n);
  
  return i;
}

/* Funkcija koja od prosledjenog broja formira nisku. */
void broj_u_nisku(int broj, char s[])
{
  int n, cifra, i;
  
  /* Promenljiva n cuva informaciju o duzini niske. Duzina niske
     odgovara broju cifara prosledjenog broja. Ukoliko je broj
     negativan, onda se duzina uvecava za 1 i na prvo mesto se 
     upisuje znak '-'. */
  n = broj_cifara(broj);
  if(broj < 0)
  {
    s[0] = '-';
    n++;
  }
  
  /* U nastavku se radi sa apsolutnom vrednoscu broja. */
  broj = abs(broj);
  
  /* Cifre broja se upisuju u nisku s sa desna na levo. */
  s[n] = '\0';
  i = n-1;
  do{ 
    /* Karakter koji odgovara trenutnoj cifri se dobija izrazom
       '0' + cifra. Na primer, '0' + 5 je '5' jer se karakter '5'
       nalazi 5 mesta nakon karaktera '0' u ASCII tablici. */
    cifra = broj % 10;
    broj = broj / 10;
    s[i] = '0' + cifra;
    i--;
  } while(broj);
}

int main()
{
  /* Deklaracija broja i niske. */
  int n;
  char s[MAKS_NISKA];

  /* Ucitava se broj. */
  printf("Unesite ceo broj: ");
  scanf("%d", &n);

  /* Formira se niska. */
  broj_u_nisku(n, s);

  /* Ispis rezultata. */
  printf("%s\n", s);

  exit(EXIT_SUCCESS);
}