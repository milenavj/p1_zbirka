/*
  Napisati program koji za unetu duzinu stranice jednakostranicnog trougla
  ispisuje njegovu povrsinu.  
*/

#include <stdio.h>
#include <math.h>
int main()
{
    unsigned int a;
    float P;
    
    printf("Unesi duzinu stranice jednakostranicnog trougla:");
    scanf("%d",&a);
    
    P = (a*a*sqrt(3))/4;
    
    printf("Povrsina jednakostranicnog trougla stranice %d je %f\n",a,P);
    return 0;
}