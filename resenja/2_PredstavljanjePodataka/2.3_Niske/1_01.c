/*
   Napisati funkciju koja konvertuje dati string tako sto 
   mala slova menja u velika a velika u mala. Napisati 
   potom glavni program koji ucitava string, poziva napisanu 
   funkciju i ispisuje konvertovani string. Mozemo pretpostaviti
   da string ne sadrzi vise od 10 karaktera.
*/

#include <stdio.h>
#include <ctype.h>

/*
   Kada je niz argument funkcije, dodatni argument je obavezno
   njegova dimenzija. Kod stringova to nije slucaj jer svaki string
   ima isti poslednji element - terminirajucu nulu - i to je oznaka
   kraja stringa. 
*/
void konvertuj(char s[])
{
   int i;
   
   for(i=0; s[i]!='\0'; i++)
      if (s[i]>='a' && s[i]<='z')
         s[i] = toupper(s[i]);  /* toupper - konvertuje malo slovo u odgovarajuce veliko */
      else if (s[i]>='A' && s[i]<='Z')
         s[i] = tolower(s[i]);  /* tolower - konvertuje veliko slovo u odgovarajuce malo */
   /*
      Funkcije toupper i tolower se nalaze u zaglavlju ctype.h.
      
      Konverzija malog slova u veliko bez upotrebe funkcije toupper:
          s[i] = s[i]-'a'+'A';
      Konverzija velikog slova u malo bez upotrebe funkcije tolower:
          s[i] = s[i]+'a'-'A';
      
   */
}    

int main()
{
   /*
      Poslednji karakter svakog stringa je terminirajuca
      nula '\0', specijalni karakter ciji je ASCII kod 0.
      
      Ukoliko pretpostavljamo da string sadrzi najvise 30
      karaktera, neophodno je deklarisati niz od 31 karaktera,
      pri cemu se dodatni izdvaja za terminirajucu nulu.
      
   */
   char s[31];
   printf("Unesi string:");
   
   /*
      Za razliku od nizova koji se ucitavaju i stampaju
      element po element, stringovi se mogu ucitati i
      odstampati pomocu jedne scanf/printf naredbe koriscenjem
      specifikatora %s.
      
      Funkcija scanf ucitava string do prvog pojavljivanja razmaka.
   */
   scanf("%s", s); 
   
   konvertuj(s);
   
   printf("Konvertovani string: %s\n", s);
   
   return 0;
      
}