#include<stdio.h>
#include<math.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  char c;
  float x1, y1, x2, y2, x3, y3, x4, y4;
  float dab, dad;
  float delta, deltap, deltaq;
  float O;
  float k, n;

  printf("Unesi jedan karakter:");
  scanf("%c", &c);

  printf("Unesi realne koordinate 4 tacke:");
  scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

  switch (c) {
  case 'k':
    if (y1 == y2 && y3 == y4 && x1 == x4 && x2 == x3) {
      dab = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
      dad = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
      O = 2 * dab + 2 * dad;
      printf("Obim pravougaonika je %f\n", O);
    } else
      printf("Tacke ne cine pravougaonik sa stranicama "
             "koje su paralelne koordinatnim osama\n");
    break;
  case 'h':
    /* 
       Ukoliko se tacke A(x1,y1) i B(x2,y2) ne nalaze na pravoj
       koja je paralelna x osi, izracunamo k,n za pravu odredjenu
       tackama A(x1,y1) i B(x2,y2) */
    if ((x1 - x2) != 0) {
      k = (y1 - y2) / (x1 - x2);
      n = y1 - k * x1;
      /* 
         Proverimo da li tacke C(x3,y3) i D(x4,y4) nalaze na toj
         pravoj */
      if (y3 == x3 * k + n && y4 == x4 * k + n)
        printf("Tacke su kolinearne, pripadaju pravoj "
               "y=%f*x+%f\n", k, n);
      else
        printf("Tacke nisu kolinearne\n");
    }
    /* 
       Ukoliko se A i B nalaze na pravoj koja je paralelna x osi,
       proverimo da li tacke C(x3,y3) i D(x4,y4) nalaze na toj
       pravoj */
    else if (x3 == x1 && x4 == x1)
      printf("Tacke su kolinearne, pripadaju pravoj " "x=%f\n", x1);
    else
      printf("Tacke nisu kolinearne\n");
    break;
  case 'j':
    delta = x1 * y2 - x2 * y1;
    deltap = x2 * (y4 - y3) - y2 * (x4 - x3);
    deltaq = x1 * (y4 - y3) - y1 * (x4 - x3);
    if (delta != 0)
      printf("Sistem ima jedinstveno resenje %.2f, %.2f\n",
             deltap / delta, deltaq / delta);
    else if (deltap == 0 && deltaq == 0)
      printf("Sistem je neodredjen ili nema resenja.\n");
    else
      printf("Sistem nema resenja\n");
    break;
  default:
    printf("Nekorektan unos\n");
  }

  return 0;
}
