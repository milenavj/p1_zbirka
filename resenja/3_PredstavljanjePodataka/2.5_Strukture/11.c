#include <stdio.h>
#include <stdlib.h>

#define MAKS_STUDENATA 2000
#define MAKS_NISKA 31

typedef struct Student {
  char ime[MAKS_NISKA];
  char prezime[MAKS_NISKA];
  char smer;
  float prosek;
} Student;

/* Funkcija ucitava podatke o studentima u niz. */
void ucitaj(Student niz[], int n)
{
  int i; 
  
  printf("Unesite podatke o studentima:\n");
  for (i = 0; i < n; i++) 
  {
    printf("%d. student: ", i);
    scanf("%s %s %c %f", niz[i].ime, niz[i].prezime, 
          &niz[i].smer, &niz[i].prosek);

    if (niz[i].smer != 'R' && niz[i].smer != 'I' && 
        niz[i].smer != 'V' && niz[i].smer != 'N' && 
        niz[i].smer != 'T' && niz[i].smer != 'O') 
    {
      printf("Greska: neispravan unos smera.\n");
      exit(EXIT_FAILURE);
    }
  }
}

/* Funkcija ispisuje podatke o studentu. */
void ispisi(const Student * s)
{
  printf("%s %s, %c, %.2f\n", s->ime, s->prezime, s->smer,
         s->prosek);
}

/* Funkcija racuna najveci prosek. */
float najveci_prosek(Student studenti[], int n)
{
  float maks_prosek;
  int i;

  maks_prosek = studenti[0].prosek;
  for (i = 1; i < n; i++)
    if (maks_prosek < studenti[i].prosek)
      maks_prosek = studenti[i].prosek;
    
  return maks_prosek;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  Student studenti[MAKS_STUDENATA];
  int n, i;
  float maks_prosek;
  char smer;

  /* Ucitavanje broja studenata i provera ispravnosti ulaza. */
  printf("Unesite broj studenata: ");
  scanf("%d", &n);
  if (n < 0 || n > MAKS_STUDENATA) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Ucitavanje podataka o studentima. */
  ucitaj(studenti, n);

  /* Ucitavanje smera. Pre smera se preskace novi red koji je unet 
     nakon podataka o poslednjem studentu. */
  printf("Unesite smer: ");
  getchar();
  scanf("%c", &smer);
  if (smer != 'R' && smer != 'I' && smer != 'V' && smer != 'N' && 
      smer != 'T' && smer != 'O') 
  {
    printf("Greska: neispravan unos smera.\n");
    exit(EXIT_FAILURE);
  }

  /* Ispis studenata sa unetog smera. */
  printf("Studenti sa %c smera:\n", smer);
  for (i = 0; i < n; i++)
    if (studenti[i].smer == smer)
      printf("%s %s\n", studenti[i].ime, studenti[i].prezime);
  printf("---------------------\n");

  /* Racunanje najveceg proseka. */
  maks_prosek = najveci_prosek(studenti, n);
  
  /* Ispis svih studenata sa najvecim prosekom. */
  printf("Svi studenti koji imaju maksimalni prosek:\n");
  for (i = 0; i < n; i++)
    if (studenti[i].prosek == maks_prosek)
      ispisi(&studenti[i]);

  return 0;
}
