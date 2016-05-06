/* Sa standardnog ulaza se ucitavaju dva cela broja i jedan od karaktera +, -,
*, / ili % koji predstavlja operaciju koju treba izvrsiti nad unetim brojevima.
Napisatiti program koji koriscenjem switch naredbe analizira o kom karakteru je
rec i na standardni izlaz ispisuje rezultat. U slucaju pogresnog unosa ispisati
odgovaraju ́u poruku. */

#include <stdio.h>

int main(){
 
  char op;
  int x, y;

  printf("Unesite operator i dva cela broja: ");
  scanf("%c %d %d", &op, &x, &y);
  
  switch(op){
    case '+':
      printf("Rezultat je: %d\n", x+y);
      break;
    case '-':
      printf("Rezultat je: %d\n", x-y);
      break;
    case '*':
      printf("Rezultat je: %d\n", x*y);
      break;
    case '/':
      if(y==0)
        printf("Greska: deljenje nulom nije dozvoljeno!\n");
      else
        printf("Rezultat je: %f\n", x*1.0/y);
      break;
    case '%':
      printf("Rezultat je: %d\n", x%y);
      break;
    default: 
      printf("Greska: nepoznat operator!\n");
  }

  return 0;
}