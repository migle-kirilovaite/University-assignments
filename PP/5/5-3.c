#include <stdio.h>

int main()
{
    int  n;
    double s, xj;

    printf("Iveskite 2 skaiciu: \n");
    scanf("%lf%d", &s, &n);

    int array[n];

    for(int i = 0; i < n; ++i)
    {   
        scanf("%d", &array[i]);

        if(array[i] < 0)
        {
            printf("Iveskite teigiama skaiciu!! \n");
            scanf("%d", &array[i]);
        }     
    }

    printf("Duomenys ivesti sekmingai. Skaiciuojama...\n");
    printf("Masyve esancios skaiciu poros: \n");

    for(int i = 0; i < n; ++i)
    {
        xj = s / array[i];

        printf("(%d, %f)\n", array[i], xj);
    }

    return 0;
}