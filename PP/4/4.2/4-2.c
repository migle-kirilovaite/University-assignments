#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c; 
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

    printf("Intervalo (%d;%d] sveikieji skaiciai kurie dalijasi is %d su liekana 1: ", a, b, c);
    for(int i = a + 1 ; a <= b; ++a)
    {
        if(a % c == 1)
        {
            printf("%d ", a);
        }
    }

    return 0;
}