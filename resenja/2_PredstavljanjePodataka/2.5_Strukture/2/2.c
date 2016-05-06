/*
  Data je struktura
    typedef struct Student
    {
      char ime[MAX];
      char prezime[MAX];
      char smer;
      float prosek;
    } STUDENT;
  
I   Napisati funkciju koja ucitava sa standardnog ulaza podatke o studentu. Mozemo pretpostaviti da 
    ime i prezime studenta ne sadrze vise od 30 karaktera.
II  Napisati funkciju koja ispisuje podatke o studentu na standardni izlaz.
III Ucitati niz od n studenata i :
      a) ispisati imena i prezimena onih koji su na smeru R
      b) ispisati podatke za studenta sa najvecim prosekom; ako ima vise takvih studenata, ispisati 
         1) sve njih 
	 2) prvog 
	 3) poslednjeg 
*/

#include <stdio.h>
#define MAXST 100
#define MAX 31

typedef struct Student
{
  char ime[MAX];
  char prezime[MAX];
  char smer;
  float prosek;
} STUDENT;

/* 
   I 
   
   Ako je dat pokazivac na strukturnu promenljivu s,
   poljima ove strukture pristupamo sa
   (*s).ime,(*s).prezime, itd.
   
   Zagrade su neophodne zbog prioriteta operatora:
   operator * ima veci prioritet nego opetator . .
   
   Operator -> pruza skraceni zapis za prethodno
   navedeni pristup poljima:
   s->ime je skraceno za (*s).ime
   s->prezime je skraceno za (*s).prezime
   itd. 
   
*/
void ucitaj(STUDENT* s)
{
  /* printf("Ime:"); */
  scanf("%s",s->ime);
  /* printf("Prezime:"); */
  scanf("%s",s->prezime);
  getchar();
  /* printf("Smer:"); */
  scanf("%c",&s->smer);
  /* printf("Prosek:");*/
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
  koju smo preneli po adresi ne da bismo je promenili vec radi povecanja efikasnosti programa, 
  ne bude, cak ni slucajno, izmenjena u funkciji.
      
*/

void ispisi(const STUDENT* s)
{
  printf("%s %s, %c, %.2f\n",s->ime, s->prezime, s->smer, s->prosek);
}


float najveci_prosek(STUDENT studenti[], int n)
{
  float m;
  int i;
  /* Pretpostavimo da student sa indeksom 0 ima 
     maksimalni prosek. */
  m = studenti[0].prosek;
  for(i=1;i<n;i++)
    if(m<studenti[i].prosek) /* Ako student sa indeksom i ima veci prosek od maksimalnog, */
       m=studenti[i].prosek; /* menjamo maksimalni prosek */ 
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
    if(m==studenti[i].prosek) /* Ako naidjemo na studenta sa maksimalnim prosekom, prekidamo petlju. */
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

/*
   Strukturu mozemo preneti u funkciju preko pokazivaca. Strukture se obavezno
   prenose preko pokazivaca ukoliko je neophodno promeniti vrednosti njihovih
   polja u funkciji.
*/
void poslednji_student_sa_najvecim_prosekom(STUDENT studenti[], int n, float m, STUDENT* s)
{
  int i;
  for(i=0;i<n;i++)
     if(m==studenti[i].prosek)
        *s = studenti[i];
}

/*
   Napomena: funkcije
      1)prvi_student_sa_najvecim_prosekom
      2)poslednji_student_sa_najvecim_prosekom
   odredjuju studenta sa najvecim prosekom po odredjenom kriterijumu.
   Funkcija su realizovane na razlicite nacine kako bi ilustrovale:
   - strukturu kao povratnu vrednost
   - prenos strukture preko pokazivaca u funkciju, s obzirom da ce se promeniti u funkciji
     
   Prilikom izrade zadataka moze biti izabran bilo koji od opisanih nacina rada, osim
   ako neki nacin nije posebno naglasen u tekstu zadatka.    

*/
int main()
{
  STUDENT studenti[MAXST];
  int n;
  int i;
  float max_prosek;
  STUDENT student_sa_max_prosekom;
  int indeks;
    

/*  printf("Unesi broj studenata:"); */
  scanf("%d", &n);
  
  if (n<0 || n>MAXST)
  {
     printf("Nekorektan unos\n");
     return -1;
  }
  
/*  printf("Unesi podatke o studentima:"); */
  for(i=0;i<n;i++)
  {
/*    printf("%d. student:\n", i); */
    ucitaj(&studenti[i]);
  }

  printf("Studenti sa R smera:\n");
  for(i=0;i<n;i++)
     if(studenti[i].smer == 'R') 
        ispisi(&studenti[i]);
  printf("---------------------\n");

  
  /* b)1)
     
     Stampamo podatke o svim studentima sa 
     maksimalnim prosekom.
  */
  
  max_prosek = najveci_prosek(studenti, n);
  printf("Svi studenti koji imaju maksimalni prosek:");  
  for(i=0;i<n;i++)
     if(studenti[i].prosek==max_prosek)
        ispisi(&studenti[i]);

  /* b)2) */    
  student_sa_max_prosekom = prvi_student_sa_najvecim_prosekom(studenti,n,max_prosek);
  
  printf("Prvi student u nizu sa najvecim prosekom: ");
  ispisi(&student_sa_max_prosekom);

  /* b)3) */
  poslednji_student_sa_najvecim_prosekom(studenti,n,max_prosek,&student_sa_max_prosekom);

  printf("Poslednji student u nizu sa najvecim prosekom: ");
  ispisi(&student_sa_max_prosekom);

  return 0;  
}