#include <stdio.h>

#define MAX 100

int main()
{
  char karakteri[MAX];
  char c;
  int i, n;


  for(i=0;i<MAX;i++)
  {
    /*
      Ucitavamo karakter po karakter dok ne unesemo * ili ne prekoracimo 100 karaktera
      i upisujemo ih u niz.
    */
    printf("Unesite karakter: ");
    scanf("%c", &c);

    /*
      Citamo belinu nakon unesenog karaktera.
    */
    getchar();

    /*
      Ukoliko smo uneli * izlazimo iz petlje
    */
    if(c == '*')
      break;

    /*
      Stavljamo karakter u niz.
    */
    karakteri[i] = c;
  }

  /*
    Broj unetih karaktera je nakon prolaska kroz petlju i-1.
  */
  n = i-1;

  /*
    Ispisujemo karaktere u obrnutom redosledu.
  */
  for(i=n;i>=0;i--)
  {
    printf("%c ", karakteri[i]);
  }
  printf("\n");

  return 0;
}
