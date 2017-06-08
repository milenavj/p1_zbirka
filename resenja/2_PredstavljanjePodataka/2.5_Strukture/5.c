#include <stdio.h>

typedef struct
{
	int brojilac;
	int imenilac;
}razlomak;

int nzd(int a, int b)
{
	int pom;

	if (a < b)
	{
		pom = a;
		a = b;
		b = pom;
	}

	while(b != 0)
	{
		pom = a % b;
		a = b;
		b = pom;
	}

	return a;
}

razlomak zbir(razlomak a, razlomak b)
{
	razlomak c;
	int nzd_razlomka;

	c.brojilac = a.brojilac * b.imenilac + b.brojilac*a.imenilac;
	c.imenilac = a.imenilac*b.imenilac;

  /* Brojilac i imenilac dobijenog zbira se dele najvecim zajednickim
   * deliocom.
   */
	nzd_razlomka = nzd(c.brojilac, c.imenilac);

	c.brojilac = c.brojilac/nzd_razlomka;
	c.imenilac = c.imenilac/nzd_razlomka;

	return c;
}

razlomak proizvod(razlomak a, razlomak b)
{
	razlomak c;
	int nzd_razlomka;

	c.brojilac = a.brojilac*b.brojilac;
	c.imenilac = a.imenilac*b.imenilac;

  /* Brojilac i imenilac dobijenog zbira se dele najvecim zajednickim
   * deliocom.
   */
	nzd_razlomka = nzd(c.brojilac, c.imenilac);

	c.brojilac = c.brojilac/nzd_razlomka;
	c.imenilac = c.imenilac/nzd_razlomka;

	return c;
}

int main()
{
	int n, i;

	razlomak suma, proizvod_svih, r;

	printf("Unesi broj razlomaka: ");
	scanf("%d", &n);


	suma.brojilac = 0;
	suma.imenilac = 1;

	proizvod_svih.brojilac = 1;
	proizvod_svih.imenilac = 1;

	printf("Uneti razlomke:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d%d", &r.brojilac, &r.imenilac);

		suma = zbir(suma, r);
		proizvod_svih = proizvod(proizvod_svih, r);
	}

	printf("Suma svih razlomaka je %d/%d.\n", suma.brojilac, suma.imenilac);
	printf("Proizvod svih razlomaka je %d/%d.\n", proizvod_svih.brojilac, proizvod_svih.imenilac);

	return 0;
}
