/*
   Napisati funkciju koja za dve prave date svojim koeficijentima
   pravca i slobodnim clanovima odredjuje njihovu tacku preseka. 
   Funkcija treba da vrati 1 ako se prave seku i 0 ako nemaju
   tacku preseka (ako su paralelne). Napisati glavni program
   koji ucitava podatke o pravama, poziva napisanu funkciju i 
   ispisuje odgovarajucu poruku.
*/

#include<stdio.h>

/*
   Funkcija presek treba da izracuna tri vrednosti:
   1. indikator da li su koeficijenti pravca jednaki ili ne
   2. prvu koordinatu presecne tacke (ukoliko prave nisu paralelne)
   3. drugu koordinatu presecne tacke (ukoliko prave nisu paralelne)
   
   Indikator funkcija vraca kao povratnu vrednost, preko kljucne reci
   return.
   
   Koordinate presecne tacke (ako postoji) funkcija vraca preko 
   liste argumenata, zbog cega promenljive kojima ce koordinate
   biti dodeljene prenosimo preko pokazivaca (promenljive px i py)
   
   Promenljive koje sadrze podatke o pravama (k1,n1,k2,n2) se ne
   menjaju u funkciji i zbog toga ih ne moramo prenositi preko
   pokazivaca.
*/

int presek(float k1, float n1, float k2, float n2, float* px, float* py)
{
   if (k1==k2)
     return 0;
   
   *px = -(n1-n2)/(k1-k2);
   *py = k1*(*px)+n1;
   return 1;
}

int main()
{
   float k1,k2,n1,n2;
   float x,y;
      
   printf("Unesi k i n za prvu pravu:");
   scanf("%f%f",&k1,&n1);
   
   printf("Unesi k i n za drugu pravu:");
   scanf("%f%f",&k2,&n2);
   
   if(presek(k1,n1,k2,n2,&x,&y))
      printf("Prave se seku u tacki (%.2f,%.2f)\n", x,y);
   else
      printf("Prave su paralelne\n");
      
   return 0;
}