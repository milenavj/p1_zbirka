#include <stdio.h>

/* Funkcija vraca karakter koji se u abecedi nalazi k mesta pre datog karaktera c. */
char sifra(char c, int k) {

  /* Provera da li je karakter malo slovo. */
  if(c >= 'a' && c <= 'z')
    /* Ako karakter koji je k pozicija pre datog karaktera ispada iz opsega malih slova. */
    if(c-k < 'a') 
      /* Od k se oduzima rastojanje izmedju c i 'a' (jer je za toliko karaktera vec vraceno u nazad), kako bi se odredilo koliko preostali broj karaktera koji treba preskociti od karaktera 'z'.
       */
      return 'z' - (k - (c -  'a') - 1);
    else
      /* U suprotnom, karakter c-k ne ispada iz opsega malih slova, te je dovoljno njega vratiti. */
      return c-k;
    
  /* Provera da li je karakter veliko slovo. */ 
  else if(c >= 'A' && c <= 'Z')
    if(c-k < 'A')
      return 'Z' - (k - (c -  'A') - 1);
    else
      return c-k;
  
    
  return c;
}

int main() {

  int k;
  char c;
  
  printf("Unesite broj k: ");
  scanf("%d", &k);
  
  printf("Unesite tekst (CTRL + D za prekid): ");
  while((c = getchar()) != EOF) 
    putchar(sifra(c, k));
  
  return 0;
}
