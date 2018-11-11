#include <stdio.h>
#include <stdlib.h>

/* Funkcija koja dato trajanje izrazeno u ukupnom broju sekundi
   konvertuje u trajanje koje je izrazeno u broju sati, minuta
   i sekundi. */
void konverzija(int trajanje, int* psati, int* pminuti, 
                int* psekunde)
{
  *psati = trajanje / 3600;
  trajanje -= *psati * 3600;
  
  *pminuti = trajanje/60;
  trajanje -= *pminuti * 60;
  
  *psekunde = trajanje;
}

int main() 
{
  /* Deklaracija potrebnih promenljivih. */
  int trajanje, sati, minuti, sekunde;
  
  /* Ucitava se trajanje u sekundama. */
  printf("Trajanje filma u sekundama: ");
  scanf("%d", &trajanje);
  
  /* Vrsi se provera ispravnosti ulaza. */
  if(trajanje < 0) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Racunanje rezultata. */
  konverzija(trajanje, &sati, &minuti, &sekunde);
  
  /* Ispis rezultata. */
  printf("%dh:%dm:%ds\n", sati, minuti, sekunde);
  exit(EXIT_FAILURE);
}