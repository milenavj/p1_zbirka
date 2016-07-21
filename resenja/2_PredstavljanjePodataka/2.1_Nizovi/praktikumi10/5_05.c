#include <stdio.h>

int main()
{
  char c;
  int cifrex[10], cifrey[10];
  int x, y, i, indikator;

  printf("Unesite dva broja: ");
  scanf("%d%d", &x, &y);

  /*
    Uzmemo apsolutnu vrednost brojeva za slucaj da su negativni.
  */
  x=abs(x);
  y=abs(y);

  /*
    Niz cifrex nam predstavlja brojace za cifre broja x, na pocetku ga inicijalizujemo na 0.
    Analogno za cifrey.
  */
  for(i=0;i<10;i++)
  {
      cifrex[i] = 0;
      cifrey[i] = 0;
  }

  /*
    Skidamo jednu po jednu cifru broja x i povecavamo njen brojac u nizu cifrex.
  */
  while(x)
  {
    c = x%10;
    cifrex[c]++;
    x /= 10;
  }

  /*
    Isto radimo i za broj y.
  */
  while(y)
  {
    c = y%10;
    cifrey[c]++;
    y /= 10;
  }

  /*
    Promenljiva koja nam sluzi za proveru da li su oba broja sastavljena od istih cifara.
    Pretpostavicemo da jesu i postaviti indikator na 1.
    Nakon toga u petlji prolazimo kroz nizove cifrex i cifrey u kojima se nalaze
    brojevi pojavljivanja svih cifri 0-9 u broju x i y, i prvi put kada naletimo na
    neku cifru koja se ne pojavljuje isti broj puta u oba broja x i y,
    postavljamo promenljivu indikator na 0 (brojevi x i y nisu zapisani sa istim ciframa)
    i izlazimo iz petlje.
  */
  indikator = 1;
  for(i=0;i<10;i++)
    if(cifrey[i] != cifrex[i])
    {
     indikator = 0;
     break;
    }

  /*
    Ako je promenljiva indikator ostala 1, to znaci da u petlji nismo pronasli cifru
    koja se ne pojavljuje isti broj puta u brojevima x i y, sto znaci da se oni zapisuju istim ciframa.
  */
  if(indikator)
    printf("Brojevi se zapisuju istim ciframa!\n");
  else
    printf("Brojevi se ne zapisuju istim ciframa!\n");

  return 0;
}
