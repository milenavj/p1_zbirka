#include <stdio.h>

#define MAX 100

/* Funkcija koja ucitava elemente niza */
void ucitaj(int a[], int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
}

/* Funkcija koja ispisuje elemente niza */
void stampaj(int a[], int n)
{  
   int i;
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\n");
}


/* a) Funkcija koja proverava da li niz sadrzi zadatu vrednost m */
int sadrzi(int a[], int n, int m)
{
   int i;
   
   /* Poredi se element po element niza a sa zadatim brojem m */
 
   for(i=0;i<n;i++){
     /* Ukoliko je tekuci element niza jednak trazenom broju */ 
     if (a[i]==m){
        /* Funkcija vraca vrednost 1 */
        return 1;
     }
   }

   /* Ako se stigne do kraja niza i ne naidje na vrednost koja je jednaka broju m,
     to znaci da se broj ne nalazi u nizu i da funkcija treba da vrati 0. */
   return 0;
}

/* b) Funkcija koja vraca vrednost prve pozicije na kojoj se nalazi element koji ima vrednost m, 
  ili -1 ukoliko element nije u nizu */
int prvo_pojavljivanje(int a[], int n, int m)
{
   int i;
   
   /* Poredi se element po element niza a sa zadatim brojem m */
   
   for(i=0;i<n;i++){
    /* Ukoliko je tekuci element niza jednak trazenom broju */ 
     if (a[i]==m){  
        /* Vraca se njegov indeks */
        return i;
     }
   }
   
   /* Ako se stigne do kraja niza i ne naidje na vrednost koja je jednaka broju m,
     to znaci da se broj ne nalazi u nizu i da funkcija treba da vrati -1. */
   return -1;
}

/* c) Funkcija koja vraca vrednost poslednje pozicije na kojoj se nalazi element koji ima vrednost m, 
 ili -1 ukoliko element nije u nizu */
int poslednje_pojavljivanje(int a[], int n, int m)
{
   int i;
   
   /* Polazi se od kraja niza i poredi se element po element sa zadatim brojem m*/
   
   for(i=n-1;i>=0;i--){
     /* Ukoliko je tekuci element niza jednak trazenom broju */ 
      if (a[i]==m){
       /* Vraca se njegov indeks */
        return i; 
      }
   }
   
   /* Ako se stigne do pocetka niza i ne naidje na vrednost koja je jednaka broju m,
     to znaci da se broj ne nalazi u nizu i da funkcija treba da vrati -1. */
   return -1;
}

/* d) Funkcija koja proverava da li elementi niza cine palindrom */
int palindrom(int a[], int n)
{
  
   int i,j;

   /*
    Uporedjuje se element na poziciji 0 sa elementom na poziciji n-1
    Uporedjuje se element na poziciji 1 sa elementom na poziciji n-2
    Uporedjuje se element na poziciji 2 sa elementom na poziciji n-3
    .
    .
    i tako redom dok je pozicija prvog elementa manja od pozicije drugog elementa
   */
   
   for(i=0,j=n-1;i<j;i++,j--){
     /* Ako element na poziciji i nije jednak odgovarajucem elementu na poziciji j */
     if(a[i]!=a[j]){
       /* Moze se odmah zakljuciti da niz nije palindrom */
        return 0;
     }
   }

   /* AKo su svi parovi elemenata jednaki, niz je palindrom i funkcija vraca vrednost 1 */
   return 1;
}

/* e) Funkcija koja proverava da li su elementi niza uredjeni neopadajuce */
int neopadajuci(int a[], int n)
{
   int i;
   
   /* Ako je niz uredjen neopadajuce vaze nejednakosti:
      a[0]<=a[1], a[1]<=a[2], ..., a[i]<=a[i+1], ..., a[n-2]<=a[n-1]
      Zato je dovoljno proveriti da li za parove susednih elemenata vazi ovi svojstvo.
   */
   for(i=0; i<n-1; i++)
      if (a[i]>a[i+1])
         return 0;

   return 1;
}


/* f) Funkcija koja izracunava najduzu uzastopnu seriju jednakih 
elemenata u nizu. Na primer, za uneti niz 1 2 3 4 4 4 5 6 7 8 9 9 funkcija 
treba da vrati 3. */
int najduza_serija_jednakih(int a[], int n)
{
   int i; 
   int j; 
   int duzina;
   int max_duzina=0;


   for(i=0,j=0;i<n-1;i++)
   {
      if(a[i]==a[i+1]) 
      {
         j++;         
         
         /*
           ako se niz zavrsava konstantnim intervalom (nalazimo se u poslednjoj
           iteraciji petlje i tada je i==n-2), ispitujemo da li je taj konstantni 
           interval maksimalne duzine
         */
         if(i==n-2)
         {
            j++;
            if(j>max_duzina)
               max_duzina=j;
         }
      }   
      else
      {   
         /* 
            izasli smo iz konstantnog intervala
         
            ukoliko smo imali bar dva elementa u konstantnom intervalu, 
            vrednost promenljive j ce biti 1, a duzina tog intervala je 2;
            zbog toga je neophodno takve (pozitivne) j uvecati za 1;
            
            sa druge strane, ako su a[i] i a[i+1] razliciti,
            duzina tog intervala je 0
         */

         if (j>0)
            j++;  
           
         /* azuriramo maksimalnu duzinu uspona */
         if(j>max_duzina)
            max_duzina=j;
         /* 
             duzina uspona se postavlja na nulu 
             kako bi mogli da je iskoristimo
             za naredni uspon         
         */
         j=0;
        
      } 
        
        
   }    
           
   return max_duzina;
}
 

int main()
{
   int a[MAX];
   int n;
   int m;
   int i;

   /* Ucitava se dimenzija niza i proverava se njena ispravnost */
   printf("Unesite dimenziju niza:");
   scanf("%d",&n);
   if (n<1 || n>MAX)
   {
      printf("Nedozvoljena vrednost!\n");
      return -1;
   }
  
   /* Ucitavaju se i ispisuju elementi niza */
   ucitaj(a,n);
   printf("Ucitani niz:");
   stampaj(a,n);

   /* Ucitava se vrednost za pretragu */
   printf("Unesi jedan ceo broj:"); 
   scanf("%d",&m);
   
   /* I proverava se rad napisanih funkcija */
   if(sadrzi(a,n,m))
      printf("Niz sadrzi element cija je vrednost %d\n", m);
   else
      printf("Niz ne sadrzi element cija je vrednost %d\n", m);

   i = prvo_pojavljivanje(a,n,m);
   if(i!=-1)
      printf("Niz sadrzi element cija je vrednost %d. Indeks njegovog prvog pojavljivanja u nizu je %d\n", m,i);
   else
      printf("Niz ne sadrzi element cija je vrednost %d\n", m);


   i = poslednje_pojavljivanje(a,n,m);
   if(i!=-1)
      printf("Niz sadrzi element cija je vrednost %d. Indeks njegovog poslednjeg pojavljivanja u nizu je %d\n", m,i);
   else
      printf("Niz ne sadrzi element cija je vrednost %d\n", m);

   if(palindrom(a,n))
      printf("Elementi niza cine palindrom\n");
   else
      printf("Elementi niza ne cine palindrom\n");

   if(neopadajuci(a,n))
      printf("Niz je sortiran neopadajuce\n");
   else
      printf("Niz nije sortiran neopadajuce\n");

   printf("Duzina najduzeg konstantnog intervala: %d\n", najduza_konstanta(a,n));


   return 0;
}
