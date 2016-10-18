#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    double P;
    double x, a;
    
    printf("Unesite dva relana broja x i a: ");
    scanf("%lf%lf", &x, &a);
    
    printf("Unesite prirodan broj: ");
    scanf("%d", &n);
    
    if (n <= 0)
    {
        printf("Neispravan unos.\n");
        return -1;
    }
    
    P = x;
    for(i=0; i<n; i++)
        P = (P+a)*(P+a);
    
    printf("Izraz = %lf\n", P);
    
    return 0;
}