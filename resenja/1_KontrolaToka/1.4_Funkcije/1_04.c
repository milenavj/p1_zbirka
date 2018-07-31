#include <stdio.h>

float zbir_reciprocnih(int n)
{
  float z=0;
  int i;
  for(i=1;i<=n;i++)
    /* Reciprocna vrednost broja je jednaka deljenju broja 1 sa tim brojem. Ipak, zbog specificnosti jezika C, 1/broj bi bilo celobrojeno deljenje (jer je 1 ceo broj i broj je ceo broj), pa bi rezultat bio ceo broj, a ne realan. Da bi izbegli takvo ponasanje deljenik ce biti 1.0 umesto 1, cime se obezbedjuje da se deljenik posmatra kao realan broj i da vrednost kolicnika bude realan broj. */
    z+=1.0/i;  
  return z;    
}

int main()
{
  int n;
  printf("Unesi jedan pozitivan ceo broj:\n");
  scanf("%d", &n);
  /* Povratna vrednost funkcije zbir_reciprocnih je float. Funkcija moze biti pozvana u okviru poziva druge funkcije, pa tako se funkcija zbir_reciprocnih poziva u okviru funkcije printf i umesto specifikatora %.2f bice ispisana povratna vrednost funkcije zbir_reciprocnih zaokruzena na dve decimale. */
  printf("Zbir je %.2f\n", zbir_reciprocnih(n));
  
  return 0;
}
