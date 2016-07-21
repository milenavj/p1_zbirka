#include <stdio.h>

/* Funkcija racuna broj x na n-ti stepen */
int stepen(int x, int n) {

  int i; 
  /* Promenljiva u kojoj se cuva proizvod broja x sa samim sobom, n puta */
  int st = 1;
  
  for(i = 1; i <= n; i++)
    st *= x;
  
  return st;
}

/* Funkcija proverava da li je broj Armstrongov. */
int armstrong(int x) {

  /* u y se cuva zbir i-tih stepena cifara */
  int y;
  /* stepen za koji se proverava */
  int i = 1; 
  /* prilikom izdvajanja cifara, broj x se menja, 
   * te treba imati promenlju koja cuva pravu vrednost x 
   */
  int original = x; 
  
  do {
    
    y = 0;
    /* Racunamo i-te stepene za svaku cifru,
     * i istovremeno te stepen sabiramo.
     * Rezultat pamtimo u promenljivoj y.
     */
    while(x) {
    
      y += stepen(x % 10, i);
      x /= 10;
    }
    
    /* x je sada promenjen, pa ga treba vratiti na pravu vrednost. */
    x = original;
    i++;
    
  } while(y < x); /* Petlju vrtimo sve dok je zbir stepena cifara manji od datog broja. */
  
  /* Ukoliko smo nasli i, takvo da je zbir i-tih stepena cifara
   * jednak upravo broju x, takav broj je Armstrongov,
   * te izraz x == y vraca 1.
   * 
   * Inace, vraca 0, tj. broj nije Armstrongov.
   */
  return x == y;
}

int main() {

  int x;
  printf("Unesite broj: ");
  scanf("%d", &x);
  
  if(armstrong(x))
    printf("Broj je Armstrongov!\n");
  else
    printf("Broj nije Armstrongov!\n");
  
  return 0;
}
