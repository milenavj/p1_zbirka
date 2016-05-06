/*
   Struktura IZRAZ opisuje numericki izraz nad celim brojevima koji se sastoji
   od dva celobrojna operanda, numericke operacije nad celim brojevima i
   vrednosti izraza:
   
   typedef struct izraz
   {
	char o;
	int x;
	int y;
   } IZRAZ;

   a) Napisati funkciju koja ispituje da li je dati izraz korektno 
   zadat i vraca 1 ako jeste a 0 u suprotnom. Podrazumevamo da je 
   izraz korektno zadat ako operacija odgovara +,-,* ili / i u slucaju
   deljenja drugi operand je razlicit od 0.
   
   b) Napisati funkciju koja za dati izraz odredjuje vrednost izraza. 
   
   c) Napisati funkciju koja ucitava dati izraz. Funkcija
   treba da ucita sa standardnog ulaza operaciju i dva
   operanda u polja o, x i y strukture IZRAZ. Funkcija vraca
   1 ako je ucitavanje bilo uspesno, tj. ako je izraz bio
   korektno zadat ili 0 u suprotnom. 
   
   d) Napisati funkciju koja stampa dati izraz infiksno, u obliku
   x o y = vr. Na primer, za izraz + 4 17 ispis treba 
   da bude 4+17=21
   
   
   e) Napisati glavni program koji ucitava prirodan broj n<1000 a zatim n izraza
   u notaciji 
   + 4 17
   - 8 -16
   Program treba da ispise maksimalnu vrednost medju unetim izrazima i da ispise one
   izraze cija je vrednost manja od polovine maksimalne vrednosti.
   	


*/

#include <stdio.h>
#define MAX 1000

typedef struct izraz
{
	char o;
	int x;
	int y;
} IZRAZ;


/*
   Funkcija korektan_izraz vraca 1 ako je izraz korektan a 0
   u suprotnom. Izraz je korektan ukoliko se sastoji od
   aritmetickih operacija +,-,* ili /, i ukoliko je u slucaju
   operacije deljenja drugi operand razlicit od nule.
*/
int korektan_izraz(const IZRAZ* izraz)
{
   if(izraz->o!='+' && izraz->o!='-' && izraz->o!='*' && izraz->o!='/')
   {
      printf("Nedozvoljena operacija!\n");
      return 0;
   }
   if(izraz->o=='/' && izraz->y==0)
   {
      printf("Deljenje nulom!\n");
      return 0;
   }
   return 1;
}

/*
   Promenljiva izraz ce se promeniti u funkciji 
   vrednost tako sto ce njenom neinicijalizovanom
   polju vr biti dodeljena vrednost izraza. Zbog
   toga ovu promenljivu funkciji prosledjujemo
   po adresi, preko pokazivaca
*/

int vrednost(const IZRAZ* izraz)
{
   int v;
	
   switch (izraz->o)
   {
      case '+':
         v=izraz->x+izraz->y;
         break;
      case '-':
         v=izraz->x-izraz->y;
         break;
      case '*':
         v=izraz->x*izraz->y;
         break;
      case '/':
         v=izraz->x/izraz->y;
         break;
   }
   return v;	
}


/*
   Promenljiva izraz ce se promeniti u funkciji 
   ucitaj_izraz tako sto ce njenim neinicijalizovanim
   poljima o,x,y biti dodeljene vrednosti ucitane 
   sa standardnog ulaza. Zbog toga ovu promenljivu 
   funkciji prosledjujemo po adresi, preko pokazivaca.
  
   S obzirom da ucitavanje karaktera nije prvo
   ucitavanje koje se obavlja u programu, funkcijom
   getchar() "pokupimo" karakter kojim razdvajamo
   unos karaktera od prethodnog unosa (najcesce blanko
   znak)
  
*/

int ucitaj_izraz(IZRAZ* izraz)
{
   getchar();
   scanf("%c%d%d",&izraz->o, &izraz->x, &izraz->y);
   if (!korektan_izraz(izraz))
      return 0;
   return 1;
}


void stampaj_izraz(const IZRAZ* izraz)
{
   printf("%d %c %d = %d\n", izraz->x, izraz->o, izraz->y, vrednost(izraz));
}

int max_vr(IZRAZ izrazi[], int n)
{
   int i;
   int max;
   /* Trazimo maksimalnu vrednost izraza */
   max=vrednost(&izrazi[0]);
	
   /* U petlji... */
   for(i=1; i<n; i++)
   /* Ako je ona veca od maksimalne: */
      if(vrednost(&izrazi[i])>max)
         /* Azuriramo max: */
         max=vrednost(&izrazi[i]);
   return max;	
}

int main()
{
   int n;
   IZRAZ izrazi[MAX];
   int max;
   int i;
	
   /* Ucitavamo broj izraza: */
   scanf("%d", &n);
   if(n<0 || n>MAX)
   {
      printf("Nekorektna vrednost broja n!\n");
      return -1;
   }
	
	
    /* U petlji ucitavamo jedan po jedan izraz: */
   for(i=0; i<n; i++)
      if(ucitaj_izraz(&izrazi[i])==0)
      {
         printf("Nekorektan unos\n");                 
         return -1;
      }


   printf("Svi izrazi:\n");
   for(i=0; i<n; i++)    
         stampaj_izraz(&izrazi[i]);
   	
   max = max_vr(izrazi, n);
   printf("Maksimalna vrednost izraza:%d\n", max);
        
   printf("Izrazi cija je vrednost manja od polovine maksimalne vrednosti:\n");	
   
   for(i=0; i<n; i++)    
      if(vrednost(&izrazi[i])<max/2)/* Ako je vrednost tekuceg izraza manja od polovine maksimalne, ispisujemo ga. */
         stampaj_izraz(&izrazi[i]);
         				
   return 0;
}