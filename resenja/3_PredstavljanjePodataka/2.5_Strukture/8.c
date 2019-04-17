#include <stdio.h>
#include <stdlib.h>

#define MAKS 1000

typedef struct 
{
  char o;
  int x;
  int y;
} Izraz;

/* Funkcija proverava da li je izraz ispravno zadat. */
int korektan_izraz(const Izraz* izraz)
{
  if (izraz->o != '+' && izraz->o != '-' && 
      izraz->o != '*' && izraz->o != '/') 
  {
    printf("Greska: neispravna operacija.\n");
    return 0;
  }
  
  if (izraz->o == '/' && izraz->y == 0) 
  {
    printf("Greska: deljenje nulom.\n");
    return 0;
  }
  
  return 1;
}

/* Funkcija ucitava n izraza sa standardnog ulaza. */
void ucitaj(Izraz izrazi[], int n)
{
  int i;
  
  printf("Unesite izraze u prefiksnoj notaciji:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%c%d%d", &izrazi[i].o, &izrazi[i].x, &izrazi[i].y);
    /* Preskace se novi red koji se nalazi nakon izraza, kako bi 
       naredni izraz bio ispravno ucitan. */
    getchar(); 
    
    /* Provera ispravnosti ucitanog izraza. */
    if (!korektan_izraz(&izrazi[i])) 
    {
      printf("Greska: neispravan unos.\n");
      exit(EXIT_FAILURE);
    }
  } 
}

/* Funkcija racuna vrednost izraza. */
int vrednost(const Izraz* izraz)
{
  switch (izraz->o) 
  {
    case '+':
      return izraz->x + izraz->y;
    case '-':
      return izraz->x - izraz->y;
    case '*':
      return izraz->x * izraz->y;
    case '/':
      return izraz->x / izraz->y;
    default:
      printf("Greska: neispravna operacija.\n");
      exit(EXIT_FAILURE);
  }
}

/* Funkcija racuna najvecu vrednost izraza. */
int najveca_vrednost(Izraz izrazi[], int n)
{
  int i;
  int maks_vrednost, tr_vrednost;

  maks_vrednost = vrednost(&izrazi[0]);
  
  for (i = 1; i < n; i++)
  {
    tr_vrednost = vrednost(&izrazi[i]);
    if (tr_vrednost > maks_vrednost)
      maks_vrednost = tr_vrednost;
  }

  return maks_vrednost;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int n;
  Izraz izrazi[MAKS];
  int maks, trenutna_vrednost;
  float polovina;
  int i;

  /* Ucitavanje broja izraza i provera ispravnosti ulaza. */
  printf("Unesite broj izraza: ");
  scanf("%d", &n);
  if (n < 0 || n > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Preskace se belina koja se unosi nakon broja izraza. 
     Ovaj korak je neophodan jer se izraz zadaje u formatu
     <operacija> <operand> <operand> 
     A <operacija> je tipa char i kada bi ovaj korak bio
     izostavljen, ta belina bi bila ucitana kao <operacija>
     za prvi izraz. */
  getchar();
  ucitaj(izrazi, n);
  
  /* Pronalazak polovine maksimalne vrednosti. */
  maks = najveca_vrednost(izrazi, n);
  printf("Maksimalna vrednost izraza:%d\n", maks);
  polovina = maks / 2.0;
  
  /* Ispis rezultata. */
  printf("Izrazi cija je vrednost manja od polovine maksimalne "
         "vrednosti:\n");
  for (i = 0; i < n; i++)
  {
    trenutna_vrednost = vrednost(&izrazi[i]);
    if (trenutna_vrednost < polovina)
    {
      printf("%d %c %d = %d\n", izrazi[i].x, izrazi[i].o, 
             izrazi[i].y, trenutna_vrednost);
    }
  }

  return 0;
}
