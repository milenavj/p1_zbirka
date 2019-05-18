/* U datoteci studenti. txt se nalaze informacije o studentima: prvo broj studenata, a zatim u pojedinacnim linijama
korisnicko ime i pet poslednjih ocena koje je student dobio. Napisati program koji pronalazi studenta koji je
ostvario najbolji uspeh i ispisuje njegove podatke. Pretpostaviti da broj studenata nece biti veci od 100. */

#include<stdio.h>

#define MAXS 100

/*Definisemo strukturu za cuvanje studenata*/
typedef struct st{
  char korisnicko_ime[8];
  float prosek;
}STUDENT;

int main() {
  
  FILE *ulaz;
  STUDENT studenti[MAXS];
  
  int ocena1,ocena2,ocena3,ocena4,ocena5, i=0, i_max_prosek;
  float max_prosek = 0;
  
  /*Otvaramo datoteku studenti.txt za citanje*/
  ulaz = fopen("studenti.txt", "r");
  if(ulaz == NULL){
	printf("Greska pri otvaranju datoteke!\n");
	return 0;
  }
  
  /*Ucitavamo liniju po liniju iz datoteke, sve dok ne dodjemo do kraja.
   Korisnicko ime smestamo u niz, a ocene ucitavamo u pomocne promenljive ocena1,...ocena5.
   Zatim, na osnovu ocena racunamo prosek.
   
   Ovde paralelno sa ucitavanjem pronalazimo i studenta sa najvecim prosekom i 
   pamtimo njegov prosek i njegovu poziciju u nizu studenata,
   Nismo morali ovako. Mogli smo i prvu da ucitamo sve studente, a zatim da prodjemo 
   jednom kroz niz i da nadjemo onog sa najvecim prosekom.
   
   */
  while(fscanf(ulaz, "%s%d%d%d%d%d", studenti[i].korisnicko_ime, &ocena1, &ocena2, &ocena3, &ocena4, &ocena5) != EOF){
	studenti[i].prosek = (ocena1 + ocena2 + ocena3 + ocena4 + ocena5)/5.0;
	
	if(studenti[i].prosek > max_prosek){
	   max_prosek= studenti[i].prosek;
	   i_max_prosek = i;
	}
	i++;
  }
  
  /*Ispisujemo rezultat*/
  printf("korisnicko ime: %s, prosek ocena: %.2f\n", studenti[i_max_prosek].korisnicko_ime, studenti[i_max_prosek].prosek);
  
  /*Zatvaramo datoteku*/
  fclose(ulaz);
 
  return 0;
}
