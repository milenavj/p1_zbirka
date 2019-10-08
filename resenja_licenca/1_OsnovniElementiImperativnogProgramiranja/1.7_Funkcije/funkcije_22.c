/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <math.h>

/* Funkcija ispisuje vrednosti funkcije sin(x) u n ravnomeno
   rasporedjenih tacaka na intervalu [a,b]. */
void ispis(float a, float b, int n) {
  double i;
  double korak = (b - a) / (n - 1);

  for (i = a; i <= b; i += korak, n--)
    printf("sin(%.4lf) = %.4lf \n", i, sin(i));

  /* Zapis realnih brojeva u racunaru ne mora da bude precizan 
     i sabiranje realnih brojeva moze, zbog akumuliranja greske, 
     da dovede do toga da iako je 
     korak = (b - a) / (n - 1)
     ne vazi da je
     b = a + korak + korak + ... + korak
     (gde se korak sabira n-1 puta). Vrednost ovog zbira, u 
     zavisnosti od konkretnih brojeva, moze da bude i malo veca 
     i malo manja od b. Zbog toga, dodatno proveravamo da li 
     treba da stampamo vrednost funkcije i u tacki b */
  if(n != 0) 
    printf("sin(%.4lf) = %.4lf \n", b, sin(b));
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  float a, b;
  int n;

  /* Ucitavanje granica intervala i provera ispravnosti ulaza. */
  printf("Unesite dva realna broja: ");
  scanf("%f%f", &a, &b);
  if (b <= a) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Ucitavanje broja n i provera ispravnosti ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if (n <= 1) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Ispis rezultata. */
  printf("Rezultat:\n");
  ispis(a, b, n);

  return 0;
}
