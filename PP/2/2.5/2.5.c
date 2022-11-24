#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z; 
    double a, b; //reiskiniu variantai

    printf("Iveskite x, y ir z reiksmes \n");
    scanf("%lf%lf%lf", &x, &y, &z);

    a=x+4*y+pow(z,3);
    b=(x+sqrt(y))*(pow(z,4)-fabs(z)+46.3);

    printf("a) %f, b) %f", a, b);

    return 0;
}