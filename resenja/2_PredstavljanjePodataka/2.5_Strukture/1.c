#include <stdio.h>

/* Struktura koja opisuje kompleksni broj obuhvata polje za realni 
 * i polje za imaginarni deo broja. 
 */
typedef struct Complex {

  float re;
  float im;
} Complex;  

/* Funkcija kojom se izracunava zbir kompleksnih brojeva. */
Complex saberi(Complex *a, Complex *b) {

  Complex c;
  c.re = a->re + b->re;
  c.im = a->im + b->im;
  return c;
}

/* Funkcija kojom se izracunava razlika kompleksnih brojeva. */
Complex oduzmi(Complex *a, Complex *b) {

  Complex c;
  c.re = a->re - b->re;
  c.im = a->im - b->im;
  return c;
}

/* Funkcija kojom se izracunava proizvod kompleksnih brojeva. */
Complex pomnozi(Complex *a, Complex *b) {

  Complex c;
  c.re = a->re * b->re - a->im * b->im;
  c.im = b->re * a->im + a->re * b->im;
  return c;
}

/* Funkcija kojom se izracunava kolicnik kompleksnih brojeva. */
Complex podeli(Complex *a, Complex *b) {

  Complex c;
  c.re = (a->re * b->re + a->im * b->im) / (b->re*b->re + b->im*b->im);
  c.im = (b->re * a->im - a->re * b->im) / (b->re*b->re + b->im*b->im);
  return c;
}

int main() {

  Complex a, b;
  Complex c;
  
  /* Ucitavamo kompleksne brojeve. */
  printf("Unesite realni i imaginarni deo prvog broja: ");
  scanf("%f%f", &a.re, &a.im);

  printf("Unesite realni i imaginarni deo drugog broja: ");
  scanf("%f%f", &b.re, &b.im);
  
  c = saberi(&a, &b);
   /* Ukoliko je imaginarni deo negativan, 
	  * njegov zapis vec ukljucuje znak,
	  * te to treba proveriti.
	  * Inace, broj je oblika a+b*i.
    */
  printf("Zbir: %.2f%c%.2f*i\n", c.re, c.im > 0 ? '+' : ' ', c.im);
  
  c = oduzmi(&a, &b);
  printf("Razlika: %.2f%c%.2f*i\n", c.re, c.im > 0 ? '+' : ' ', c.im);
  
  c = pomnozi(&a, &b);
  printf("Proizvod: %.2f%c%.2f*i\n", c.re, c.im > 0 ? '+' : ' ', c.im);
  
  if(b.re != 0 || b.im != 0) {
    c = podeli(&a, &b);
    printf("Kolicnik: %.2f%c%.2f*i\n", c.re, c.im > 0 ? '+' : ' ', c.im);
  }
  /* U polju kompleksnih brojeva
   * nije dozvoljeno deljenje nulom.
   */
  else
    printf("Kolicnik ne postoji.\n"); 
					

  return 0;
}
