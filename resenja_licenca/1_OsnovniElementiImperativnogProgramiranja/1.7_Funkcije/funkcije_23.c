/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

/* Funkcija vraca karakter koji se u engelskoj abecedi nalazi k mesta pre
   datog karaktera c. */
char sifra(char c, int k) {
  /* Provera da li je karakter malo slovo. */
  if (c >= 'a' && c <= 'z') {
    /* Ako karakter koji je k pozicija pre datog karaktera ispada
       iz opsega malih slova. */
    if (c - k < 'a')
      /* Od k se oduzima rastojanje izmedju c i 'a' (jer je za
         toliko karaktera vec vraceno u nazad), kako bi se odredilo 
         koliko preostali broj karaktera koji treba preskociti od
         karaktera 'z'. */
      return 'z' - (k - (c - 'a') - 1);
    else
      /* U suprotnom, karakter c-k ne ispada iz opsega malih slova, 
         te je dovoljno njega vratiti. */
      return c - k;
  } else if (c >= 'A' && c <= 'Z') {
    /* Postupak se ponavlja i za velika slova. */
    if (c - k < 'A')
      return 'Z' - (k - (c - 'A') - 1);
    else
      return c - k;
  }

  /* Ako nije ni malo ni veliko slovo, karakter se ne menja. */
  return c;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int k;
  char c;

  /* Ucitavanje vrednosti k. */
  printf("Unesite broj k: ");
  scanf("%d", &k);

  /* Ucitavanje karaktera sve do kraja ulaza i ispis njihove
     sifre. */
  printf("Unesite tekst (CTRL + D za prekid): ");
  while ((c = getchar()) != EOF)
    putchar(sifra(c, k));

  return 0;
}
