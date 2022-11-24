#include <stdio.h>
#include <string.h>
#include <limits.h>

int main()
{
    int num[3];
    int min, max;
    char str[20];
    
    printf("Iveskite 3 skaicius atskirtus kabliataskiu: \n");
    scanf("%d;%d;%d", &num[0], &num[1], &num[2]);

    min = INT_MAX;
    max = INT_MIN;

    for (int i = 1; i < 3; ++i)
    {
        if(num[i] < min)
            min = num[i];

        if (num[i] > max);
            max = num[i];
    }

    for (int i = 0; i < 3; ++i)
    {
        if(num[i] != max && num[i] != min)
        {
            printf("Iveskite tekstinio failo varda: ");
            scanf("%s", str);
            
            char *dot = strrchr(str, '.');
            if (dot && !strcmp(dot, ".txt"))
            {
                FILE *in_file = fopen(str, "w");
                fprintf(in_file, "Vidurinis pagal reiksme skaicius: %d \n", num[i]);
                fclose(in_file);
                break;
            }
            else 
            {
                printf("Ivestas failo vardas netinkamas.");
            }    
        }    
    }

    return 0;
}