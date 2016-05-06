#include <stdio.h>

/* Funkcija vraca karakter koji se u abecedi
 * nalazi k mesta pre datog karaktera c
 */
char sifra(char c, int k) {

  /* Ukoliko je uneto malo slovo ... */
  if(c >= 'a' && c <= 'z')
    /* Pri tome karakter koji je k pozicija pre datog karaktera ispada iz opsega malih slova ... */
    if(c-k < 'a') 
      /* Treba krenuti s drugog kraja abecede, racunajuci i preskocena slova.
       * 
       * Na primer, ukoliko je c = 'b' i k = 2
       * Jedan karakter pre 'b' je 'a'.
       * Dva karaktera pre 'b' je 'z' (kruzno).
       * 
       * Karakter iz prvog dela abecede, koji je preskocen, je 'a'.
       * Broj preskocenih karaktera iz prvog dela abecede
       * racunamo tako sto izracunamo c - 'a' (rastojanje od datog karaktera do malog slova a) 
       * sto je u ovom slucaju 'b' - 'a' = 1.
       * 
       * Ostatak karaktera do k ispisujemo, ali gledavsi unazad od z.
       * Zato racunamo k - (c - 'a') - 1.
       * 
       * Od k oduzimamo rastojanje izmedju c i 'a', 
       * kako bismo dobili preostali broj karaktera koji treba preskociti.
       */
      return 'z' - (k - (c -  'a') - 1);
    else
      /* U suprotnom, karakter ne ispada iz opsega malih slova, te je dovoljno bas njega i vratiti */
      return c-k;
    
  /* Ukoliko je uneto veliko slovo ... */ 
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