/*
   Napisati program koji ucitava string src i formira string dst
   trostrukim nadovezivanjem stringa src. Program treba da ispise
   string dst. Na primer, za uneti string "dan", string dst treba
   da bude "dandandan". Pretpostaviti da string src nije duzi od
   30 karaktera.
*/

#include <stdio.h>
#include <string.h>

#define MAX 30
/*
    Na stringove ne mozemo primeniti naredbu dodele.
    Ukoliko zelimo da jedan string "dodelimo" drugom,
    mozemo koristiti ugradjenu funkciju strcpy(s,t)
    koja kopira karaktere stringa t
    u string s zajedno za terminirajucom nulom.
    
    Funkcija strcpy se nalazi u biblioteci string.h.

    Funkcija strcpy_klon predstavlja jednu
    implementaciju funkcije strcpy.

    Karakteri stringa original se, jedan po jedan,
    kopiraju u string kopija. Nakon kopiranja,
    na kraj stringa kopija dodaje se terminalna
    nula.
    
    U zadacima cemo uvek koristiti ugradjenu
    funkciju strcpy osim ako u tekstu zadatka
    nije naglaseno da se ona ne sme koristiti. 
    Funkcija strcpy_klon sluzi da pokaze na koji
    nacin radi ugradjena funkcija strcpy.
    
    Ugradjena funkcija strcpy poziva se na 
    isti nacin kao funkcija strcpy_klon:
    strcpy(dst,src)
    gde karaktere stringa src kopiramo
    u string dst.
    
    
*/
void strcpy_klon(char kopija[], char original[])
{
  int i;
  for(i=0; original[i]; i++)
    kopija[i]=original[i];
    
  kopija[i] = '\0';
}

int main()
{
  char src[MAX+1];   /* src, skraceno od source (izvor, odnosno sta kopiramo) */
  char dst[3*MAX+1];   /* dst, skraceno od destination (odrediste, odnosno gde kopiramo) */
  
  /*
     Vazno je izdvojiti dovoljno memorijskog prostora
     za string dst: on treba da bude tri puta veci od
     maksimalne duzine stringa src + jedan karakter za 
     terminirajucu nulu.
  */
  
  printf("Unesi jedan string:");
  scanf("%s", src);
  
  strcpy_klon(dst,src); 

  /*
    Funkcija strcat(s,t) nadovezuje karaktere stringa
    t na kraj stringa s i novi string terminira 
    karakterom '\0' .
    
    Funkcija strcat se nalazi u biblioteci string.h.
  */
  strcat(dst,src);
  strcat(dst,src);

  printf("Kada nadovezemo string %s triput: %s\n",src,dst);
 
  return 0;
}
