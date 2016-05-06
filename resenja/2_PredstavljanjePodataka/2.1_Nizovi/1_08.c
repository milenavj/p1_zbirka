/*
   a) Napisati funkciju koja ucitava sadrzaj niza.
   b) Napisati funkciju koja stampa sadrzaj niza.
   c) Napisati funkciju koja proverava da li niz sadrzi neku vrednost m.
   d) Napisati funkciju koja vraca vrednost prve pozicije na kojoj se 
nalazi element koji ima vrednost m, ili -1 ukoliko element nije u nizu.
   e) Napisati funkciju koja vraca vrednost poslednje pozicije na kojoj se 
nalazi element koji ima vrednost m, ili -1 ukoliko element nije u nizu.
   f) Napisati funkciju koja proverava da li elementi niza cine palindrom.
   g) Napisati funkciju koja proverava da li su elementi niza uredjeni 
neopadajuce.
   h) Napisati funkciju koja izracunava najduzu uzastopnu seriju jednakih 
elemenata u nizu. Na primer, za uneti niz 1 2 3 4 4 4 5 6 7 8 9 9 funkcija 
treba da vrati 3.
   i) Napisati program koji testira prethodne funkcije.
*/
#include <stdio.h>
#define MAX 100

/* a) */
void ucitaj(int a[], int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("Unesi element na poziciji %d:",i);
      scanf("%d",&a[i]);
   }
}

/* b) */
void stampaj(int a[], int n)
{  
   int i;
   for(i=0;i<n;i++)
      printf("%d\t",a[i]);
   printf("\n");
}


/* c) */
int sadrzi(int a[], int n, int m)
{
   int i;
   /*
     poredimo jedan po jedan element niza a sa datim m; ukoliko
     ustanovimo jednakost, to znaci da niz sadrzi element jednak
     m i vracamo 1
   */
   for(i=0;i<n;i++)
      if (a[i]==m)  
         return 1;   
  
   /*
     ukoliko se petlja zavrsi a uslov a[i]==m nijednom nije bio ispunjen,
     to znaci da se broj m ne nalazi u nizu a i da funkcija treba da vrati 0
   */    
   return 0;
}

/* d) */
int prvo_pojavljivanje(int a[], int n, int m)
{
   int i;
   /*
     poredimo jedan po jedan element niza a sa datim m; ukoliko
     ustanovimo jednakost, vracamo indeks elementa niza a koji 
     je jednak sa m
   */
   for(i=0;i<n;i++)
      if (a[i]==m)  
         return i;   
  
   /*
     ukoliko se petlja zavrsi a uslov a[i]==m nijednom nije bio ispunjen,
     to znaci da se broj m ne nalazi u nizu a i da funkcija treba da vrati -1
   */    
   return -1;
}

/* e) */
int poslednje_pojavljivanje(int a[], int n, int m)
{
   int i;
   /*
     krecemo od indeksa poslednjeg elementa, n-1
   */
   for(i=n-1;i>=0;i--)
      if (a[i]==m)
         return i; 
  
   return -1;
}

/* f) */
int palindrom(int a[], int n)
{
  
   int i,j;

   /*
    uporedjujemo element na poziciji 0 sa elementom na poziciji n-1
    uporedjujemo element na poziciji 1 sa elementom na poziciji n-2
    .
    .
    i tako redom dok je prva pozicija manja od druge
   */
   for(i=0,j=n-1;i<j;i++,j--) 
     if(a[i]!=a[j]) 
        return 0;

   return 1;
}

/* g) */
int neopadajuci(int a[], int n)
{
   int i;
   
   /*
   Funkcija neopadajuci proverava da li je dati niz sortiran neopadajuce i vraca
   1 ako jeste, a 0 u suprotnom   
   
   Sortiranost proveravamo na sledeci nacin: za svaki par susednih elemenata
   a[0] i a[1], a[1] i a[2], a[2] i a[3], ..., a[n-2] i a[n-1] proveravamo
   da li vazi da je drugi clan para manji od prvog. Ako naidjemo na par za koji
   to ne vazi, niz nije sortiran i funkcija vraca 0. Ukoliko se petlja zavrsi
   a da pritom uslov a[i]<a[i-1] nije nijednom bio ispunjen, to znaci da je
   niz sortiran i funkcija vraca 1
   
   */
   for(i=1; i<n; i++)
      if (a[i]<a[i-1])
         return 0;

   return 1;
}

/* h) */
int najduza_konstanta(int a[], int n)
{
   int i; /* indeks niza */
   int j; /* duzina intervala */
   int duzina;
   int max_duzina=0;


   for(i=0,j=0;i<n-1;i++)
   {
      if(a[i]==a[i+1]) /* nalazimo se unutar konstantnog intervala */
      {
         j++;         /* uvecavamo duzinu konstantnog intervala */
         
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

   printf("Unesi dimenziju niza:");
   scanf("%d",&n);

   if (n<1 || n>MAX)
   {
      printf("Nekorektan unos\n");
      return -1;
   }

   ucitaj(a,n);
   printf("Ucitani niz:");
   stampaj(a,n);

   printf("Unesi jedan ceo broj:"); 
   scanf("%d",&m);
   
   
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
