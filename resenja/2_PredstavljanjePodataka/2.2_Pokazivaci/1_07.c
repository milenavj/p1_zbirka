#include <stdio.h>

void suma(int a, int b, int *s);


int main()
{
    int a,b,s;
    
    scanf("%d%d",&a,&b);
    
    suma(a,b,&s);
    
    printf("suma: %d\n",s);
 
    return 0;
}

void suma(int a, int b, int *s)
{
    *s = a + b;
}