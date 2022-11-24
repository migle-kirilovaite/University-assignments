#include <stdio.h>

int main()
{
    int n = 0;
    int array[100];

    printf("Iveskite kiek norite skaiciu: \n");

    scanf("%d", &array[n]);
    
    while (array[n] >= 0) 
    {  
        n++;
        scanf("%d", &array[n]);
    }

    printf("Duomenys ivesti sekmingai. Skaiciuojama...\n");
    printf("Ivesti pirminiai skaiciai: \n");

    for(int i = 0; i < n; ++i)
    {   
        int counter = 0;

        for(int j = 1; j <= array[i]; ++j)
        {
            if(array[i] % j == 0)
                counter++;
        }

        if(counter == 2 || array[i] == 1)
            printf("%d ", array[i]);
    }

    return 0;
}