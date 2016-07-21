#include <stdio.h>
#include <string.h>

#define MAX_IME_PREZIME 51
#define MAX_ZELJA 101
#define MAX_BR_STUDENATA 100

typedef struct student
{
  char imeipre[MAX_IME_PREZIME];
  char zelja[MAX_ZELJA];
} STUDENT;


int main()
{
  STUDENT studenti[MAX_BR_STUDENATA];
  char odgovor[3];
  char imeiprezime[MAX_IME_PREZIME]; 
  int i = 0, n;
  int broj_pronalazaka;
   
 
  /*
    Ucitavamo studente i njihove zelje i upisujemo ih u niz
     sve dok to zelimo ili dok ne unesemo MAX_BR_STUDENATA studenata.
  */
  while(i < MAX_BR_STUDENATA)
  {
    printf("Ime i prezime studenta: \n");
    /*
      Funkcija fgets ucitava jednu liniju i smesta je promenljivu koju zadajemo kao njen prvi argument.
      Drugi argument je maksimalna duzina linije.
      Treci argument je kod nas stdin sto predstavlja standardni ulaz.
    */

    if(fgets(studenti[i].imeipre, MAX_IME_PREZIME, stdin) == NULL)
    {
      printf("Greska: nismo dobro ucitali ime i prezime studenta.");
      return 0;
    }

    printf("Njegova zelja: \n");

    if(fgets(studenti[i].zelja, MAX_ZELJA, stdin) == NULL)
    {
        printf("Greska: nismo dobro ucitali zelju studenta.");
        return 0;
    }

    i++;

    printf("Jos vrednih studenta (da/ne)?\n");

    scanf("%s", odgovor);

    /*
      Moramo da pokupimo karakter koji unesemo nakon odgovora
      kako ga ne bismo ucitali u sledecoj iteraciji petlje.
    */
    getchar();
    /*
      Ukoliko je nas odgovor "ne" prekidamo petlju.
      A ukoliko nije ni "da" ni "ne" onda nismo dobro uneli odgovor.
    */
    if(strcmp(odgovor,"ne") == 0)
      break;
    else if(strcmp(odgovor,"da") != 0)
    {
      printf("Greska: odgovor mora biti u obliku (da/ne)!");
      return 0;
    }

  }

  /*
    Postavljamo dimenziju niza.
  */
  n = i;
  printf("Za podsecanje uneti ime i prezime: \n");
  if(fgets(imeiprezime, MAX_IME_PREZIME, stdin) == NULL)
  {
    printf("Greska: nismo dobro ucitali ime i prezime studenta.");
    return -1;
  }

  /* Prolazimo kroz listu studenta i ispisujemo zelje studenta cije ime i prezime smo uneli. */
  broj_pronalazaka=0;
  for(i=0;i<n;i++){
    if(strcmp(imeiprezime, studenti[i].imeipre) == 0){      
      broj_pronalazaka++;
      printf("Novogodisnja zelja: %s\n",studenti[i].zelja);
    }
  }
  
  /* Za slucaj da nismo pronasli studenta sa trazenim imenom */
  if(broj_pronalazaka==0){
	  printf("Trazeni student ne postoji - mozda ce mu poklon odneti drugi Deda Mraz\n");
  }
  
  return 0;
}
