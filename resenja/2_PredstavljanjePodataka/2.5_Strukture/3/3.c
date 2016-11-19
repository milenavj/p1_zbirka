/*

Napisati program koji ucitava reci sa standardnog ulaza dok korisnik ne zada EOF i ispisuje
ih na standardni izlaz svaku u posebnom redu, poravnatu udesno u odnosu 
na poslednji karakter najduze reci. Koristiti
strukturu typedef struct rec
	  {
	     char s[21];
	     int duzina;
          }REC;
Na primer, ako su unesene sledece reci:
Danas imamo ispit iz programiranja1.
Nadam se da nece biti tesko!
onda ispis izgleda ovako:
          Danas 
          imamo 
          ispit 
             iz 
programiranja1.
          Nadam 
             se 
             da 
           nece 
           biti 
         tesko!

Program realizovati kroz sledece funkcije:
a) Funkciju za ucitavanje jedne reci u strukturu REC.
b) Funkciju za ucitavanje niza struktura koja vraca dimenziju niza
c) Funkciju koja odredjuje maksimalnu duzinu reci u datom nizu
d) Funkciju koja ispisuje reci u trazenom formatu

Mozemo pretpostaviti da nijedna rec ne sadrzi vise od 30 karaktera i da nece biti
uneto vise od 1000 reci.
*/

#include<stdio.h>
#include<string.h>
#define MAXRECI 100
#define MAX 31

typedef struct rec
{
   char s[MAX];
   int duzina;
}REC;


void ucitaj_rec(REC* rec)
{
   scanf("%s", rec->s);
   rec->duzina = strlen(rec->s);
}

/*
   U funkciji ucitaj_niz_reci argument n oznacava broj
   elemenata niza reci, koji ce biti poznat tek po
   zavrsetku funkcije. Ova promenljiva ce dobiti svoju
   vrednost u funkciji i zbog toga mora biti prenesena
   preko pokazivaca. 
   
*/

void ucitaj_niz_reci(REC reci[], int* pn, int granica)
{
   int i=0;
   do
   {
      ucitaj_rec(&reci[i]);
      i++;
   }
   while(reci[i-1].duzina>0 && (i-1)<granica);
   
   /*
      S obzirom da se promenljiva i ucitava
      pre ispitivanja uslova, uslov ispitujemo
      za rec sa indeksom i-1
   */   

   *pn = i-1;
   
   /*
      S obzirom da se vrednost promenljive i 
      ucitava i kada je unesen EOF, dimenzija
      niza odgovarace vrednosti i-1
   */
}

int max_duzina(REC reci[], int n)
{
   int najveca_duzina;
   int i;

   /*
      Najvecu duzinu inicijalizujemo na duzinu
      prve reci.
   */   
   najveca_duzina = reci[0].duzina;
           
   for(i=1;i<n;i++)	
      if(reci[i].duzina>najveca_duzina)   /* Ukoliko u nizu naidjemo na rec duzine vece od najvece duzine, */
         najveca_duzina = reci[i].duzina; /* menjamo vrednost promenljive najveca_duzina. */
         
   return najveca_duzina;
}

/*
   Da bismo realizovali ispis u trazenom formatu, pre 
   svake reci ispisujemo onoliko razmaka koliko iznosi
   razlika maksimalne duzine i duzine date reci.
*/

void ispis(REC reci[], int n, int max_d)
{
   int i,j;
   
   for(i=0;i<n;i++)       
   {
      for(j=0;j<max_d-reci[i].duzina;j++)     
         printf(" ");
      printf("%s\n", reci[i].s);
   }

}

int main(int argc, char* argv[])
{
   REC reci[MAXRECI];
   int najveca_duzina;
   int n;

   ucitaj_niz_reci(reci, &n, MAXRECI);
   najveca_duzina = max_duzina(reci,n);
   ispis(reci, n, najveca_duzina);

   return 0;
}
