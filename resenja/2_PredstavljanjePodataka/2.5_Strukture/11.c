#include <stdio.h>
#include <stdlib.h>

#define MAXST 2000
#define MAX 31

typedef struct Student
{
  char ime[MAX];
  char prezime[MAX];
  char smer;
  float prosek;
} STUDENT;

void provera(char smer)
{
	if (smer != 'R' && smer != 'I' && smer != 'V' && smer != 'N' && smer != 'T' && smer != 'O')
	{
		printf("Nekorektan smer.\n");
		exit(EXIT_FAILURE);
	}
}

void ucitaj(STUDENT* s)
{
  scanf("%s",s->ime);

  scanf("%s",s->prezime);

  getchar();
  scanf("%c",&s->smer);

  scanf("%f", &s->prosek);
}

/* II */
/*
  Kada neku promenljivu prenosimo u funkciju kao argument, obicno
  je prenosimo po vrednosti (bez pokazivaca), ako se ona nece menjati u funkciji
  ili po adresi (preko pokazivaca), ako ce se njena vrednost promeniti u funkciji.
  
  Prilikom poziva funkcije, za svaki argument funkcije kreira se promenljiva
  koja predstavlja lokalnu kopiju argumenta i koja prestaje da postoji po zavrsetku
  funkcije. S obzirom da se strukuture sastoje od vise polja, zauzimaju
  vise memorije nego nestrukturne promenljive. Zbog toga je za njihovo kopiranje 
  potrebno vise vremena i vise memorijskih resursa nego za kopiranje nestrukturnih
  promenljivih. 
  
  Da bismo ucinili program efikasnijim, korisno je da strukturu uvek kao
  argument funkcije prenosimo po adresi (preko pokazivaca), bez obzira
  da li ce se struktura u toj funkciji menjati ili ne. Pokazivac na strukturu
  zauzima manje memorije nego sama struktura pa je izrada njegove kopije
  brza a kopija pokazivaca uzima manji memorijski prostor nego kopija
  strukture. 
  
  Kada prenosimo strukturnu promenljivu u funkciju po adresi (preko pokazivaca), tada 
  imamo mogucnost da je u funkciji menjamo. Ukoliko zelimo da onemogucimo promenu,
  uz argument dodajemo kljucnu rec const. Ako pokusamo da promenimo argument
  funkcije prenesen kao const (npr u funkciji ispisi navedemo naredbu s->smer='X';), 
  kompajler ce prijaviti gresku. Na ovaj nacin obezbedjujemo da promenljiva
  koju smo preneli po adresi ne da bismo je promenili vec radi povecanja 
  efikasnosti programa, ne bude, cak ni slucajno, izmenjena u funkciji.
      
*/

void ispisi(const STUDENT* s)
{
  printf("%s %s, %c, %.2f\n",s->ime, s->prezime, s->smer, s->prosek);
}


float najveci_prosek(STUDENT studenti[], int n)
{
  float m;
  int i;

  m = studenti[0].prosek;
  for(i=1;i<n;i++)
    if(m<studenti[i].prosek) 
       m=studenti[i].prosek; 
  return m;
}

/*
   Struktura moze da bude povratna vrednost funkcije. 
*/
STUDENT prvi_student_sa_najvecim_prosekom(STUDENT studenti[], int n, float m)
{
  STUDENT s;
  int i;
  for(i=0;i<n;i++)
    if(m == studenti[i].prosek) 
    {
       /* 
         Na strukture se moze primenjivati 
         naredba dodele.
       */
       s = studenti[i];
       break;
    }
  return s;
}


int main()
{
  STUDENT studenti[MAXST];
  int n;
  int i;
  float max_prosek;
  STUDENT student_sa_max_prosekom;
  int indeks;
	char smer;    

  printf("Uneti broj studenata: ");
  scanf("%d", &n);
  
  if (n<0 || n>MAXST)
  {
     printf("Nekorektan unos\n");
     return -1;
  }
  
	printf("Uneti podatke o studentima:\n");
  for(i=0;i<n;i++)
  {
		printf("%d. student: ", i); 
    ucitaj(&studenti[i]);
		provera(studenti[i].smer);
  }

	printf("Uneti smer: ");
	getchar();
	scanf("%c", &smer);

	provera(smer);

  printf("Studenti sa R smera:\n");
  for(i=0;i<n;i++)
     if(studenti[i].smer == smer) 
        printf("%s %s\n",studenti[i].ime, studenti[i].prezime);
  printf("---------------------\n");

  
  /* Stampamo podatke o svim studentima sa 
     maksimalnim prosekom.
  */
  
  max_prosek = najveci_prosek(studenti, n);
  printf("Svi studenti koji imaju maksimalni prosek:\n");  
  for(i=0;i<n;i++)
     if(studenti[i].prosek == max_prosek)
        ispisi(&studenti[i]);


  return 0;  
}
