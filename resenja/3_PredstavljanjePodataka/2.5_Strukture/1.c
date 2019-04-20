#include <stdio.h>

/* Struktura koja opisuje kompleksni broj. */
typedef struct 
{
  float re;
  float im;
} KompleksanBroj;

/* Kada se neka promenljiva zadaje kao argument funkcije, obicno
   se prenosi po vrednosti (bez pokazivaca), ako se ona nece
   menjati u funkciji ili po adresi (preko pokazivaca), ako ce se
   njena vrednost promeniti u funkciji.

   Prilikom poziva funkcije, za svaki argument funkcije kreira se
   promenljiva koja predstavlja lokalnu kopiju argumenta i koja
   prestaje da postoji po zavrsetku funkcije. S obzirom da se
   strukuture sastoje od vise polja, zauzimaju vise memorije nego
   nestrukturne promenljive. Zbog toga je za njihovo kopiranje
   potrebno vise vremena i vise memorijskih resursa nego za
   kopiranje nestrukturnih promenljivih.

   Da bi program bio efikasniji, korisno je da se struktura uvek
   prenosi po adresi (preko pokazivaca), bez obzira da li ce se 
   ona u toj funkciji menjati ili ne. Pokazivac na strukturu
   zauzima manje memorije nego sama struktura pa je izrada njegove
   kopije brza, a kopija pokazivaca uzima manji memorijski prostor
   nego kopija strukture. 
   
   Kada se strukturna promenljiva prenosi u funkciju po adresi
   (preko pokazivaca), tada postoji mogucnost da se njena polja
   menjaju u funkciji. Ukoliko to nije potrebno, uz argument se
   dodaje kljucna rec const. Na taj nacin, u slucaju pokusaja 
   izmene strukturne promenljive koja je prosledjena kao const,
   kompajler ce prijaviti gresku. Na ovaj nacin se obezbedjuje
   da promenljiva koja je preneta po adresi ne bude cak ni slucajno
   izmenjena u funkciji.
   
   Funkcija izracunava zbir kompleksnih brojeva. */
KompleksanBroj saberi(const KompleksanBroj * a, 
                      const KompleksanBroj * b)
{
  KompleksanBroj c;
  c.re = a->re + b->re;
  c.im = a->im + b->im;
  return c;
}

/* Funkcija izracunava razliku kompleksnih brojeva. */
KompleksanBroj oduzmi(const KompleksanBroj * a, 
                      const KompleksanBroj * b)
{
  KompleksanBroj c;
  c.re = a->re - b->re;
  c.im = a->im - b->im;
  return c;
}

/* Funkcija izracunava proizvod kompleksnih brojeva. */
KompleksanBroj pomnozi(const KompleksanBroj * a,
                       const KompleksanBroj * b)
{
  KompleksanBroj c;
  c.re = a->re * b->re - a->im * b->im;
  c.im = b->re * a->im + a->re * b->im;
  return c;
}

/* Funkcija izracunava kolicnik kompleksnih brojeva. */
KompleksanBroj podeli(const KompleksanBroj * a, 
                      const KompleksanBroj * b,
                      int* postoji_kolicnik)
{
  KompleksanBroj c;
  
  if (b->re != 0 || b->im != 0) 
  {
    c.re = (a->re * b->re + a->im * b->im) /
        (b->re * b->re + b->im * b->im);
    c.im = (b->re * a->im - a->re * b->im) /
        (b->re * b->re + b->im * b->im);
  }
  else
  {
    printf("Kolicnik ne postoji.\n");
    *postoji_kolicnik = 0;
  }
  
  return c;
}

int main()
{
  /* Deklaracije potrebnih promenlivih. */
  KompleksanBroj a, b;
  KompleksanBroj c;
  int postoji_kolicnik = 1;

  /* Ucitavanje kompleksnih brojeva. */
  printf("Unesite realni i imaginarni deo prvog broja: ");
  scanf("%f%f", &a.re, &a.im);

  printf("Unesite realni i imaginarni deo drugog broja: ");
  scanf("%f%f", &b.re, &b.im);

  /* Ispis zbira. */
  c = saberi(&a, &b);
  /* Ukoliko je imaginarni deo negativan, njegov zapis vec
     ukljucuje znak, u suprotnom, broj je oblika a + b*i. */
  printf("Zbir: %.2f%c%.2f*i\n", 
         c.re, c.im > 0 ? '+' : ' ', c.im);

  /* Ispis razlike. */
  c = oduzmi(&a, &b);
  printf("Razlika: %.2f%c%.2f*i\n",
         c.re, c.im > 0 ? '+' : ' ', c.im);

  /* Ispis proizvoda. */
  c = pomnozi(&a, &b);
  printf("Proizvod: %.2f%c%.2f*i\n",
         c.re, c.im > 0 ? '+' : ' ', c.im);

  /* Ispis kolicnika. */
  c = podeli(&a, &b, &postoji_kolicnik);
  if(postoji_kolicnik)
  {
    printf("Kolicnik: %.2f%c%.2f*i\n",
            c.re, c.im > 0 ? '+' : ' ', c.im);
  }

  return 0;
}
