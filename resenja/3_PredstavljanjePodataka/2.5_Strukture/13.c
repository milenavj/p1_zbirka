#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAKS_IME 21
#define MAKS_PREZIME 31
#define MAKS_EMAIL 51
#define MAKS_OSOBA 50

typedef struct 
{
  char ime[MAKS_IME];
  char prezime[MAKS_PREZIME];
  char email[MAKS_EMAIL];
} Osoba;

/* I nacin:
   Funkcija proverava da li se prosledjeni email zavrsava sa
   "gmail.com" koriscenjem funkcije strtok. */
int gmail(char email[])
{
  /* Funkcija strtok "deli" nisku u podniske tako sto ih razdvaja
     na mestu na kom se nalazi prosledjeni delimiter (u ovom slucaju
     je to "@"). 
     Na primer, ukoliko je email="pera.peric@gmail.com", funkcija
     deli ovu nisku na "pera.peric" i "gmail.com". */
  char *deo = strtok(email, "@");
  
  /* Kada se funkcija sledeci put pozove i pri tom pozivu se kao
     prvi argument navede NULL, tada funkcija vraca sledeci token u nizu,
     a to je u ovom slucaju "gmail.com". */
  deo = strtok(NULL, "");

  /* Ako se email zavrsava na "gmail.com", funkcija vraca 1, a 
     u suprotnom 0. */
  return strcmp(deo, "gmail.com") == 0;
}

// /* II nacin:
//    Funkcija proverava da li se prosledjeni email zavrsava sa
//    "gmail.com" koriscenjem funkcije strchr. */
// int gmail2(char email[])
// {
//   /* Pronalazi se pokazivac na znak @. */
//   char* desni_deo = strchr(email, '@');
//   
//   /* Poredi se niska koja pocinje jedan karakter posle @ sa
//      niskom "gmail.com". */
//   return strcmp(desni_deo+1, "gmail.com") == 0;
// }

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  Osoba osobe[MAKS_OSOBA];

  /* Ucitavanje broja osoba i provera ispravnosti ulaza. */
  printf("Unesite broj osoba: ");
  scanf("%d", &n);
  if (n < 0 || n >= MAKS_OSOBA) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje podataka o osobama. */
  printf("Unesite podatke o osobama, ime, prezime i email.\n");
  for (i = 0; i < n; i++)
    scanf("%s%s%s", osobe[i].ime, osobe[i].prezime, osobe[i].email);

  /* Ispis rezultata. */
  printf("Vlasnici gmail naloga su:\n");
  for (i = 0; i < n; i++)
    if (gmail(osobe[i].email))
      printf("%s %s\n", osobe[i].ime, osobe[i].prezime);

  return 0;
}
