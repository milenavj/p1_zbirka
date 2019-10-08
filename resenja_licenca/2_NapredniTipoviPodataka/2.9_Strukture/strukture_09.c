/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAKS_IME 21
#define MAKS_PREZIME 31
#define MAKS_EMAIL 51
#define MAKS_OSOBA 50

/* Struktura koja opisuje osobu. */
typedef struct {
  char ime[MAKS_IME];
  char prezime[MAKS_PREZIME];
  char email[MAKS_EMAIL];
} Osoba;

/* I nacin: Funkcija proverava da li se prosledjeni email zavrsava
   sa "gmail.com" koriscenjem funkcije strtok. */
int gmail(char email[]) {
  /* Funkcija strtok "deli" nisku u podniske tako sto ih razdvaja
     na mestu na kom se nalazi prosledjeni delimiter (u ovom
     slucaju je to "@"). Na primer, ukoliko je
     email="pera.peric@gmail.com", funkcija deli ovu nisku na
     "pera.peric" i "gmail.com". */
  char *deo = strtok(email, "@");

  /* Kada se funkcija sledeci put pozove i pri tom pozivu se kao
     prvi argument navede NULL, tada funkcija vraca sledeci token u 
     nizu, a to je u ovom slucaju "gmail.com". */
  deo = strtok(NULL, "");

  /* Ako se email zavrsava na "gmail.com", funkcija vraca 1, a u
     suprotnom 0. */
  return strcmp(deo, "gmail.com") == 0;
}

/* II nacin:
int gmail2(char email[])
{
  //Pronalazi se pokazivac na znak @. 
  char* desni_deo = strchr(email, '@');

  //Poredi se niska koja pocinje jedan karakter posle @ sa
  //niskom "gmail.com". 
  return strcmp(desni_deo+1, "gmail.com") == 0;
} */


int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, i, postoji_gmail_adresa = 0;
  Osoba osobe[MAKS_OSOBA];

  /* Ucitavanje broja osoba i provera ispravnosti ulaza. */
  printf("Unesite broj osoba: ");
  scanf("%d", &n);
  if (n < 0 || n > MAKS_OSOBA) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje podataka o osobama. */
  printf("Unesite podatke o osobama (ime, prezime i imejl adresu):\n");
  for (i = 0; i < n; i++)
    scanf("%s%s%s", osobe[i].ime, osobe[i].prezime, osobe[i].email);

  /* Ispis rezultata. */
  for (i = 0; i < n; i++) {
    if (gmail(osobe[i].email)) {
      if (!postoji_gmail_adresa) {
        /* U ovu granu ce se uci samo kada se naidje na prvog
           vlasnika gmail naloga. */
        printf("Vlasnici gmail naloga su:\n");
        postoji_gmail_adresa = 1;
      }
      printf("%s %s\n", osobe[i].ime, osobe[i].prezime);
    }
  }

  /* Ukoliko se nije naislo ni na jednog vlasnika gmail naloga,
     promenljiva postoji_gmail_adresa ce ostati 0 i u tom slucaju
     se ispsuje odgovarajuca poruka. */
  if (!postoji_gmail_adresa)
    printf("Nema vlasnika gmail naloga.\n");

  exit(EXIT_SUCCESS);
}
