/* Napisati program koji za unete duzine stranica trougla, ispisuje njegov obim
i povrsinu */

/* Napomena: prilikom prevodjenja programa treba navesti opciju -lm 
 * na primer, gcc trougao.c -lm 
 */

#include <stdio.h>
#include <math.h>

int main(){
  float a, b, c;
  float obim, s, povrsina;
  
  /* Ucitavamo potrebne podatke */
  printf("Unesite duzine stranica trougla: ");
  scanf("%f %f %f", &a, &b, &c);
  
  /* Obim */
  obim=a+b+c;
  
  /* Povrsina - koristicemo Heronov obrazac*/
  s=obim/2;
  povrsina=sqrt(s*(s-a)*(s-b)*(s-c));
  
  /* Ispisujemo trazene vrednosti */
  printf("Obim: %.2f\n", obim);
  printf("Povrsina: %.2f\n", povrsina);
  
  return 0;
}