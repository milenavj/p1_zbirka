/* Napisati program koji ucitava karakter po karakter do EOF i ispisuje koliko se puta
   u unetom tekstu pojavila svaka cifra, svako malo slovo i svako veliko slovo. Ispisati
   broj pojavljivanja samo za ona mala slova, velika slova i cifre koji su se u unetom 
   tekstu pojavili >0 puta.   
*/

#include <stdio.h>


int main()
{
  /* Za svaku dekadnu cifru definisemo jedan brojac (tj. imamo niz
     od 10 brojaca): brojaci[0] broji koliko se puta pojavio karakter
     '0', brojaci[1] broji koliko se puta pojavio karakter '1' i tako
     dalje. Svi brojaci se inicijalizuju nulama. 
  */
  int cifre[10];
  int mala[26];
  int velika[26];
  
  int c, i;

  for(i=0;i<10;i++)
    cifre[i]=0;
    
  for(i=0;i<26;i++)
  {
    mala[i]=0;
    velika[i]=0;
  }   
  
  while((c = getchar()) != EOF)
  {
      
    if (c>='A' && c<='Z')
      velika[c-'A']++;
    else if (c>='a' && c<='z')
      mala[c-'a']++;
    else if(c >='0' && c <= '9')  /* Ako je karakter c dekadna cifra... */
      cifre[c-'0']++;             /* Uvecavamo odgovarajuci brojac za 1 */
      
      /* 
         Izraz c - '0' ce u slucaju da je c dekadna cifra imati upravo 
	 vrednost 0, 1, ..., 9 za karaktere '0', '1', ..., '9' respektivno,
	 a to su upravo indeksi u nizu brojaci (jer niz ima 10 elemenata,
	 pa su indeksi od 0 do 9). Time postizemo da brojaci[0] broji
	 karaktere '0', itd. Isto vazi i za brojace za mala i velika slova.
      */
  }

  /* Prikazujemo elemente niza, tj. vrednosti brojaca: */
  for(i = 0; i < 10; i++)
    if (cifre[i]!=0)
      printf("Karakter %c se pojavljuje %d puta\n", '0' + i, 
	   cifre[i]);  
	   
   for(i = 0; i < 26; i++)
    if (mala[i]!=0)
      printf("Karakter %c se pojavljuje %d puta\n", 'a' + i, 
	   mala[i]);  

    for(i = 0; i < 26; i++)
    if (velika[i]!=0)
      printf("Karakter %c se pojavljuje %d puta\n", 'A' + i, 
	   velika[i]);  

  return 0;
}