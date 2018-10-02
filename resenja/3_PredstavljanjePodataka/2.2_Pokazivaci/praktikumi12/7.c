#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n,i;

  /*
    Ispisujemo gresku ukoliko nema dovoljno argumenata komandne linije.
  */
  if(argc != 2)
  {
    printf("Greska: nedostaje argument komandne linije!\n");
    return -1;
  }

  /*
    Pretvaramo argument komandne linije koji je string u ceo broj koriscenjem funkcije atoi
  */
  n = atoi(argv[1]);
  n = abs(n);

  for(i=(-1)*n;i<=n;i++)
    printf("%d ",i);

  return 0;
}
