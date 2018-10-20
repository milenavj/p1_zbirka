#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int an;
  
  /* Ucitava se vrednost prvog clana i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite prvi clan:");
  scanf("%d", &an);
  
  if (an <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }
 
  /* Dok se ne dodje do clana koji je 1, stampa se vrednost
     trenutnog clana i vrsi se izracunavanje narednog, po
     zadatoj formuli. */
  while (an != 1) {
    printf("%d ", an);

    if (an % 2 != 0)
      an = (3 * an + 1) / 2;
    else
      an = an / 2;
  }
  
  /* Na kraju se stampa i jedinica. */
  printf("1\n");
  
  return 0;
}
