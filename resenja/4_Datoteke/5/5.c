/* Program se pokrece tako sto se navedu nazivi dve datoteke(ulazna i izlazna) i opcije. 
   U datoteci cije se ime navodi kao prvi argument komandne linije nalaze se podaci o razlomcima: 
   u prvom redu se nalazi broj razlomaka, a u svakom sledecem redu brojilac i imenilac jednog razlomka. 
   Potrebno je kreirati strukturu koja opisuje razlomak i ucitati niz razlomaka
   iz datoteke, a potom:
      a) ukoliko je navedena opcija x, upisati u datoteku cije je ime drugi argument komandne linije 
         reciprocni razlomak za svaki razlomak iz niza (npr. za 2/3 treba upisati 3/2)
      b) ukoliko je navedena opcija y, upisati u datoteku cije je ime drugi argument komandne linije 
         realnu vrednost reciprocnog razlomka svakog razlomka iz niza (npr. za 2/3 treba upisati 1.5)  
   Mozemo pretpostaviti da se u datoteci sa podacima o razlomcima nalazi najvise 100 razlomaka.
*/

/*
  Prilikom pokretanja programa se, pored naziva ulazne i izlazne
  datoteke, navode i opcije -x i -y. Moguce je navesti jednu ili
  obe opcije, sto znaci da je minimalni broj argumenata 3. 
  
  Moguci nacini pokretanja:
  ./a.out ulaz.txt izlaz.txt -x
  ./a.out ulaz.txt izlaz.txt -y
  ./a.out ulaz.txt izlaz.txt -yx
  ./a.out ulaz.txt izlaz.txt -xy
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define MAX 100

typedef struct razlomak
{
  int br;
  int im;
} RAZLOMAK;

/*
   Funkcija ucitaj_razlomke ucitava razlomke iz datoteke
   na koju pokazuje f u niz. Dimenzija niza, na koju 
   pokazuje pokazivac dim, nije poznata. Prva vrednost
   u datoteci je ukupan broj razlomaka i tu vrednost
   ucitavamo u promenljivu dim.
   
   Funkcija fscanf se koristi isto kao i funkcija scanf
   uz dodatni prvi argument koji predstavlja naziv
   datoteke iz koje se vrsi ucitavanje.

*/
int ucitaj_razlomke(RAZLOMAK niz[], int* dim, FILE* f)
{
   int i;

   fscanf(f,"%d", dim);
   for (i=0; i<*dim; i++)   
   {
      fscanf(f,"%d %d", &niz[i].br, &niz[i].im);
      if (niz[i].im==0)
         return 0;
   }
   return 1;
}

RAZLOMAK reciprocni(RAZLOMAK* r)
{
   RAZLOMAK rec;
   rec.im = r->br;
   rec.br = r->im;
   return rec;
}

float vrednost(RAZLOMAK* r)
{
   return 1.0*r->br/r->im;
}

int main(int argc, char* argv[])
{
   FILE *in, *out;
   char c;
   int i; 
   int j;
   int xoption=0;
   int yoption=0;
   int dim;
   RAZLOMAK razlomci[MAX];
   RAZLOMAK r;
   
   /*
      Prilikom pokretanja programa se, pored naziva ulazne i izlazne
      datoteke, navode i opcije -x i -y. Moguce je navesti jednu ili
      obe opcije, sto znaci da je minimalni broj argumenata 3. 
      
      Moguci nacini pokretanja:
      ./a.out ulaz.txt izlaz.txt -x
      ./a.out ulaz.txt izlaz.txt -y
      ./a.out ulaz.txt izlaz.txt -yx
      ./a.out ulaz.txt izlaz.txt -xy
      
   */
    
   if(argc!=4)
   {
      fprintf(stderr,"Greska: program se pokrece sa: %s ime_ulazne_datoteke ime_izlazne_datoteke [ -x | -y]\n", argv[0]);
      exit(EXIT_FAILURE);            
   } 
            
            
   in= fopen(argv[1],"r");
   if(in==NULL)
   {
      fprintf(stderr, "Greska fopen(): Neuspelo otvaranje datoteke %s.\n", argv[1] );
      exit(EXIT_FAILURE);         
   }  
                 
   out= fopen(argv[2],"w");
   if(out==NULL)
   {
      fprintf(stderr, "Greska fopen(): Neuspelo otvaranje datoteke %s.\n", argv[2] );
      exit(EXIT_FAILURE);
   }
                 
   /* Ispitujemo da li je treca opcija u trazenom formatu. Prvi karakter mora biti '-'.*/
   
   if (argv[3][0] != '-')
   {
      fprintf(stderr, "Greska u zadavanju opcija: program se pokrece sa: %s ime_ulazne_datoteke ime_izlazne_datoteke [ -x | -y]\n", argv[0]);
      exit(EXIT_FAILURE);
   }  
   
   /* Ostali karakteri mogu biti 'x' ili 'y'. U zavisnosti od date opcije, postavljamo
      vrednosti indikatorskih promenljivih xoption i yoption. */
      
   for(j=1;argv[3][j]!='\0';j++)
       switch(argv[3][j])
       {
          case 'x': xoption=1;
                    break;
          case 'y': yoption=1;
                    break;
          default: 
                    fprintf(stderr, "Greska: nedozvoljeni karakter\n" );
                    exit(EXIT_FAILURE);   
       }


    if(ucitaj_razlomke(razlomci, &dim, in)==0)
    {
       fprintf(stderr, "Greska pri zadavanju razlomaka\n");
       exit(EXIT_FAILURE);
    }

    /*
       U zavisnosti od datih opcija, vrsimo upis reciprocnih 
       razlomaka u trazenom formatu.
       
       Funkcija fprintf se koristi na isti nacin kao
       funkcija printf uz dodatni prvi argument koji
       oznacava naziv datoteke u koju se vrsi upis.
    */
    for (i=0; i<dim;i++)       
    {
       /*
          Ukoliko je brojilac razlomka jednak nuli,
          nema smisla traziti njegovu reciprocnu vrednost
       */
       if (razlomci[i].br==0)
          continue;
          
       r = reciprocni(&razlomci[i]);
       
       if (xoption)
          fprintf(out,"%d/%d ", r.br, r.im);

       if (yoption)
          fprintf(out, "%f ", vrednost(&r));

       fprintf(out,"\n");
    }

    fclose(in);
    fclose(out);
    
    return 0;    
}
