#include <stdio.h>

int main(int argc, char* argv[]) {

  int i;

  /* Prolazimo for petljom kroz niz argumenata,
	 i trazimo one niske ciji je prvi karakter bas 'z'.
	 Ukoliko je trenutni argument koji se ispituje
	 argv[i],
	 kako je on sam po sebi niska,
	 do prvog karaktera dolazimo kao i pri dosadasnjem
	 radu sa niskama --> argv[i][0]
							     ^
								 |
								index prvog karaktera u niski argv[i]
	*/
  
  for(i = 1; i < argc; i++)
    if(argv[i][0] == 'z')
      printf("%s ", argv[i]);

  putchar('\n');

  return 0;
}