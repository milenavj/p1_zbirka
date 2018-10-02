/*
   Napisati funkciju skrati koja uklanja beline sa
   kraja datog stringa. 
   
   Napisati glavni program koji testira napisanu
   funkciju na stringu "rep belina                           ".
   
*/

#include <stdio.h>
#include <ctype.h>

/*
    Funkcija koja racuna duzinu niza
    ne racunajuci '\0'.
   
    U biblioteci string.h definisan je veliki
    broj funkcija za rad sa stringovima, 
    ukljucujuci i funkciju strlen koja racunana 
    duzinu stringa.
   
    Funkcija strlen_klon predstavlja jednu
    implementaciju funkcije strlen.

    U zadacima cemo uvek koristiti ugradjenu
    funkciju strlen osim ako u tekstu zadatka
    nije naglaseno da se ona ne sme koristiti. 
    Funkcija strlen_klon sluzi da pokaze na koji
    nacin radi ugradjena funkcija strlen.
    
    Ugradjena funkcija strlen poziva se na 
    isti nacin kao funkcija strlen_klon:   
    strlen(s1)

*/
int strlen_klon(char s[])
{
  int i=0;
  while(s[i]) /* ASCII kod karaktera '\0' je jednak nuli. */
     i++;
     
  return i;
}

void skrati(char s[])
{
  /*
     Poslednji karakter stringa s(ne racunajuci '\0') ima
     indeks strlen_klon(s)-1; ideja je da pocnemo od poslednjeg
     karaktera stringa i da smanjujemo indeks dokle god
     je karakter na poziciji i blanko znak.
     
  */
  int i;
  for(i=strlen_klon(s)-1;i>=0;i--)
      if (!isspace (s[i])) /* Ako s[i] nije blanko znak, prekidamo petlju. */
         break;
         
  s[i+1]='\0';  /* DOdajemo terminirajucu nulu iza indeksa i (prvi neblanko karakter gledano sdesna nalevo).*/
  
  /*
     Ugradjena funkcija isspace nalazi se u biblioteci ctype.h i vraca 1 ako
     je dati karakter blanko znak a 0 u suprotnom.
     
     Unarni logicki operator ! oznacava negaciju.
     
  */
}

int main()
{

  /*
     Ukoliko string ne zelimo da ucitavamo po pokretanju programa
     vec da ga unapred zadamo, to mozemo uraditi na sledeci nacin:
  */
  char s[]="rep belina                           ";
  /* U ovom slucaju nije neophodno navoditi dimenziju stringa vec 
     ce ona biti automatski postavljena na broj karaktera u stringu + 1 za
     terminirajucu nulu. */


  printf("Pre skracivanja: *%s*\n", s);   
  skrati(s);
  printf("Posle skracivanja: *%s*\n", s);   
  
  return 0;
}