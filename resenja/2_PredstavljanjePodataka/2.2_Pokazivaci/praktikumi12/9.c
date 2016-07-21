#include <stdio.h>

#define MAX 21

void modifikacija(char *s, char *t, int *br_modifikacija)
{
  int i;
  for(i=0;s[i];i++)
    if(s[i]>='a' && s[i]<='z')
    {
      t[i] = toupper(s[i]);
      (*br_modifikacija)++;
    }
    else
      t[i] = s[i];
}

int main()
{
  char s[MAX], t[MAX];
  int br_modifikacija = 0;

  printf("Unesite nisku: ");
  scanf("%s", s);

  modifikacija(s, t, &br_modifikacija);

  printf("Modifikovana niska je: %s\nBroj modifikacija je: %d\n", t, br_modifikacija);

  return 0;
}
