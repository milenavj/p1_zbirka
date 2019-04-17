#include <stdio.h>
#include <stdlib.h>

#define MAKS_STUDENATA 100
    
typedef struct
{
  char korisnicko_ime[8];
  float prosek;
} Student;

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  FILE * ulaz;
  Student studenti[MAKS_STUDENATA];
  int ocena1, ocena2, ocena3, ocena4, ocena5, zbir_ocena;
  int i = 0, n;
  float maks_prosek = 0;
  
  /* Ulazna datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */  
  ulaz = fopen("studenti.txt", "r");
  if (ulaz == NULL)
  {
    fprintf(stderr, "Greska: neuspesno otvaranje "
                    "ulazne datoteke.\n");
    exit(EXIT_FAILURE);
  }  

  /* Citaju se podaci o studentima sve dok se ne dodje do kraja
     ulaza. */
  while (fscanf(ulaz, "%s%d%d%d%d%d", studenti[i].korisnicko_ime,
              &ocena1, &ocena2, &ocena3, &ocena4, &ocena5) != EOF)
  {
    /* Racuna se prosek trenutnog studenta. */
    zbir_ocena = ocena1 + ocena2 + ocena3 + ocena4 + ocena5;
    studenti[i].prosek = zbir_ocena / 5.0;
    
    /* Azurira se maksimalni prosek. */
    if (studenti[i].prosek > maks_prosek) 
      maks_prosek = studenti[i].prosek;
    
    /* Prelazi se na sledeceg studenta. */
    i++;
  }
  
  /* Promenljiva n cuva ukupan broj studenata. */
  n=i;
  
  /* Ispis svih studenata sa maksimalnim prosekom. */
  for(i=0; i<n; i++)
  {
    if(studenti[i].prosek == maks_prosek)
      printf("korisnicko ime: %s, prosek ocena: %.2f\n",
             studenti[i].korisnicko_ime, studenti[i].prosek);
  }
 
  /* Zatvara se datoteka. */ 
  fclose(ulaz);

  return 0;
}