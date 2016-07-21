#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

  int i;
  int br = 0;

  /* Da bismo proverili da li se karakter 'z' (tj. 'Z')
	 nalazi u niski argv[i],
	 to mozemo uciniti koriscenjem funkcije
	 strchr() koja se nalazi u string.h.
	 
	 Ukoliko je karakter sadrzan u okviru niske,
	 strchr() vraca pokazivac na taj karakter
	 unutar same niske.
	 Inace, ukoliko se karakter ne nalazi u niski,
	 funkcija vraca NULL.
	*/
  
  for(i = 1; i < argc; i++)
    if(strchr(argv[i], 'z') != NULL || strchr(argv[i], 'Z') != NULL)
      br++;

  printf("%d\n", br);

  return 0;
}
