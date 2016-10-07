/*
   Navedeni program definise funkciju koja se zove main. 
   Program moze da definise vise funkcija, 
   ali obavezno mora da definise funkciju koja se zove main i 
   izvrsavanje programa uvek pocinje od te funkcije. Pored naziva, 
   zapis svake funkcije cine i povratna vrednost funkcije (u ovom 
   slucaju int), lista argumenata koje funkcija koristi (u ovom 
   slucaju funkcija nema argumenata pa se navode samo prazne 
   zagrade, ()) i telo funkcije koje je ograniceno 
   viticastim zagradama ({ i }). O ovim pojmovima bice vise reci 
   u narednim poglavljima.

   Unutar tela funkcije navode se naredbe. Unutar navedenog programa 
   postoji jedna naredba koja predstavlja poziv funkcije printf. 
   Funkcija printf sluzi za ispis teksta na standardni izlaz (obicno 
   ekran). Deklaracija ove funkcije data je u zaglavlju stdio.h
   koje je potrebno ukljuciti direktivom #include na pocetku
   samog programa.
   
   Da bismo pokrenuli program, prvo ga moramo prevesti u izvrsnu 
   datoteku. Na primer, ako je navedeni program sacuvan kao zdravo.c, 
   ako koristimo gcc kompajler koji je sastavni deo standardnih Linux
   distribucija, prevodjenje iz komandne linije se vrsi narednom naredbom:
      gcc zdravo.c
   Ukoliko nije bilo gresaka prilikom prevodjenja, bice generisana 
   izvrsna datoteka pod nazivom a.out koja se pokrece navodjenjem 
   sledece naredbe:
     ./a.out
   Ukoliko je bilo gresaka prilikom prevodjenja, one se moraju 
   otkloniti a postupak prevodjenja se mora ponoviti. 
*/
#include<stdio.h>

int main()
{
  /* printf: funkcija pomocu koje se vrsi ispis */
  /* Specijalni karakter \n : prelazak u novi red */
  /* Svaka naredba zavrsava se karakterom ; */
  printf("Zdravo svete!\n");

  /* Povratna vrednost 0 se obicno koristi da oznaci
     da je prilikom izvrsavanja programa sve proslo 
     u redu. */
  return 0; 
}
