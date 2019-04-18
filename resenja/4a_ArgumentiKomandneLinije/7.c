#include <stdio.h>

int main(int argc, char* argv[])
{
  /* Deklaracije potrebnih promenljivih. */
  int i, j, indikator = 0;
  
  /* Prolazi se kroz sve argumente komandne linije. */
  for(i=1; i < argc; i++)
  {
    /* Ukoliko argument pocinje karakterom '-', znaci da se navode
       opcije. */
    if(argv[i][0] == '-')
    {
      /* Ukoliko je u pitanju prvi niz opcija, ispisuje se
         odgovarajuca poruka i indikator se postavlja na 1. */
      if(!indikator)
      {
        printf("Opcije su: ");
        indikator = 1;
      }
      
      /* Ispisuju se sve opcije, tj. svi karakteri argumenta argv[i]
         koji se nalaze nakon '-'. */
      for(j=1; argv[i][j]; j++)
        printf("%c ", argv[i][j]);
    }
  }
  
  /* Ukoliko indikator nakon petlje ima vrednost 0, znaci da nije
     navedena nijedna opcija. */
  if(!indikator)
    printf("Medju argumentima nema opcija.\n");
  else
    printf("\n");

  return 0;
}
