/*
   Napisati program koji ucitava jedan ceo broj a zatim ispisuje koliko puta koja cifra ucestvuje
   u zapisu tog broja. Nije potrebno ispisivati da se neka cifra pojavila 0 puta. 
   
   Na primer, za uneti broj 4611, izlaz treba da bude: 

   U zapisu broja 4611, cifra 1 se pojaviljuje 2 puta
   U zapisu broja 4611, cifra 4 se pojaviljuje 1 puta
   U zapisu broja 4611, cifra 6 se pojaviljuje 1 puta

   A za uneti broj -252
   
   U zapisu broja -252, cifra 2 se pojaviljuje 2 puta
   U zapisu broja -252, cifra 5 se pojaviljuje 1 puta

*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main()
{
   int x;
   int brojaci[10];  
   char cifra;
   int original;
   int i;
   
   printf("Unesi jedan ceo broj:");
   scanf("%d",&x);

   /* 
      svaki element niza brojaci predstavlja 
      brojac za jednu cifru:
      brojac[0] sadrzi broj nula
      brojac[1] sadrzi broj jedinica
      ...
      brojac[9] sadrzi broj devetki            
      
      brojaci se inicijalizuju na vrednost 0
   */   
   
   for(i=0;i<10;i++)
      brojaci[i]=0;
   
   /*
      vrednost promenljive x ce biti unistena 
      u while petlji jer je u svakom koraku delimo
      sa 10; njenu vrednost cuvamo u promenljivoj
      original kako bismo mogli da je iskoristimo
      na kraju prilikom ispisa
   */
   original = x;
   
   /*
      Uzimamo apsolutnu vrednost broja za slucaj
      da je uneti broj negativan   
   */
   x=abs(x);   
   
   /* Izdvajanje cifara broja */
   do
   {
      cifra = x%10;
      brojaci[cifra]++;  /* Uvecavamo brojac odgovarajuce cifre */
      x/=10;
   } while(x);
   
   /* Ispis brojaca koji su razliciti od nule */
   for(i=0;i<10;i++)
      if(brojaci[i])
         printf("U zapisu broja %d, cifra %d se pojaviljuje %d puta\n", original, i, brojaci[i]);
   

  return 0;
}