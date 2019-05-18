#include <stdio.h>

/* Argumenti komandne linije cuvaju se u nizu niski. Svaki element
   tog niza odgovara jednom argumentu komandne linije, pri cemu
   prvi element predstavlja naziv programa koji se pokrece.
   Celobrojna promenljiva argc predstavlja ukupan broj argumenata
   komandne linije ukljucujuci i argument koji odgovara nazivu
   programa, a promenljiva argv pomenuti niz niski koji sadrzi same 
   argumente. */
int main(int argc, char *argv[]) {
  /* Deklaracija potrebne promenljive. */
  int i;

  /* Ispis broja argumenata komandne linije. */
  printf("Broj argumenata je: %d\n", argc);

  /* Ispis svakog od navedenih argumenata. */
  for (i = 0; i < argc; i++)
    printf("%d: %s\n", i, argv[i]);

  return 0;
}
