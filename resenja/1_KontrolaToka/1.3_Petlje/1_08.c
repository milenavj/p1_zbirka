/*
    Napisati program koji omogucava korisniku da unosi karaktere dok
    ne zada EOF a potom ispisuje broj velikih slova, broj malih slova,
    broj cifara, broj belina i zbir cifara.
*/

#include <stdio.h>

int main()
{
  /* promenljivoj c dodelicemo povratnu vrednost funkcije getchar() 
     funkcija getchar() ucitava jedan karakter sa standardnog ulaza 
     i vraca njegov ascii kod; povratna vrednost funkcije getchar je 
     int, pa i promenljiva c mora biti tipa int 
  */
  int c;
  
   /* brojaci moraju biti inicijalizovani na 0 */
  int br_v=0;
  int br_m=0;
  int br_c=0;
  int br_b=0;
  int br_k=0;
  int suma=0;
   
  while((c=getchar())!=EOF)              /* petlja se zavrsava kada korisnik ne unese karakter, vec zada konstantu EOF */
  {                                      /* ova konstanta se zadaje kombinacijom tastera CTRL+D. U tom slucaju, getchar() vraca -1*/
    if (c>='A' && c<='Z')
      br_v++; /* <=> br_v = br_v+1; */
    else if (c>='a' && c<='z')
      br_m++;
    else if (c>='0' && c<='9')
    {
      br_c++;
      suma=suma+c-'0';            /* funkcija getchar() vraca ascii kod unetog karaktera; ascii kodovi cifara 0,1,...,9
	                                 su redom 48,49,...,57; Na primer, za unetu 1 
	                                 promenljiva c ce imati vrednost 49. Zbog toga bi bilo pogresno racunati
									 zbir kao zbir=zbir+c. Promenljivu zbir zato racunamo kao zbir=zbir+(c-'0')
									 jer c-'0' ce za unetu 0 proizvesti 48-'0' sto je 0, 
									 za unetu 1 49-'0' sto je 1, za unetu 2 50-'0' sto je 2, ...*/
    }
    else if (c=='\t' || c=='\n' || c==' ')
      br_b++;
    
    br_k++;      
  }
  
  printf("velika: %d, mala: %d, cifre: %d, beline: %d, svi: %d\n", br_v, br_m, br_c, br_b, br_k);
  printf("suma cifara: %d\n", suma);

  return 0;
}