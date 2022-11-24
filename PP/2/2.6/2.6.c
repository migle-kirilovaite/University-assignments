#include <stdio.h>

int main()
{
    int num;
    int min;
    int max;

    for(int i=0; i<3; i++)
    {
        scanf("%d", &num);
        (i!=0) ?(min=(num<min)? min=num : min, max=(num>max)? max=num : max) : (min=num, max=num);
    }

    printf ("Maksimali reiksme %d, minimali reiksme %d. \n", max, min);

    return 0;
}