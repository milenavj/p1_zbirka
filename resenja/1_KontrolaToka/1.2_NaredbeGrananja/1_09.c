
#include<stdio.h>

int main()
{
  int a,b,c;
  int s;
  printf("Unesite tri cela broja:");
  scanf("%d%d%d",&a,&b,&c);

  /* inicijalizujemo promenljivu s na nulu */
  s=0; 

  /* 
     U naredbi dodele s=s+a vrednost izraza sa desne strane 
     znaka jednakosti dodeljujemo promenljivoj sa leve 
     strane znaka jednakosti. Staru vrednost promenljive s 
     saberemo sa vrednoscu promenljive a i dobijenu vrednost 
     upisemo u promenljivu s.     
  */
  
  if (a>0)
     s=s+a; 

  /* s+=b je skraceni zapis za s=s+b */
  
  if (b>0)
     s+=b; 

  if (c>0)
     s+=c;

  printf("Suma unetih pozitivnih brojeva: %d\n",s);
  return 0;
}