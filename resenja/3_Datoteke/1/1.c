/* 
    Napisati program koji prepisuje sadrzaj datoteke ulaz.txt u  
    datoteku izlaz.txt karakter po karakter.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int c;
   FILE *ulaz, *izlaz;

   /*
      Promenljive ulaz i izlaz predstavljaju
      pokazivace na ugradjenu strukturu FILE. 
      Unutar ove strukture nalaze se polja neophodna
      za rad sa datotekama. 
      
      Kada zelimo da radimo sa nekom datotekom, 
      moramo je prvo otvoriti. Ugradjena funkcija
      fopen(dat, mode) otvara datoteku sa nazivom
      dat. Datoteka moze biti otvorena za citanje,
      pisanje ili nadovezivanje, sto odredjuje
      argument mode koji moze imati vrednost "r" (read),
      "w"(write) ili "a"(append). 
   */
   
   ulaz=fopen("ulaz.txt","r");
   
   /*
      Do neuspesnog otvaranja datoteke moze doci
      ukoliko ne postoji datoteka sa datim nazivom
      ili je putanja do datoteke pogresna. U tom
      slucaju, funkcija fopen vraca pokazivac na NULL
      i tada treba prijaviti gresku. Datoteka stderr
      predstavlja standardnu datoteku u koju se upisuju
      greske. Stderr je podrazumevano postavljen
      na standardni izlaz.
      
      Ugradjena funkcija exit prouzrokuje zavrsetak programa.
      Argument ove funkcije je jedna od konstanti definisanih 
      u biblioteci stdlib.h koje pokazuju da li se program 
      zavrsio uspesno (EXIT_SUCCESS) ili neuspesno (EXIT_FAILURE).
      
   */
   if(ulaz==NULL)
   {
      fprintf(stderr,"error fopen(): Neuspelo otvoranje datoteke ulaz.txt za citanje.\n");
      exit(EXIT_FAILURE);
   }
	
   izlaz= fopen("izlaz.txt", "w");
   if(izlaz==NULL)
   {
      fprintf(stderr,"error fopen():  Neuspelo otvoranje datoteke izlaz.txt za citanje.\n");
      exit(EXIT_FAILURE);
   }
	
   /*
      Funkcija fgetc ucitava jedan karakter iz datoteke ulaz.
      Povratna vrednost ove funkcije je ascii kod unetog 
      karaktera.      
      
      Funkcija fputc ispisuje karakter c u datoteku izlaz. 
   */	
   
   while((c=fgetc(ulaz))!=EOF)
      fputc(c,izlaz);

   /*
      Nakon zavrsetka rada sa datotekama, neophodno ih je
      zatvoriti pomocu ugradjene funkcije fclose. 
   */
   fclose(ulaz);
   fclose(izlaz); 
   return 0;
}
