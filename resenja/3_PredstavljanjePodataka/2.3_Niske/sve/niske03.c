#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_NISKA 21

/* Funckija pretvara sva slova niske s u velika slova. */
void u_velika_slova(char s[])
{
  int i;
  
  for(i=0; s[i]; i++)
    s[i] = toupper(s[i]);
}

/* Funkcija vraca 1 ako su niske s1 i s2 jednake, a nulu inace. */
int jednake(char s1[], char s2[]){
  int i;
  
  /* Prolazi se kroz obe niske dok god ima neobradjenih karaktera
     u bilo kojoj od njih. Ukoliko se naidje na karaktere koji 
     su razliciti, kao povratna vrednost se vraca 0 jer u tom
     slucaju niske nisu jednake. */
  for(i=0; s1[i] || s2[i]; i++)
    if(s1[i] != s2[i])
      return 0;
  
  /* Ako se doslo do kraja petlje znaci da su se svi karakteri
     poklopili, a da se pri tom doslo do kraja obe niske, tako da
     se kao povratna vrednost funkcije vraca 1 jer su niske
     s1 i s2 jednake. */
  return 1;
}

int main(){
  /* Deklaracija potrebnih promenljivih. */
  char s1[MAKS_NISKA], s2[MAKS_NISKA];
  
  /* Ucitavaju se niske s1 i s2. */
  printf("Unesite niske:\n");
  scanf("%s%s", s1, s2);
  
  /* Kako bi se pri poredjenju zanemarila razlika izmedju malih i
     velikih slova, sva slova obe niske se pretvaraju u velika. */
  u_velika_slova(s1);
  u_velika_slova(s2);
  
  /* Ispis rezultata. */
  if(jednake(s1, s2))
    printf("Niske su jednake.\n");
  else
    printf("Niske nisu jednake.\n");
  
  exit(EXIT_FAILURE);
}