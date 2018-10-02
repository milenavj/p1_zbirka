/*
  Napisati funkciju koja za boju datu u rgb formatu 
  racuna cmy format po formulama:
  C = 1 - ( R / 255 )
  M = 1 - ( G / 255 )
  Y = 1 - ( B / 255 )

  Napisati program koji ucitava boju u rgb formatu, 
  primenjuje odgovarajucu funkciju i ispisuje boju u cmy formatu.

*/

#include <stdio.h>
#include <math.h>

void rgb_to_cmy(float* a, float* b, float* c)
{
  /* Zagrade su neophodne jer aritmeticke operacije
     imaju veci prioritet od operatora dereferenciranja (*).
  */
  *a=1-(*a)/255;
  *b=1-(*b)/255;
  *c=1-(*c)/255;
  
  /*
  Pomocu return ne mozemo vratiti vise od jedne vrednosti.
  
  Ceste greske:
  return a,b,c;         return vraca samo jednu vrednost
  return a; return b; return c; return ce vratiti samo a
  
  Zato je neophodno da promenljive ciju vrednost
  zelimo da promenimo prenesemo preko pokazivaca.
  */
}


int rgb_korektno(float a)
{
   if(a<0 || a>255)
      return 0;
   return 1;
}


int main()
{
  float a,b,c;

  /*
      Argumenti funkcije rgb_to_cmy su
      pokazivaci na float. Njima prosledjujemo
      adrese promenljivih a, b i c.
  */
  
  printf("Unesi boju u rgb formatu (vrednosti izmedju 0 i 255:");
  scanf("%f%f%f",&a,&b,&c);
     
  if(rgb_korektno(a) && rgb_korektno(b) && rgb_korektno(c))
     rgb_to_cmy(&a,&b,&c);
  else
  {
     printf("Nekorektan unos\n");
     return -1;
  }
  
  printf("Nakon konverzije: %.2f,%.2f,%.2f\n", a,b,c);
  
  return 0;
}