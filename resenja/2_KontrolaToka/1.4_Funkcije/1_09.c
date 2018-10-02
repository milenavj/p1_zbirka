#include<stdio.h>
#include<stdlib.h>

/* Funkcija ispituje da li se cifra c nalazi u zapisu celog broja x. */
int sadrzi(int x, int c)
{
   char cifra;
   /* Posmatra se pozitivna vrednost broja. */
   x=abs(x);

   while(x)
   {
	   /* Odredjuje se poslednja cifra broja. */
      cifra = x%10;
      /* Proverava se da li je poslednja cifra jednaka trazenoj cifri i ako jeste prekida se izvrsavanje funkcije i vraca se 1, kao oznaka da je broj nadjen. */
      if (cifra==c)
         return 1;
      /* Inace, broj se umanjuje za poslednju cifru i prelazi se na sledecu iteraciju. */
      x/=10;
   }
   /* Ukoliko se cifra ne nalazi u broju uslov u petlji nikad nece biti ispunjen. */
   return 0;
}
int main()
{
  int x;
  int c;
  printf("Unesi jedan ceo broj i jednu cifru:");
  scanf("%d%d",&x,&c);
  if (sadrzi(x,c))
     printf("Cifra %d se nalazi u zapisu broja %d\n",c,x);
  else
     printf("Cifra %d se ne nalazi u zapisu broja %d\n",c,x);  
  return 0;
}
