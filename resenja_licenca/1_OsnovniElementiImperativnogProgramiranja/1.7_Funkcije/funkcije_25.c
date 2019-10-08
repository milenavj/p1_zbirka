/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

/* Funkcija proverava da li je godina prestupna. */
int prestupna(int godina) {
  if ((godina % 100 != 0 && godina % 4 == 0) || godina % 400 == 0)
    return 1;
  else
    return 0;
}

/* Funkcija odredjuje broj dana u datom mesecu. */
int broj_dana(int mesec, int godina) {
  switch (mesec) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
  case 2:
    if (prestupna(godina))
      return 29;
    else
      return 28;
  }
  return -1;
}

/* Funkcija proverava da li je datum ispravan. Ako je datum
   ispravan funkcija vraca 1, inace vraca 0. */
int ispravan(int dan, int mesec, int godina) {
  /* Ako je godina negativna, datum nije ispravan. */
  if (godina < 0)
    return 0;

  /* Ako mesec nije u opsegu od 1 do 12, datum nije ispravan. */
  if (mesec < 1 || mesec > 12)
    return 0;

  /* Ako je dan manji od 1 ili veci od broja dana u datom mesecu,
     datum nije ispravan. */
  if (dan < 1 || dan > broj_dana(mesec, godina))
    return 0;

  return 1;
}

/* Funkcija racuna sledeci dan. */
void sledeci_dan(int dan, int mesec, int godina) {
  /* Za kraj godine, odnosno za datum 31.12. sledeci datum je 1.1.
     i godina se uvecava za jedan. */
  if (mesec == 12 && dan == 31)
    printf("1.1.%d.\n", godina + 1);
  /* Ukoliko je dan jednak poslednjem danu u tom mesecu, odnosno
     ako je jednak broju dana u tom mesecu, onda je sledeci datum
     kada se mesec uveca za 1, a dan postane 1. Bitan je redosled
     ovih naredbi. Ako bi ovo ispitivanje bilo prvo, onda bi se
     mesec mogao uvecati na 13. sto ne bi bio ispravan datum. Zato
     se prvo proverava da li je kraj godine, pa tek onda da li je
     kraj meseca. */
  else if (dan == broj_dana(mesec, godina))
    printf("1.%d.%d.\n", mesec + 1, godina);
  /* Ako nije ni jedan od prethodna dva slucaja, onda se dan moze
     uvecati na 1, bez bojazni da ce se prekoraciti broj dana u
     datom mesecu. */
  else
    printf("%d.%d.%d.\n", dan + 1, mesec, godina);
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int dan, mesec, godina;

  /* Ucitavanje vrednosti dana, meseca i godine. */
  printf("Unesite datum:");
  scanf("%d.%d.%d.", &dan, &mesec, &godina);

  /* Provera ispravnosti datuma. */
  if (!ispravan(dan, mesec, godina)) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Poziv funkcije za ispis sledeceg dana. */
  printf("Datum sledeceg dana je:");
  sledeci_dan(dan, mesec, godina);

  return 0;
}
