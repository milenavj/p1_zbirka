#include <stdio.h>
#include <stdlib.h>

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  FILE * ulaz;
  float broj, najveci_broj;

  /* Otvara se datoteka brojevi.txt i proverava se da li je
     otvaranje proslo uspesno. */
  ulaz = fopen("brojevi.txt", "r");
  if (ulaz == NULL) 
    greska("Greska: neuspesno otvaranje ulazne datoteke.\n");
  
  /* Promenljiva u koju se smesta najveci broj se inicijalizuje na
     prvi broj iz datoteke. Ukoliko se pri prvom citanju dodje do
     kraja datoteke, ispisuje se odgovarajuca poruka. */
  if(fscanf(ulaz, "%f", &najveci_broj) == EOF)
    greska("Greska: datoteka je prazna.\n");
  
  /* Iz datoteke se cita broj po broj, sve dok se ne dodje do kraja
     datoteke i trazi se najveci procitani broj. */
  while (fscanf(ulaz, "%f", &broj) != EOF) 
  {  
    if (broj > najveci_broj) 
      najveci_broj = broj;
  }
  
  /* Ispis rezultata. */ 
  printf("Najveci broj je: %.2f\n", najveci_broj);
  
  /* Zatvara se datoteka. */ 
  fclose(ulaz);

  return 0;
}