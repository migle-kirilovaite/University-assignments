#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c; 
    double x1, x2;
    char character;

    printf("Iveskite tris skaicius: \n");

    if((scanf("%d%c", &a, &character) != 2) || (character != '\n')) 
    {
        printf("Netinkama ivestis! Iveskite sveika skaiciu! \n");
        while(getchar() != '\n');
        scanf("%d", &a);  
    }
    if((scanf("%d%c", &b, &character) != 2) || (character != '\n')) 
    {
        printf("Netinkama ivestis! Iveskite sveika skaiciu! \n");
        while(getchar() != '\n');
        scanf("%d", &b);  
    }
    if((scanf("%d%c", &c, &character) != 2) || (character != '\n')) 
    {
        printf("Netinkama ivestis! Iveskite sveika skaiciu! \n");
        while(getchar() != '\n');
        scanf("%d", &c);  
    }

    x1 = (-b + sqrt (pow (b,2) - 4 * a * c) ) / (2 * a);
    x2 = (-b - sqrt (pow (b,2) - 4 * a * c) ) / (2 * a);

    printf("Kvadratines lygties sprendimai: x1 = %lg x2 = %lg", x1, x2);

    return 0;
}