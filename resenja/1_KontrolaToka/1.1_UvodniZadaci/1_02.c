
#include<stdio.h>

int main()
{
      
   int x, y, rezultat; /* Promenljive istog tipa mogu se deklarisati jedna za drugom. */
   
   
   printf("Unesi vrednost celobrojne promenljive x:");
   scanf("%d", &x); /* "%d" - specifikator tipa koji treba uneti (%d za int) 
                       &x   - adresa promenljive x
                    */
   
   printf("Unesi vrednost celobrojne promenljive y:");
   scanf("%d", &y);
   
   /* 1) ispis unetih vrednosti */
   printf("x=%d, y=%d\n", x,y); /* umesto prvog %d bice ispisana vrednost promenljive x */
                                /* umesto drugog %d bice ispisana vrednost promenljive y */
   
   /* 2) ispis zbira */
   rezultat = x+y; /* dodelimo vrednost promenljivoj rezultat */
   printf("Zbir je %d\n", rezultat);
   
   /* 3) ispis razlike */ 
   printf("Razlika je %d\n",x-y); /* mozemo ispisivati direktno vrednost izraza x-y i bez */
                                 /* njegovog dodeljivanja posebnoj promenljivoj */
                                 
   
   /* 4) ispis proizvoda */
   printf("%d*%d=%d\n",x,y,x*y);
   
   /* 5) ispis kolicnika */
   rezultat = x/y; 
   printf("celobrojno deljenje: %d/%d=%d\n",x,y,rezultat); /* promenljiva rezultat je celobrojna (int) */
                                                           /* ona ne moze sadrzati realan broj */
                                                           /* ukoliko je x=7, a y=2, tada ce nakon naredbe */
                                                           /* rezultat=x/y; promenljiva rezultat imati vrednost 2 */
                                                           /* a ne 2.5 */
                                                           
   printf("ostatak pri celobrojnom deljenju: %d %% %d=%d\n",x,y,x%y);
                                                           /* operator % izracunava ostatak pri celobrojnom deljenju */
                                                           /* 7%2 ima vrednost 1 (jer je 7=3*2+1) */
                                                           /* oznaku % u naredbi printf pisemo %% */
   return 0;
}