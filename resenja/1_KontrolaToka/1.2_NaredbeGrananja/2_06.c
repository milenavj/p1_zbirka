#include <stdio.h>

int main()
{
   unsigned a,b,c;
   unsigned min;
   unsigned cena_bez_popusta, cena_sa_popustom;

   printf("Unesite cene tri artikla:");   
   scanf("%u%u%u",&a,&b,&c);

   /* 
      Racunamo minimum tri broja. Dodeljujemo promenljivoj
      min vrednost prvog broja.   
   */   
   min=a;
   
   /* 
      Ako je drugi broj manji od minimuma, to znaci da
      promenljiva min ne sadrzi najmanji broj. Dodeljujemo
      joj vrednost drugog broja.
   */   
   if(min>b) 
      min=b;
   
   /* 
      Ako je treci broj manji od minimuma, to znaci da
      promenljiva min ne sadrzi najmanji broj. Dodeljujemo
      joj vrednost treceg broja.
   */   
   if(min>c) 
      min=c;
   
   cena_bez_popusta=a+b+c;
   cena_sa_popustom = cena_bez_popusta - min + 1;
   
   printf("Cena sa popustom: %u\nUsteda: %u\n", 
         cena_sa_popustom, cena_bez_popusta-cena_sa_popustom);
    
    return 0;
}
