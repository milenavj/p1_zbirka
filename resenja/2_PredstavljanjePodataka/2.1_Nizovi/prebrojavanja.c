#include <stdio.h>

int main()
{
  /* Niz u kojem ce se cuvati informacije o pojavljivanju cifara */
  int cifre[10];
  
  /* Niz u kojem ce se cuvati informacije o pojavljivanju malih slova */
  int mala_slova[26];
  
  /* Niz u kojem ce se cuvati informacije o pojavljivanju velikih slova */
  int velika_slova[26];
  
  int c, i;

  /* Brojaci se na pocetku inicijalizuju nulama */
  for(i=0;i<10;i++){
    cifre[i]=0;
  }
    
  for(i=0;i<26;i++)
  {
    mala_slova[i]=0;
    velika_slova[i]=0;
  }   
  
  /* Ucitavaju se karakteri sve do kraja ulaza */
  while((c = getchar()) != EOF)
  {
    /* Ako je procitani karakter veliko slovo ... */
    if (c>='A' && c<='Z'){
      velika_slova[c-'A']++;
    }
    else{
      /* Ako je procitani karakter malo slovo ... */
      if (c>='a' && c<='z'){
        mala_slova[c-'a']++;
      }
      else{
        /* Ako je procitani karakter cifra ... */
        if(c >='0' && c <= '9'){
          cifre[c-'0']++;
        }
      }
    }
  }

  /* Ispisuju se trazene informacije */
  for(i = 0; i < 10; i++){
    if (cifre[i]!=0)
      printf("Karakter %c se pojavljuje %d puta\n", '0' + i, cifre[i]);  
  }
	   
   for(i = 0; i < 26; i++){
    if (mala_slova[i]!=0)
      printf("Karakter %c se pojavljuje %d puta\n", 'a' + i, mala_slova[i]);  
   }

    for(i = 0; i < 26; i++){
      if (velika_slova[i]!=0)
        printf("Karakter %c se pojavljuje %d puta\n", 'A' + i, velika_slova[i]);  
    }

    
  return 0;
}