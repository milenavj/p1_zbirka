/*
  a) Napisati funkciju koja sve vrednosti niza uvecava za vrednost m.
  b) Napisati funkciju koja obrce vrednosti elementima niza.     
  c) Napisati funkciju koja rotira niz ciklicno za jedno mesto u levo.
  d) Napisati funkciju koja rotira niz ciklicno za k mesta u levo.
  e) Napisati program koji testira prethodne funkcije.

  Napisati potom glavni program koji testira ovu funkciju.
*/

#include<stdio.h>
#define MAX 100

void ucitaj(int a[], int n)
{
   int i;
   for(i=0;i<n;i++)
   {
        printf("Unesi element na poziciji %d:",i);
        scanf("%d",&a[i]);
   }
}
 
void stampaj(int a[], int n)
{
   int i;
   for(i=0;i<n;i++)
        printf("%d\t",a[i]);
   printf("\n");
}


void uvecaj(int a[], int n, int m)
{  
   int i;
   for(i=0;i<n;i++)
        a[i]+=m;   
}


void obrni(int a[], int n)   
{          
  
   int t;  
   int i,j;
   /*
    Niz obrcemo tako sto razmenimo vrednosti elemenata na pozicijama 0 i n-1,
    zatom 1 i n-2, 2 i n-3 i tako redom dok je prva pozicija manja od druge
   */    

   for(i=0,j=n-1;i<j;i++, j--)
   { 
        t = a[i];
        a[i] = a[j];  
        a[j] = t;   
   }

}   

void rotiraj1(int a[], int n)
{
   int i;
   int tmp;
   tmp=a[0]; /* izdvajamo prvi element */
   for(i=0;i<n-1;i++)
        a[i]=a[i+1]; /* pomeramo preostale elemente */
   a[n-1] = tmp;  /* poslednjem elementu dodeljujemo 
                     sacuvanu vrednost prvog elementa */
}

void rotirajk(int a[], int n, int k)
{
   int i;
   /*
      k puta rotiramo niz za jednu poziciju
      ulevo
   */
   for(i=0;i<k;i++)
        rotiraj1(a,n);
}

int main()
{  
  int a[MAX];
  int n;
  int i;
  int k;
  int m;
      
  printf("Unesi dimenziju niza:");
  scanf("%d",&n);   
  
  if (n<1 || n>MAX)
  {
        printf("Nekorektan unos\n");
        return -1;
  }       
 
  ucitaj(a,n);
  
  printf("Unesi jedan ceo broj:");
  scanf("%d", &m);
  
  uvecaj(a,n,m);
  printf("Elementi niza nakon uvecanja za %d:\n",m);
  stampaj(a,n);
  
  obrni(a,n);
  printf("Elementi niza nakon obrtanja:\n");
  stampaj(a,n);
  
  printf("Unesi jedan pozitivan ceo broj:"); 
  scanf("%d",&k);
  
  if (k<=0)
  {
        printf("Nekorektan unos\n");
        return -1;
  }
  
  rotiraj1(a,n);
  printf("Elementi niza nakon rotiranja za 1 mesto ulevo:\n");
  stampaj(a,n);
  
  rotirajk(a,n,k);
  printf("Elementi niza nakon rotiranja za %d mesto ulevo:\n",k);
  stampaj(a,n);
  
  return 0;
}
