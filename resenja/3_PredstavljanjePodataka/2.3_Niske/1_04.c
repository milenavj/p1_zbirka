/*
   Napisati funkciju int ucitaj_liniju(char s[], int n)
   koja ucitava liniju maksimalne duzine n u string s
   i vraca duzinu ucitane linije. Linija moze da sadrzi
   blanko znakove ali ne moze da sadrzi \n ili EOF. 
   
   Napisati potom glavni program koji ucitava linije
   do EOF i ispisuje najduzu liniju i njenu duzinu. Ukoliko
   ima vise linija maksimalne duzine, ispisati prvu. Mozemo
   pretpostviti da svaka linija sadrzi najvise 80 karaktera,
   zajedno sa \n.
   
*/

#include<stdio.h>
#include<string.h>
#define MAX 81

/*
   Ukoliko zelimo da ucitamo string koji sadrzi beline
   (npr liniju teksta), ne mozemo koristiti funkciju
   scanf jer ona ucitava string do prvog blanko znaka.
   
   Zbog toga je neophodno napisati funkciju koja ucitava
   string karakter po karakter.
   
   Ova funkcija ne dopusta unosenje vise karaktera od
   unapred odredjene granice (argument n). 
   
   U standardnoj biblioteci stdio.h postoji definisana
   funkcija char *gets(char *s) koja ucitava karaktere
   dok se ne pojavi novi red ili EOF. Ova funkcija 
   dopusta unosenje vise karaktera nego sto string
   s sadrzi, sto moze dovesti do neocekivanog ponasanja
   programa.
   
   Pored funkcije gets, koja vrsi ucitavanje sa standardnog
   ulaza, u standardnoj biblioteci stdio.h postoji
   i ugradjena funkcija fgets koja vrsi ucitavanje iz
   datoteke. Nju cemo koristiti za nekoliko casova
   kada budemo radili datoteke. Prototim funkcije fgets je
   ovakav:       
   
   char *fgets(char *s, int size, FILE *stream);
   
   Argumenti funkcije fgets su:
   s - string u koji vrsimo ucitavanje
   size - maksimalna duzina unetog stringa
   stream - datoteka iz koje vrsimo ucitavanje
   
   Funkcija fgets, za razliku od funkcije gets, ne dopusta
   unos vise karaktera od date vrednosti size. Zbog toga
   je ona sigurnija nego funkcija gets. Funkciju fgets
   mozemo koristiti i za unos sa standardnog ulaza
   ukoliko kao treci argument navedemo stdin. 
      
*/
int ucitaj_liniju(char s[], int n)
{
  int i=0;
  int c;
  
  while((c=getchar())!='\n' && i<n-2 && c!=EOF)
  {
    s[i] = c;
    i++;
  }
  
  /* Ucitavamo najvise n-2 karaktera jer na kraju dodajemo jos 
     dva: '\n' i '\0' */
  
  s[i]='\n';    
  s[i+1]='\0';
  
  return i;
  
}

int main()
{
  char linija[MAX];
  char najduza_linija[MAX];
  int max_duzina=0;
  int duzina;
  
  /*
     Petlja se zavrsava ukoliko je promenljiva duzina
     jednaka nuli, sto cemo postici zadavanjem linije koja ne sadrzi
     nijedan karakter osim EOF.
  */
  
  while ((duzina=ucitaj_liniju(linija, MAX))>0)
  {
     /*
        Proveravamo da li je uneta linija duza od trenutnog
        maksimuma i azuriramo promenljive max_duzina i najduza_linija.
     */
     if (max_duzina<duzina)
     {
        max_duzina = duzina;
        strcpy(najduza_linija,linija);
     }
  }
  
  printf("Najduza linija: %s duzine: %d\n", najduza_linija, max_duzina);

  return 0;
}