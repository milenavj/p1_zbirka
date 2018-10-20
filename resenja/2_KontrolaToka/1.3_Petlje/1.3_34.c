#include <stdio.h>

int main()
{
  char c;
  
  /* I nacin ucitavanja: 
     U samom uslovu petlje se vrsi ucitavanje jednog karaktera, 
     njegovo smestanje u promenljivu c i provera da li je ucitani
     karakter tacka. Zagrade oko (c=getchar()) su obavezne jer
     relacioni operator != ima veci prioritet od dodele i kada ne
     bi postojale zagrade, redosled operacija bi bio:
     (c = (getchar() != '.')), sto znaci da bi se u c smestio 
     rezultat poredjenja, odnosno 0 ili 1. */
  while ((c = getchar()) != '.') {
    /* Proveravaju se uslovi i vrsi se ispis odgovarajuceg
       karaktera.*/
    if (c >= 'A' && c <= 'Z')
      putchar(c + 'a' - 'A');
    else if (c >= 'a' && c <= 'z')
      putchar(c - 'a' + 'A');
    else
      putchar(c);
  }
  
  /*II nacin:
  while(1) {
    c = getchar();
    if(c == '.')
      break;
    
    if (c >= 'A' && c <= 'Z')
      putchar(c + 'a' - 'A');
    else if (c >= 'a' && c <= 'z')
      putchar(c - 'a' + 'A');
    else
      putchar(c);
  }
  */

  return 0;
}
