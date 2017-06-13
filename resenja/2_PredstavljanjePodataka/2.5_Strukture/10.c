#include <stdio.h>
#include <math.h>

#define MAX_TACAKA 1000

typedef struct
{
	int x, y;
}TACKA;

double rastojanje(TACKA a, TACKA b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

unsigned ucitaj_poligon(TACKA* tacke, unsigned n)
{
	int i = 0;

	while(i < n && scanf("%d%d", &tacke[i].x, &tacke[i].y) != EOF)
		i++;

	return i;
}

double obim(TACKA* poligon, unsigned n)
{
	double o = rastojanje(poligon[0], poligon[n-1]);
	int i;

	for(i=0; i<n-1; i++)
		o += rastojanje(poligon[i], poligon[i+1]);

	return o;
}

double maksimalna_stranica(TACKA* poligon, unsigned n)
{
	double max = rastojanje(poligon[0], poligon[n-1]);
	double stranica;
	int i;

	for(i=0; i<n-1; i++)
	{
		stranica = rastojanje(poligon[i], poligon[i+1]);
		if (stranica > max)
			max = stranica;
	}

	return max;
}

double povrsina_trougla(TACKA A, TACKA B, TACKA C)
{
	double a = rastojanje(B, C);
	double b = rastojanje(A, C);
	double c = rastojanje(A, B);

	double s = (a + b + c)/2;

	return sqrt(s*(s -a)*(s - b)*(s - c));
}

double povrsina(TACKA* poligon, unsigned n)
{
	double P = 0;
	int i;

	for(i=1; i<n-1; i++)
		P += povrsina_trougla(poligon[0], poligon[i], poligon[i+1]);

	return P;
}

int main()
{
	int N;
	unsigned m;
	TACKA poligon[MAX_TACAKA];

	printf("Uneti maksimalan broj tacaka poligona: ");
	scanf("%d", &N);

	if (N < 3 || N > MAX_TACAKA)
	{
		printf("Neispravan broj tacaka poligona.\n");
		return -1;
	}

	m = ucitaj_poligon(poligon, N);

	if (m < 3)
	{
		printf("Neispravan broj tacaka poligona.\n");
		return -1;
	}

	printf("Obim poligona je %.3lf.\n", obim(poligon, m));
	printf("Duzina maksimalne stranice je %.3lf.\n", maksimalna_stranica(poligon, m));
	printf("Povrsina poligona je %.3lf.\n", povrsina(poligon, m));

	return 0;
}
