#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int c;

  /* Promenljive ulaz i izlaz predstavljaju pokazivace na ugradjenu
     strukturu FILE. Unutar ove strukture se nalaze polja neophodna
     za rad sa datotekama. */
  FILE *ulaz, *izlaz;

  /* Funkcija fopen sluzi da otvori datoteku. Prvi argument je
     putanja do datoteke koja se otvara, a drugi argument je niska
     koja moze imati vrednosti "r", "r+", "w", "w+", "a", "a+".
     Kada ovaj argument ima vrednost "r" datoteka se otvara za
     citanje. Ukoliko datoteka ne postoji, funkcija fopen kao
     povratnu vrednost vraca NULL. */
  ulaz = fopen("ulaz.txt", "r");
  if (ulaz == NULL) {
    /* Funkcija fprintf vrsi ispis u datoteku. Funkcionise isto kao
       i funkcija printf - razlika je sto se kao prvi argument
       prosledjuje datoteka u koju se ispisuje izlaz.

       Ukoliko je izlaz potrebno ispisati na standardni izlaz za
       greske, kao prvi argument se navodi stderr. */
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke "
            "ulaz.txt.\n");
    exit(EXIT_FAILURE);
  }

  /* Ukoliko je drugi argument funkcije fopen "w", tada se
     prosledjena datoteka otvara za pisanje. */
  izlaz = fopen("izlaz.txt", "w");
  if (izlaz == NULL) {
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke "
            "izlaz.txt. \n");
    exit(EXIT_FAILURE);
  }

  /* Funkcija fgetc ucitava jedan karakter iz datoteke ulaz.
     Povratna vrednost ove funkcije je ASCII kod unetog karaktera.
     Funkcija fputc ispisuje karakter c u datoteku izlaz. */
  while ((c = fgetc(ulaz)) != EOF)
    fputc(c, izlaz);

  /* Nakon zavrsetka rada sa datotekama, neophodno ih je zatvoriti
     pomocu ugradjene funkcije fclose. */
  fclose(ulaz);
  fclose(izlaz);

  return 0;
}
