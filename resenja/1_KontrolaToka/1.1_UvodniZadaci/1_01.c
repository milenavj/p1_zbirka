/*
Napisati program koji na standardni izlaz ispisuje tekst "Zdravo svete!"
*/
#include<stdio.h>

int main()
{
  /* printf - funkcija pomocu koje se vrsi ispis */
  /* oznaka \n : prelazak u novi red */
  printf("Zdravo svete!\n");

  /* naredne dve naredbe ispisace reci Zdravo i svete u istom redu*/
  printf("Zdravo ");
  printf("svete \n");

  /* naredne dve naredbe ispisace reci Zdravo i svete u posebnim redovima */
  /* jer se u prvoj printf naredbi na kraju oznakom \n prelazi u novi red */

  printf("Zdravo \n");
  printf("svete \n");

  return 0;
}