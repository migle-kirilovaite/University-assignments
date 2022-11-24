#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c; 
    int fc;
    char character;

    printf("Iveskite tris skaicius: \n");

    if(scanf("%d", &a), a < 0)
    {   
        while (a < 0)
        {
            printf("Iveskite neneigiama sveika skaiciu! \n");
            scanf("%d", &a);  
        }
        
    }

    if(scanf("%d", &b), b < 0)
    {
        while (b < 0)
        {
            printf("Iveskite neneigiama sveika skaiciu! \n");
            scanf("%d", &b);  
        }
    }

    if(scanf("%d", &c), c < 0)
    {   
        while (c < 0)
        {
            printf("Iveskite neneigiama sveika skaiciu! \n");
            scanf("%d", &c);  
        }
            
    }
    
    for(int i = 3; i <= c; ++i)
    {
        fc = a + b;
        a = b;
        b = fc;    
    }

    printf("Fibonacio sekos %d-asis skaicius: %d \n", c, fc);
    
    return 0;
}