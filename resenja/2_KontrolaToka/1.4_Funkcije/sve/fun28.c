#include<stdio.h>


/* Funkcija koja proverava da li je godina prestupna. */
int prestupna(int godina)
{
  if ((godina % 100 != 0 && godina % 4 == 0) || godina % 400 == 0)
    return 1;
  else
    return 0;
}


/* Funkcija odredjuje broj dana u datom mesecu. */
int broj_dana(int mesec, int godina)
{
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
int ispravan(int dan, int mesec, int godina)
{
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


/* Funkcija odredjuje koliko dana je proteklo od pocetka godine. */
int od_nove_godine(int dan, int mesec, int godina)
{
  int suma_dana = 0, i;

  /* Za sve mesece pre datog datuma dodaje se broj dana za dati
     mesec. */
  for (i = 1; i < mesec; i++)
    suma_dana += broj_dana(mesec, godina);

  /* Na kraju se dodaje koliko je dana proteklo u datom mesecu, a
     to je zadato sa promenljivom dan. */
  return suma_dana + dan;
}


/* Funkcija odredjuje koliko dana ima do kraja godine. */
int do_kraja_godine(int dan, int mesec, int godina)
{
  int suma_dana = 0, i;

  /* Za sve mesece posle datog datuma dodaje se broj dana za dati
     mesec. */
  for (i = mesec + 1; i <= 12; i++)
    suma_dana += broj_dana(mesec, godina);

  /* Na kraju se dodaje koliko je dana je ostalo u datom mesecu. */
  return suma_dana + broj_dana(mesec, godina) - dan;
}


/* Funkcija vraca 1 ako je prvi datum pre drugog datuma. U
   suprotnom vraca 0. */
int prethodi(int dan1, int mesec1, int godina1, int dan2,
             int mesec2, int godina2)
{
  if (godina1 < godina2)
    return 1;
  else if (godina1 > godina2)
    return 0;
  else if (mesec1 < mesec2)
    return 1;
  else if (mesec1 > mesec2)
    return 0;
  else if (dan1 < dan2)
    return 1;
  else
    return 0;
}


/* Funkcija vraca broj dana u datoj godini. */
int broj_dana_u_godini(int godina)
{
  if (prestupna(godina))
    return 366;
  else
    return 365;
}


/* Funkcija koja racuna broj dana izmedju dva datuma. */
int broj_dana_izmedju(int dan1, int mesec1, int godina1, int dan2,
                      int mesec2, int godina2) {
  int pom, i;
  int suma_dana = 0;

  /* Vrsi se provera koji od datuma je ranije i ukoliko je to
     potrebno, razmenjuju se tako da broj 1 ide uz prvi datum. */
  if (!prethodi(dan1, mesec1, godina1, dan2, mesec2, godina2)) {
    pom = dan1;
    dan1 = dan2;
    dan2 = pom;

    pom = mesec1;
    mesec1 = mesec2;
    mesec2 = pom;

    pom = godina1;
    godina1 = godina2;
    godina2 = pom;
  }

  /* Ako su godine razlicite. */
  if (godina1 != godina2) {
    /* Za manji datum dodaje se broj dana do kraja godine. */
    suma_dana = do_kraja_godine(dan1, mesec1, godina1);

    /* Za sve godine koje su izmedju dve date godine dodaje se broj 
       dana u tim godinama. */
    for (i = godina1 + 1; i < godina2; i++)
      suma_dana += broj_dana_u_godini(i);

    /* Za veci datum dodaje se broj dana od pocetka godine. */
    suma_dana += od_nove_godine(dan2, mesec2, godina2);
  }
  /* Ako su godine iste, ali meseci razliciti. */
  else if (mesec1 != mesec2) {
    /* Dodaje se broj dana do kraja prvog meseca. */
    suma_dana = broj_dana(mesec1, godina1) - dan1;

    /* Dodaje se broj dana za svaki mesec koji je izmedju dva data
       meseca. Kako su godina1 i godina2 jednake svejedno je koja
       od ove dve promenljive se koristi u pozivu funkcije. */
    for (i = mesec1 + 1; i < mesec2; i++)
      suma_dana += broj_dana(i, godina1);

    /* Dodaje se broj dana od pocetka meseca. */
    suma_dana += dan2;
  }
  /* Ako su i godine i meseci jednaki. */
  else
    suma_dana = dan2 - dan1;

  return suma_dana;
}


int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int dan1, mesec1, godina1, dan2, mesec2, godina2;

  /* Ucitavaju se datumi. */
  printf("Unesite prvi datum:");
  scanf("%d.%d.%d.", &dan1, &mesec1, &godina1);

  printf("Unesite drugi datum:");
  scanf("%d.%d.%d.", &dan2, &mesec2, &godina2);

  /* Vrsi se provera ispravnosti unetih datuma. */
  if (!ispravan(dan1, mesec1, godina1)
      || !ispravan(dan2, mesec2, godina2)) {
    printf("Uneti datum nije ispravan.\n");
    return -1;
  }

  /* Ispis rezultata. */
  printf("Broj dana izmedju dva datuma je: %d\n",
         broj_dana_izmedju(dan1, mesec1, godina1, dan2, mesec2,
                           godina2));

  return 0;
}
