#include <stdio.h>
#include <ctype.h>

/* Funkcija za ispis elemenata niza. */
void ispis(int niz[], int n)
{
	int i;

	for(i = 0; i < n; i++)
		printf("%c:%d  ", 'a' + i, niz[i]);  
	putchar('\n');
}

int main()
{ 
	/* Niz u kojem ce se cuvati informacije o broju pojavljivanja malih slova. */
	int mala_slova[26];  
	int c, i;

	for(i=0;i<26;i++)
		mala_slova[i]=0;   

	/* Ucitavaju se karakteri sve do kraja ulaza. */
	while((c = getchar()) != EOF)
	{
		/* Ako je procitani karakter slovo broj pojavljivanja slova se uvecava. Kako se zanemaruje velicina slova, svako slovo se pretvori u malo i potom se element na odgovarajucoj poziciji u nizu uveca. */
		if (isalpha(c))
			mala_slova[tolower(c)-'a']++;
	}

	/* Ispisuju se trazene informacije. */
	ispis(mala_slova, 26); 

	return 0;
}
