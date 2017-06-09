#include <stdio.h>
#define MAX 1000

typedef struct
{
	char o;
	int x;
	int y;
} IZRAZ;


int korektan_izraz(const IZRAZ izraz)
{
   if(izraz.o != '+' && izraz.o != '-' && izraz.o != '*' && izraz.o != '/')
   {
      printf("Nedozvoljena operacija!\n");
      return 0;
   }
   if(izraz.o == '/' && izraz.y == 0)
   {
      printf("Deljenje nulom!\n");
      return 0;
   }
   return 1;
}

/* Racunanje vrednosti izraza. */
int vrednost(const IZRAZ izraz)
{
   int v;
	
   switch (izraz.o)
   {
      case '+':
         return izraz.x + izraz.y;
      case '-':
         return izraz.x - izraz.y;
      case '*':
         return izraz.x * izraz.y;
      case '/':
         return izraz.x / izraz.y;
   }
}


/*
   Promenljiva izraz ce se promeniti u funkciji 
   ucitaj_izraz tako sto ce njenim neinicijalizovanim
   poljima o,x,y biti dodeljene vrednosti ucitane 
   sa ulaza. Zbog toga ovu promenljivu 
   funkciji prosledjujemo po adresi, preko pokazivaca.
  
   S obzirom da ucitavanje karaktera nije prvo
   ucitavanje koje se obavlja u programu, funkcijom
   getchar() se ucita karakter kojim se razdvaja
   unos karaktera od prethodnog unosa (najcesce blanko
   znak ili znak za novi red).
  
*/

int ucitaj_izraz(IZRAZ* izraz)
{
   getchar();
   scanf("%c%d%d",&izraz->o, &izraz->x, &izraz->y);
   if (!korektan_izraz(*izraz))
      return 0;
   return 1;
}


void stampaj_izraz(const IZRAZ izraz)
{
   printf("%d %c %d = %d\n", izraz.x, izraz.o, izraz.y, vrednost(izraz));
}

int max_vr(IZRAZ izrazi[], int n)
{
   int i;
   int max;
   
   max=vrednost(izrazi[0]);
	   
   for(i=1; i<n; i++)
      if(vrednost(izrazi[i])>max)
         max=vrednost(izrazi[i]);

   return max;	
}

int main()
{
   int n;
   IZRAZ izrazi[MAX];
   int max;
   int i;
	
   printf("Uneti broj izraza: ");
   scanf("%d", &n);
   if(n<0 || n>MAX)
   {
      printf("Nekorektna vrednost broja n!\n");
      return -1;
   }
	
	
   printf("Uneti izraze u prefiksnoj notaciji:\n");
   for(i=0; i<n; i++)
      if(ucitaj_izraz(&izrazi[i])==0)
      {
         printf("Nekorektan unos\n");                 
         return -1;
      }

   	
   max = max_vr(izrazi, n);
   printf("Maksimalna vrednost izraza:%d\n", max);
        
   printf("Izrazi cija je vrednost manja od polovine maksimalne vrednosti:\n");	
   
   for(i=0; i<n; i++)    
      if(vrednost(izrazi[i])<max/2)
         stampaj_izraz(izrazi[i]);
         				
   return 0;
}
