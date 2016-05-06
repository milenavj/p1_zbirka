/*

  Data je struktura koja opisuje koordinate 
  tacke u ravni:

  typedef struct point
  {	
    float x;
    float y;	
  } POINT;

  U glavnom programu date su dve tacke: tacka
  A sa fiksiranim koordinatama (1,2) i tacka B
  cije koordinate zadaje korisnik. Napisati 
  funkcije:
  a) za racunanje rastojanja izmedju dve date tacke
  b) za odredjivanje tacke koja se nalazi na
     sredini duzi odredjene dvema datim tackama

  Testirati napisane funkcije u glavnom programu.

*/

#include <stdio.h>
#include <math.h>

typedef struct point
{	
  float x;
  float y;	
} POINT;

/*
  Poljima strukture pristupamo pomocu
  operatora .
  
  Ako je promenljiva a tipa POINT,
  njenim koordinatama pristupamo
  pomocu a.x i a.y
*/

float rastojanje (POINT a, POINT b)
{
  return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

POINT sredina (POINT a, POINT b)
{
  POINT s;
  s.x = (a.x+b.x)/2;
  s.y = (a.y+b.y)/2;
  return s;
}


int main()
{

  POINT a = {1,2};
  POINT b;
  POINT sredina_a_b;
  
  /* Ispisujemo koordinate tacke a. */
  printf("Tacka a ima koordinate %.2f,%.2f\n", a.x, a.y);
   
  /* Ucitavamo koordinate tacke b. */
  printf("Unesi prvu koordinatu tacke: ");
  scanf("%f", &b.x);
  printf("Unesi drugu koordinatu tacke: ");
  scanf("%f", &b.y);
  printf("Tacka b ima koordinate %.2f,%.2f\n", b.x, b.y);

  /* Strukture kao argumenti funkcije - prenos po vrednosti. */
  printf("Rastojanje izmedju tacaka a i b je %.2f\n", rastojanje(a,b));    

  /* Struktura kao povratna vrednost funkcije. */
  sredina_a_b=sredina(a,b);
  printf("Tacka na sredini izmedju tacaka a i b je %.2f,%.2f\n", sredina_a_b.x, sredina_a_b.y);	
  
  return 0;
}