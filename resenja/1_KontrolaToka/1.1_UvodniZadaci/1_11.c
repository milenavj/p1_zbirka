#include <stdio.h>
#include <limits.h>

/* u zaglavlju limits.h 
su definisane maksimalne i minimalne 
vrednosti za svaki tip podataka
npr. INT_MAX konstanta je najveci ceo
broj koji moze da se stavi 
u promenljivu tipa int
zbog toga za poslednji test primer 
ne dobijamo zeljeni broj
jer je doslo do prekoracenja 
novibroj je veci od INT_MAX
*/

/* test primeri:
broj:	140
c1:	2
c2:	3

novibroj:	13240
----------------------
broj:	526
c1:	7
c2:	4

novibroj:	54726
----------------------
broj:	25
c1:	9
c2:	5

novibroj:	5925	
----------------------
test primer koji dovodi do prekoracenja, pa zbog toga
ne dobijamo zeljeni rezultat:

broj:	100000000
c1:	5
c2:	1

novibroj:	neocekivan rezultat ---> PREKORACENJE

*/

int main(){
int broj,c1,c2,z1,z2;
int novibroj;
int dostatak1, dostatak2 ;
printf("unesi broj: ");
scanf("%d", &broj);
printf("unesi c1: ");
scanf("%d", &c1);
printf("unesi c2: ");
scanf("%d", &c2);

z1 = 100;

dostatak1 = broj % z1;

/*
 levi ostatak je u stvari ovaj deo --> broj / z1 * z1 * 10
 inace taj deo moze da se racuna i kao --> (broj - broj % z1) * 10 
*/
novibroj = broj / z1 * z1 * 10 + z1 * c1 + dostatak1 ;

/* sada u novibroj insertujemo cifru c2 na poziciju 4 - za hiljade */

z2 = 1000;

dostatak2 = novibroj % z2;

/*
 levi ostatak je u stvari ovaj deo --> broj / z2 * z2 * 10
 inace taj deo moze da se racuna i kao --> (broj - broj % z2) * 10 
*/
novibroj = novibroj / z2 * z2 * 10 + z2 * c2 + dostatak2 ;

printf("Novi broj je: %d\n", novibroj);
printf("Maksimalna vrednost za int je: %d\n", INT_MAX);

return 0; 
}
