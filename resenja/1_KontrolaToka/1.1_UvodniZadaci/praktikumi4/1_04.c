/* Napisati program koji za unete dimenzije sobe u metrima (duzinu, sirinu i
visinu) ispisuje koju povrsinu treba da okreci moler. Uracunati da na vrata i
prozore otpada oko 20%. Omoguciti i unos cene usluge po kvadratnom metru i
izracunati zaradu koju ostvaruje moler.
 */

#include <stdio.h>

int main(){
  int duzina, sirina, visina;
  int cena;
  float povrsina_za_krecenje;
  float ukupna_cena;
  
  /* Ucitavamo duzinu, sirinu i visinu sobe */
  printf("Unesite dimenzije sobe: ");
  scanf("%d %d %d", &duzina, &sirina, &visina);
  
  /* Ucitavamo cenu krecenja */
  printf("Unesite cenu po kvadratnom metru: ");
  scanf("%d", &cena);
  
  /* Povrsina za krecenje odgovara povrsini kvadra - bez poda jer se on ne
kreci */
  povrsina_za_krecenje=0.8*(duzina*sirina+2*duzina*visina+2*sirina*visina);
  ukupna_cena=povrsina_za_krecenje*cena;
  
  /* Ispisujemo trazene podatke */
  printf("Moler treba da okreci %.2f kvadratna metra\n", povrsina_za_krecenje);
  printf("Cena krecenja je %.2f\n", ukupna_cena);
  
  /* Zavrsavamo sa programom */
  return 0;
}