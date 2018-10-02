#include <stdio.h>

#define MAXART 20
#define MAXPOT 100
#define MAXNAZIV 31

typedef struct artikal
{
   char naziv[MAXNAZIV];
   int kolicina;
   float cena;
} ARTIKAL;

typedef struct korpa
{
   int br_art;
   ARTIKAL artikli[MAXART];
} KORPA;

/*
   Funkcija ucitaj_artikal ucitava podatke za jedan
   artikal i vraca 1 ako je ucitavanje bilo uspesno
   a 0 u suprotnom. Ucitavanje je neuspesno ukoliko
   kolicina nekog artikla ili njegova cena nisu pozitivni
   brojevi.
   
   S obzirom da funkcija ucitaj artikal treba da vrati
   dve vrednosti (ucitanu strukturu i indikator uspesnosti),
   strukturu ARTIKAL prenosimo preko pokazivaca a 
   indikator uspesnosti vracamo kao povratnu vrednost.
   
*/

int ucitaj_artikal(ARTIKAL* a)
{
   printf("Unesi artikal, naziv, kolicinu i cenu: ");
   scanf("%s", a->naziv);
   scanf("%d", &a->kolicina);
   
   if (a->kolicina<=0)
   {
      printf("Nekorektan unos za kolicinu artikla: %d\n", a->kolicina);
      return 0;
   }
   
   scanf("%f",&a->cena);
   if (a->cena<0)
   {
      printf("Nekorektan unos za cenu artikla: %f\n", a->cena);
      return 0;
   }
   
   return 1;   
}

/*
   Funkcija izracunaj_racun izracunava racun date
   potrosacke korpe u kojoj su inicijalizovani
   podaci o broju artikala i o svakom pojedinacnom
   artiklu.    
*/
float izracunaj_racun(const KORPA* k)
{
   int i;
   float racun=0;
   for(i=0;i<k->br_art;i++)
      racun+=k->artikli[i].kolicina * k->artikli[i].cena;         
   return racun;
}

/*
   Pri ucitavanju korpe, zadaje se broj artikala a zatim 
   podaci za svaki artikal. 
   
   Funkcija ucitaj_korpu vraca 1 ako je ucitavanje uspesno
   i 0 u suprotnom. Do neuspesnog ucitavanja moze doci
   ako broj artikala u korpi nije pozitivan ili ako dodje
   do neuspesnog ucitavanja nekog artikla.
*/

int ucitaj_korpu(KORPA* k)
{
   int i;
	 printf("Uneti podatke o korpi: \n");
	 printf("Broj artikala: ");
   scanf("%d", &k->br_art);
   if (k->br_art<=0)
   {
      printf("Nekorektan unos za broj artikala: %d\n", k->br_art);
      return 0;
   }   
   for(i=0; i<k->br_art;i++)
      if (ucitaj_artikal(&k->artikli[i])==0)
         return 0;
            
   return 1;
}

/*
   Funkcija ucitaj_niz_korpi ucitava podatke
   za niz od n potrosackih korpi. Funkcija
   vraca 1 ako je ucitavanje uspesno i 0 ako 
   nije. Ucitavanje je neuspesno ukoliko ne uspe
   ucitavanje jedne od korpi.
*/

int ucitaj_niz_korpi(KORPA korpe[], int n)
{
   int i,j;
   for(i=0; i<n; i++)
      if(ucitaj_korpu(&korpe[i])==0)
         return 0;
         
   return 1;
   
}

/*
   Funkcija stampaj_racun ispisuje na
   standardni izlaz racun za datu korpu
   tako sto za svaki artikal ispise
   naziv, cenu i kolicinu i na kraju
   ukupnu cenu za kupljene artikle.
*/

void stampaj_racun(const KORPA* k)
{
   int i,j;
   for(i=0;i<k->br_art;i++)
      printf("\t%s %d %.2f\n", k->artikli[i].naziv, k->artikli[i].kolicina, k->artikli[i].cena);
   printf("------------------------\n");   
   printf("\tukupno: %.2f\n", izracunaj_racun(k));
   
}

/*
   Funkcija stampaj_racune_za_korpe 
   ispisuje na standardni izlaz racune
   za svaku korpu u nizu potrosackih
   korpi
*/

void stampaj_racune_za_korpe(KORPA korpe[], int n)
{
   int i;
   for (i=0;i<n;i++) 
   {
      printf("\nKorpa %d:\n",i);
      stampaj_racun(&korpe[i]);
   }
}

/*
   Funkcija prosek racuna prosecnu cenu
   potrosacke korpe za dati niz potrosackih
   korpi
*/
float prosek(KORPA korpe[], int n)
{
   int i;
   float p;
   
   for(i=0;i<n;i++)
      p+=izracunaj_racun(&korpe[i]);
      
   return p/n;   
}

int main()
{
   int n;
   KORPA korpe[MAXPOT];
   
   printf("Uneti broj potrosackih korpi:");
   scanf("%d", &n);
   
   if(n<0 || n>MAXPOT)
   {
      printf("Nekorektan unos broja potrosackih korpi: %d\n",n);
      return -1;
   }
   
   if (ucitaj_niz_korpi(korpe, n)==0)
      return -1;
      
   stampaj_racune_za_korpe(korpe,n);
   printf("Prosecna cena potrosacke korpe: %.2f\n", prosek(korpe, n));
   
   return 0;
}
