#include <stdio.h>

int main(int argc, char *argv[])
{
  /* Deklaracija potrebnih promenljivih. */
  int i, indikator = 0;

  /* Ispisuju se svi argumenti komandne linije ciji
     je prvi karakter znak '@'. 
     Ako se program pokrene sa ./a.out @pera mika @zika
     argv[0] je ./a.out i on se preskace.
     argv[1] je @pera, a prvi karakter je onda argv[1][0].
     Dakle, za argv[i] treba proveravati da li je
     argv[i][0] jednak karakteru '@'. */
  for (i = 1; i < argc; i++)
  {
    if (argv[i][0] == '@')
    {
      /* Promenljiva indikator sluzi da detektuje da li postoji 
         bar jedna niska koja pocinje sa @. Ukoliko se naidje na
         prvu takvu nisku, ispisuje se trazena poruka i indikator
         se postavlja na 1.*/
      if(!indikator)
      {
        printf("Argumenti koji pocinju sa @:\n");
        indikator = 1;
      }
      printf("%s ", argv[i]);
    }
  }

  /* Ukoliko je indikator i dalje 0, znaci da nijedan argument ne
     pocinje karakterom @. */
  if(!indikator)
    printf("Nema argumenata koji pocinju sa @.");
  printf("\n");
  
  return 0;
}
