/*
   Napisati funkciju void sifruj(char s[], char c, int k) koja sifruje
   string s na sledeci nacin: svako malo i veliko slovo stringa s konvertuje u
   slovo koje je u abecedi od njega udaljeno k pozicija, i to 
   k pozicija ulevo, ako je karakter c jednak karakteru 'L' ili udesno
   ako je karakter c jednak karakteru 'D'. Sifrovanje treba da bude kruzno. Ako string
   s sadrzi karakter koji nije alfanumericki, ostaviti ga nesifriranog.
   
   Napisati potom glavni program koji testira napisanu funkciju za string i prirodan
   broj koji se unose kao argumenti komandne linije dok se pravac sifrovanja unosi
   kao opcija -p koja moze imati vrednosti 'L' ili 'D'. Ukoliko opcija -p nije 
   navedena, podrazumevani pravac je udesno. 
   
   Mozemo podrazumevati da string sadrzi najvise 30 karaktera.
   
   Primeri upotrebe:
   
   1:
   ./a.out abcd 2
   cdef
   
   2:
   ./a.out abcd 2 -p D
   cdef
   
   3:
   ./a.out abcd 2 -p L
   yzab
   
   4:
   ./a.out abcd -3 -p L
   Nekorektan unos
   
   5: 
   ./a.out abcd 3 -p X
   Nekorektan unos
   
   6:
   ./a.out ab12cd 2 -p D
   cd12ef
   
*/   
  
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define MAX 31

void sifruj(char s[], char c, int k)   
{
   int i;
   int znak;
   char t;
   
   /*
      S obzirom da ce korektnost unosa podataka
      biti ispitana pre poziva funkcije, promenljiva
      c ce imati vrednost 'L' ili 'D'.
      
      Promenljiva znak ima vrednost 1 ili -1
      i sluzi kao pomocna promenljiva u slucaju
      da prilikom sifriranja konvertovani
      karakter izadje iz opsega malih ili velikih slova.
      
   */
   znak=1;   
   if (c=='L')
      znak = -1;
   
   
   for(i=0; s[i];i++)
      if(isalpha(s[i]))
      {
         /*
            Promenljiva t predstavlja sifrirani karakter s[i].
            Ako je promenljiva t izvan opsega malih ili velikih slova,
            dodajemo joj ili oduzimamo ukupan broj slova u abecedi (26),
            u zavisnosti od pravca sifriranja, kako bismo omogucili
            kruzno sifriranje.
         */
         t = s[i]+znak*k;
         if((islower(s[i]) && (t<'a' || t>'z')) || (isupper(s[i]) && (t<'A' || t>'Z')))
            s[i]=t-znak*26;
         else
            s[i]=t;
      }
}

int main(int argc, char* argv[])
{

   int k;
   char pravac;
   char rec[MAX];
   
   /*
      Program mozemo pozivati na dva nacina:
      ./a.out abcd 2
      ili
      ./a.out abcd 2 -p D
      
      Zbog toga, broj argumenata moze biti 3 ili 5.      
   */
   
   if (argc!=3 && argc!=5)
   {
      printf("Nekorektan unos: broj argumenata moze biti 3 ili 5\n");
      return -1;
   }
   
   /*
      Argumenti komandne linije su stringovi. Ako program pokrecemo
      na sledeci nacin:
      ./a.out abcd 2 -p D      
      to znaci da je argument koji odgovara dvojci u stvari
      string "2". Da bismo string konvertovali u ceo broj,
      koristimo ugradjenu funkciju atoi iz biblioteke stdlib.h.      
   */
   
   k = atoi(argv[2]);
   
   /*
      Ispitujemo korektnost datih podataka:
   */
   if (k<=0)
   {
      printf("Nekorektan unos: broj pozicija mora biti pozitivan ceo broj\n");
      return -1;
   }
   
   /* Korektnost unosa je ispitana, sto znaci da 
   argc moze biti 3 ili 5 */
   
   if (argc==3) /* Ako je argc 3: */
      pravac='D';
   else        /* Ako argc nije 3, tada je sigurno 5, jer je */
   {           /* korektnost unosa ispitana, a unos je korektan jedino za argc==3 ili argc==5 */
      /*
         Ispitujemo korektnost pretposlednjeg argumenta koji mora da bude u formatu "-p".         
         Ovaj argument je string argv[3]. Njegovom prvom karakteru (koji treba
         da bude '-') pristupamo sa argv[3][0] a drugom sa argv[3][1].
      */
      if (argv[3][0] != '-')
      {
         printf("Nekorektan unos: pri zadavanju opcija prvi karakter mora biti '-' \n");
         return -1;
      }
      
      if (argv[3][1]!='p')     
      {
         printf("Nekorektan unos: nedozvoljena opcija\n");
         return -1;
      }

      /*
         Nakon argumenta -p sledi argument koji zadaje vrednost ove opcije. To je
         poslednji argument kome pristupamo sa argv[4]. Ovaj argument treba
         da sadrzi samo jedan karakter - 'L' ili 'D' i njemu pristupamo sa
         argv[4][0].
      */
      if(argv[4][0]=='L' || argv[4][0]=='D')
         pravac=argv[4][0];
      else
      {
         printf("Nekorektan unos: pravac moze biti L ili D\n");
         return -1;
      }                  
   }
   
   strcpy(rec, argv[1]);
   sifruj(rec,pravac,k);   

   printf("Sifrovana rec: %s\n", rec);
   
   return 0;
}

