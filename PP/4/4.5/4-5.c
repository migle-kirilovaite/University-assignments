#include <stdio.h>

int main()
{
    int n;
    double num;
    double min, max;
    double sum = 0;
    
    printf("Iveskite pasirinkta kieki skaiciu: \n");
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i)
    {
        scanf("%lf", &num);
        
        sum+=num;
        
        if (i == 0)
        {
            min=num;
            max=num;
        }
        
        if(min > num)
            min=num;
        if(max < num)
            max=num;
    }
    
    printf("Suma: %lf \n", sum);
    printf("Vidurkis: %lf \n", sum/n);
    printf("Maziausias: %lf \n", min);
    printf("Didziausias: %lf \n", max);
    

    return 0;
}