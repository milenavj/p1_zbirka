/*
  Napisati program koji racuna skalarni proizvod dva vektora. Svaki vektor
  je zadat kao celobrojni niz sa najvise 100 elemenata. Program treba da
  ucita dimenziju nizova (oba niza su iste dimenzije), zatim jedan po
  jedan element niza i da ispise njihov skalarni proizvod na standardni
  izlaz.  
*/

#include <stdio.h>
#define MAX 100

/*

Pretprocesorskom direktivom define uvode se simbolicka imena (u ovom slucaju
MAX) kojima se pridruzuje nekakav tekst (u ovom slucaju 100). Pre kompilacije,
sva pojavljivanja simbolickog imena MAX bice zamenjena pridruzenim tekstom
100. MAX nije promenljiva i za nju se tokom izvrsavanja programa ne izdvaja
memorijski prostor. 

MAX se u ovom zadatku koristi kao maksimalni broj elemenata niza. Ukoliko bismo zeleli
da izmenimo ovu vrednost, npr. da povecamo sa 100 na 200, sve 
sto bi bilo neophodno uraditi je da izmenimo tekst sa 100 na 200. Sa druge
strane, da nismo koristili pretprocesorsku direktivu i da smo svaki put
umesto MAX direktno navodili vrednost 100, morali bismo da je izmenimo na svakom
mestu u kodu. 

*/
int main()
{
  int a[MAX];
  int b[MAX];
  int n;
  int i;
  int s;

  
  printf("Unesi dimenziju niza:");
  scanf("%d", &n);

  if (n<1 || n>100)  
  {
    printf("Neispravan unos\n");
    return -1;
  }
       
  /* 
     prvi element niza ima indeks 0, a poslednji n-1,
     gde je n broj elemenata niza; elementima niza pristupamo 
     preko indeksa; na primer, ako niz a ima 5 elemenata, mozemo 
     im pristupiti pomocu
     a[0], a[1], a[2], a[3], a[4]     
  
  */
    
  for (i=0; i<n; i++)
  {
    printf("a[%d]=",i);
    scanf("%d", &a[i]);
  }
  
  for (i=0; i<n; i++)
  {
    printf("b[%d]=",i);
    scanf("%d", &b[i]);
  }
  
  s=0;

  for (i=0; i<n; i++)
    s = s + a[i]*b[i];
  
  printf("Skalarni proizvod: %d\n",s);     
  return 0;
}