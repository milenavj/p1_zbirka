/*

Napisati program koji ucitava tri cela broja i ispisuje zbir onih unetih brojeva
koji su pozitivni.

*/
#include<stdio.h>
int main()
{
  int a,b,c;
  int s;
  printf("Unesi prvi ceo broj:");
  scanf("%d",&a);
  printf("Unesi drugi ceo broj:");
  scanf("%d",&b);
  printf("Unesi treci ceo broj:");
  scanf("%d",&c);

  s=0; /* inicijalizujemo promenljivu s na nulu */

  if (a>0)
     s=s+a; /* naredba dodele: vrednost izraza a desne strane znaka jednakosti 
               dodeljujemo promenljivoj sa leve strane znaka jednakosti.
               Staru vrednost promenljive s saberemo sa vrednoscu promenljive a
               i dobijenu vrednost upisemo u promenljivu s */

  if (b>0)
     s+=b; /* operator +=
               s+=b je skraceni zapis za s=s+b
           */

  if (c>0)
     s+=c;

  printf("Suma unetih pozitivnih brojeva: %d\n",s);
  return 0;
}