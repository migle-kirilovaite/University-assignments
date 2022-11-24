#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c; 
    char character;
    int min, max; 
    int gcd, lcm;

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

    if(a < b && a < c)  
        min = a;
    if(b < a && b < c)  
        min = b;
    else
        min = c;

    if(a > b && a > c)  
        max = a;
    if(b > a && b > c)  
        max = b;
    else
        max = c;

    for(int i = 1; i <= min; ++i)
    {
        if(a % i == 0 && b % i == 0 && c % i == 0)
            gcd = i;
    }

    printf("DBD: %d \n", gcd);

    while(1)
    {
        if(max % a == 0 && max % b == 0 && max % c == 0) 
        {
            lcm=max;
            printf("MBK: %d", lcm);
            break;
        }
        else 
            ++max;
    }

    return 0;
}