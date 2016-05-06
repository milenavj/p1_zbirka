/* 
    Napisati program koji ispisuje broj navedenih argumenata komandne linije,
    a zatim i same argumenate i njihove redne brojeve. 
*/

#include <stdio.h>

/* 
   Argumenti komandne linije cuvaju se u nizu niski pod nazivom
   argv. Svaki element tog niza odgovara jednom argumentu komandne
   linije pri cemu prvi element predstavlja naziv programa koji
   pokrecemo. Celobrojna promenljiva argc predstavlja ukupan
   broj argumenata komandne linije ukljucujuci i argument koji 
   odgovara nazivu programa.
*/

int main(int argc, char *argv[])
{
   int i;

   printf("Broj argumenata je: %d\n",argc);
	
   for(i=0; i<argc; i++)
      printf("%d: %s\n",i,argv[i]);
	
   return 0;
}