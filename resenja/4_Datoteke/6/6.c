/*
  Za svaki automobil poznati su marka, model i cena. Iz datoteke cije
  se ime zadaje sa standardnog ulaza Ucitavanje broj automobila a potom
  i podaci za svaki automobil. Program treba da:
  a) izracuna prosecnu cenu po marki kola
  b) za maksimalnu cenu koju je kupac spreman da plati, a koja se zadaje
  kao argument komandne linije, da ispise automobile u tom cenovnom
  rangu zajednu sa prosecnom cenom odgovarajuce marke

  Mozemo pretpostaviti da se model i marka sastoje od jedne reci i 
  da svaka od njih sadrzi najvise 30 karaktera kao i da se u datoteci
  nalaze podaci za najvise 100 automobila.
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 31
#define MAXA 100

typedef struct automobil
{
   char marka[MAX];
   char model[MAX];
   float cena;
} AUTOMOBIL;

/*
   Struktura INFO sadrzi naziv
   marke automobila, prosek cena
   za tu marku i broj automobila
   te marke
*/
typedef struct info
{
   char marka[MAX];
   float vrednost;
   int n;
} INFO;

int ucitaj_podatke(FILE* f, AUTOMOBIL a[], int* pn, int max)
{
   int i;

   fscanf(f,"%d", pn);
   if (*pn<=0 || *pn>max)
   {
      printf("Nekorektan unos dimenzije niza automobila\n");
      return 0;
   }
   for(i=0;i<*pn;i++)   
      fscanf(f,"%s %s %f", a[i].marka, a[i].model, &a[i].cena);

   return 1;
}

/*
   Funkcija sadrzi ispituje da li se u nizu proseka po marki
   nalazi prosek za marku m. Posto podatak o marki automobila
   predstavlja string, poredjenje vrsimo pomocu funkcije strcmp.
   
   Povratna vrednost ove funkcije je indeks pojavljivanja, ukoliko
   se marka m pojavljuje u nizu proseka, ili -1 u suprotnom.   
*/

int sadrzi(INFO p[], int n, char m[])
{
   int i;
   for(i=0;i<n;i++)
      if(strcmp(p[i].marka,m)==0)
         return i;
         
   return -1;
}

/*
   Funkcija informacije_o_markama za niz automobila a dimenzije n
   racuna proseke cena automobila po markama i smesta ih u niz
   p. Na dimenziju niza p pokazuje pokazivac pn. 
   
   Ideja je da jednim prolaskom kroz niz sa svaku marku izracunamo
   sumu cena automobila te marke (koju cemo smestiti u polje vrednost strukture
   INFO), i broj automobila te marke (koju cemo smestiti u polje
   n strukture INFO) i da na kraju podelimo ove dve promenljive
   i tako dobijemo prosecnu vrednost cene.
   
   Za svaki automobil a[i] proveravamo da li se njegova marka vec
   nalazi u nizu p. Ukoliko se nalazi, nadjenom elementu dodajemo
   vredost cene automobila a[i] i uvecavamo broj automobila sa 
   tom markom. U suprotnom, dodajemo novi element u niz p. Posto
   ga dodajemo na kraj, njegov indeks odgovarace dimenziji niza p
   na koju pokazuje pokazivac *pn.
*/
void informacije_o_markama(AUTOMOBIL a[], int n, INFO p[], int* pn1)
{
   int i,j;
   int ind;
   for(i=0;i<n;i++)
   {
      /* Proveravamo da li se marka automobila a[i] vec nalazi u 
         nizu p (niz proseka po markama) */
      ind = sadrzi(p,*pn1,a[i].marka);
      if(ind==-1) /* Ako se ne nalazi, uvodimo novi element niza na kraj, na poziciju *pn. */
      {
         strcpy(p[*pn1].marka, a[i].marka);
         p[*pn1].vrednost = a[i].cena;
         p[*pn1].n = 1;
         (*pn1)++; /* Zagrade su neophodne zbog prioriteta operatora. */
      }
      else /* Ako se nalazi, azuriramo polja strukture. */
      {
         p[ind].vrednost+=a[i].cena;
         p[ind].n++;
      }   
   }         
   
   /* Na osnovu sume cena i broja automobila racunamo prosecnu vrednost. */
   for(i=0;i<*pn1;i++)
      p[i].vrednost = p[i].vrednost/p[i].n;
      
}

void stampaj_informacije(INFO p[], int n)
{
   printf("Informacije o broju automobila i prosecnoj ceni po markama:\n");
   int i;
   for(i=0;i<n;i++)
      printf("%s %.2f %d\n", p[i].marka, p[i].vrednost, p[i].n);
}

/*
   Funkcija stampa automobile cija je cena manja od maksimalne
   cene koju je korisnik naveo u komandnoj liniji da je spreman
   da plati, zajedno sa prosecnom cenom za tu marku automobila
*/
void stampaj_kandidate(AUTOMOBIL a[], int n, float g, INFO p[], int n1)
{
   /*
      S obzirom da je niz p formiran na osnovu niza a, marka svakog
      automobila iz niza a se sigurno nalazi u nizu p. Zbog toga
      nije neophodno proveravati da li je povratna vrednost funkcije
      sadrzi razlicita od -1.
   */
   int i;
   printf("Kola u vasem cenovnom rangu:\n");
   for(i=0;i<n;i++)
      if(a[i].cena<g)
         printf("%s %s %.2f\n", a[i].marka, a[i].model, p[sadrzi(p,n1,a[i].marka)].vrednost);
}

int main(int argc, char* argv[])
{
   AUTOMOBIL kola[MAXA];   
   FILE* f;
   char dat[MAX]; /* Naziv datoteke koji se unosi sa standardnog ulaza. */  
   float granica; /* Maksimalna cena koju je korisnik spreman da plati.
                     Zadaje se kao argument komandne linije.                     
                  */
   INFO infos[MAXA];
   int dim_kola,dim_infos;
   int i;
   
   if(argc!=2)      
   {
      fprintf(stderr,"Greska: program se pokrece sa: %s gornja_granica_cene \n", argv[0]);
      exit(EXIT_FAILURE);       
   }
   
   /* Argumenti komandne linije su stringovi. Da bismo od stringa dobili
      realan broj, koristimo ugradjenu funkciju atof. */
   granica = atof(argv[1]);
   
   printf("Unesi naziv datoteke:");
   scanf("%s", dat);
   
   f=fopen(dat, "r");
   
   if(f==NULL)
   {
      fprintf(stderr, "Greska fopen(): Neuspelo otvaranje datoteke %s.\n", dat);
      exit(EXIT_FAILURE);
   }

   if (ucitaj_podatke(f,kola,&dim_kola,MAXA)==0)
   {
      fprintf(stderr, "Greska pri ucitavanju podataka\n");
      exit(EXIT_FAILURE);
   }

   
   informacije_o_markama(kola, dim_kola, infos, &dim_infos);

   stampaj_informacije(infos,dim_infos);
   
   stampaj_kandidate(kola, dim_kola, granica, infos, dim_infos);   
   
   fclose(f);  
   return 0;
}

