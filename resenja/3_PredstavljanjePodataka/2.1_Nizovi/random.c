#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>


int main()
{
  int i;
  srand(time(NULL));

  for (i = 0; i < 30; i++)
    printf("%d ", rand() % 350);

  exit(EXIT_SUCCESS);
}
