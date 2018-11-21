#include<stdio.h>

/* Funkcija racuna najveci od 4 prosledjena broja. */
int maksimum(int a, int b, int c, int d)
{
  int max;

  max = a;
  if (b > max)
    max = b;
  if (c > max)
    max = c;
  if (d > max)
    max = d;

  return max;
}

/* Pomocna funkcija za stampanje beline ili zvezdice. */
void stampaj_znak(int polje, int granica)
{
  if (polje < granica)
    printf(" ");
  else
    printf("*");
}

/* Funkcija iscrtava vertikalni grafikon. */
void grafikon_v(int a, int b, int c, int d)
{
  int i, max;

  /* Na pocetku je potrebno pronaci najvecu od ove cetiri
     vrednosti. */
  max = maksimum(a, b, c, d);

  /* Grafikon ukupno ima max horizontalnih linija. */
  for (i = 0; i < max; i++) 
  {
    /* U svakoj od horizontalnih linija se nalazi po 4 polja: polje 
       za a,b,c i d uspravnu liniju. U svako od polja treba da se
       upise ili * ili belina, u zavisnosti od vrednosti i toga
       koja linija se trenutno ispisuje. */

    /* Stampa se znak za polje a. */
    stampaj_znak(i, max - a);

    /* Stampa se znak za polje b. */
    stampaj_znak(i, max - b);

    /* Stampa se znak za polje c. */
    stampaj_znak(i, max - c);

    /* Stampa se znak za polje d. */
    stampaj_znak(i, max - d);

    /* Na kraju svake horizontalne linije stampa se novi red. */
    printf("\n");
  }
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a, b, c, d;

  /* Ucitavaju se vrednosti cetiri broja. */
  printf("Unesite brojeve: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);

  /* Vrsi se provera ispravnosti ulaza i poziva se funkcija za
     ispis grafikona. */
  if (a < 0 || b < 0 || c < 0 || d < 0)
  {
    printf("Greska: neispravan unos.\n");
    return -1;
  }
  else
    grafikon_v(a, b, c, d);

  return 0;
}
