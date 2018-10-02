/* 
	Napisati program koji pretvara zadatu broj u nisku. 
	Npr. za broj -453 treba generisati nisku "-453"
*/

#include <stdio.h>
#include <string.h>
#define MAX 10
/*

   Funkcija transformisi_negativan vraca
   1 ako je broj negativan i 0 u suprotnom, a
   uz to, ako broj jeste negativan, funkcija
   treba da ga konvertuje u  njegovu apsolutnu 
   vrednost. S obzirom da funkcija treba da vrati dve
   vrednosti, to realizujemo na sledeci nacin: 
   1. indikator da li je broj negativan
   ce vratiti kao povratnu vrednost
   2. apsolutnu vrednost broja ce vratiti
   preko liste argumenata, zbog cega broj
   prenosimo preko pokazivaca
   
*/
int transformisi_negativan(int* pn)
{
   if(*pn<0)
   {
      *pn = -(*pn);
      return 1;
   }
   return 0;
}

int formiraj_niz_cifara(int n, char b[], int neg)
{
   int i=0;
   char cifra;
   
   do
   {
      cifra = n%10;

      /* Promenljiva b predstavlja string.
         Da bismo na neku poziciju u stringu 
         upisali karakter koji odgovara nekoj
         cifri, npr '2', neophodno je da 
         odgovarajucoj poziciji dodelimo vrednost
         ASCII koda te cifre, konkretno za '2'
         ASCII kod je '0'+2.

         Greska bi bila navesti b[i]=2
         jer 2 nije ASCII kod koji odgovara karakteru
         '2'.
      */
      b[i]=cifra+'0';
      
      n/=10;
      i++;
   } while(n);
   
   /* Ako je broj negativan, dodajemo znak minus: */
   if(neg)
   {
      b[i]='-';
      i++;
   }   
   
   /* Svaki string se zavrsava terminirajucom nulom: */
   b[i]='\0';   
}

void obrni(char s[])
{          
           
   char t;  
   int i,j;
   /*
    Karaktere stringa obrcemo tako sto razmenimo karaktere na pozicijama 0 i n-1,
    zatom 1 i n-2, 2 i n-3 i tako redom dok je prva pozicija manja od druge  
   */    

   for(i=0,j=strlen(s)-1;i<j;i++, j--)
   { 
        t = s[i];
        s[i] = s[j];
        s[j] = t;   
   }

}

void broj_u_niz_cifara(int n, char broj[])
{
   int negativan;
   
   /* Odredjujemo znak broja: */
   negativan=transformisi_negativan(&n);
   
   /* Izdvajamo cifre broja i smestamo ih u niz: */
   formiraj_niz_cifara(n, broj, negativan);
   
   /* S obzirom da cifre izdvajamo sa kraja broja, u nizu ce biti u obrnutom redosledu.
      Na primer, za broj 234 niz ce sadrzati cifre 4 3 2. */
   obrni(broj);
}

int main()
{
   int n;
   char broj[MAX];
   int negativan;
	
   /* Ucitavamo broj: */
   scanf("%d", &n);	
 
   /* Kreiramo broj na osnovu niza cifara: */
   broj_u_niz_cifara(n,broj);                    
   
   /* Ispisujemo rezultat: */
   printf("Broj zapisan kao string: %s\n", broj);

   return 0;	       
}