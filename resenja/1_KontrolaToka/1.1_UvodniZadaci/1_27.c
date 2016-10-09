
#include <stdio.h>

int main(){
  unsigned duzina, sirina, visina;
  unsigned cena;
  float povrsina_za_krecenje;
  float ukupna_cena;
  
  /* Ucitavamo duzinu, sirinu i visinu sobe */
  printf("Unesite dimenzije sobe: ");
  scanf("%u%u%u", &duzina, &sirina, &visina);
  
  /* Ucitavamo cenu krecenja */
  printf("Unesite cenu po m2: ");
  scanf("%u", &cena);
  
  /* Povrsina za krecenje odgovara povrsini kvadra - 
     bez poda jer se on ne kreci */
  povrsina_za_krecenje=0.8*(duzina*sirina+
                            2*duzina*visina+
                            2*sirina*visina);
  ukupna_cena=povrsina_za_krecenje*cena;
  
  /* Ispisujemo trazene podatke */
  printf("Moler treba da okreci %.2f m2\n", 
          povrsina_za_krecenje);
  
  printf("Cena krecenja je %.2f\n", ukupna_cena);
  
  /* Zavrsavamo sa programom */
  return 0;
}