#include <stdio.h>

int main()
{
    //a)
    int array[10]={0}; 
    
    //b)
    for(int i = 0; i < 10; ++i) 
    {
        printf("%d ", array[i]);
    }
    
    printf ("\n");
    
    //c)
    array[0] = 1;
    array[3] = 2;
    array[9] = 3;
    
    //d)
    for(int i = 2; i < 10; ++i)
    {
        array[i] = array[i+1];
    }
    
    array[9] = 0;
    
    //e)
    for(int i = 9; i > 6; --i)
    {
        array[i] = array[i-1];
    }
    
    array[6] = 4;
    
    //f)
    for(int i = 0; i < 10; ++i) 
    {
        printf("%d ", array[i]);
    }
    
    printf ("\n");
    
    //g)
    int x, y;

    printf("Iveskite 2 skaicius: \n");
    scanf("%d%d", &x, &y);
    
    array[x] = y;

    for(int i = 0; i < 10; ++i) 
    {
        printf("%d ", array[i]);
    }
    
    printf ("\n");

    //h)
    printf("Iveskite skaiciu: \n");
    scanf("%d", &x);

    for(int i = x; i < 10; ++i)
    {
        array[i] = array[i+1];
    }
    
    array[9] = 0;

    for(int i = 0; i < 10; ++i) 
    {
        printf("%d ", array[i]);
    }
    
    printf ("\n");

    //i)
    printf("Iveskite 2 skaicius: \n");
    scanf("%d%d", &x, &y);

    for(int i = 9; i > x - 1; --i)
    {
        array[i] = array[i-1];
    }

    array[x] = y;

    //j)
    for(int i = 0; i < 10; ++i) 
    {
        printf("%d ", array[i]);
    }

    printf ("\n");

    return 0;
}