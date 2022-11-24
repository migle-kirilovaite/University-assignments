#include <stdio.h>

int main()
{
    int c = 0;
    int year, month, day;
    printf("Iveskite data YYYY-MM-DD formatu \n");

    while((scanf("%d-%d-%d", &year, &month, &day) != 3) ||
        year < 1 ||
        month < 1 ||
        month > 12 ||
        day < 1 ||
        day > 31)
    {
        printf("Netinkama ivestis. Iveskite data YYYY-MM-DD formatu \n");
        do 
        { 
            c = getchar(); 
        } while (c != '\n' && c != EOF);
    }

    FILE *in_file = fopen( "week.txt", "r");

    if (in_file == NULL)
    {
        printf("Failas negali buti atidarytas \n");
        return 1;
    }

    printf("Failas atidarytas sekmingai \n");

    int weekday  = (day += month < 3 ? year-- : year - 2, 23*month/9 + day + 4 + year/4- year/100 + year/400)%7;
    char weekday_name[30];

    if (weekday == 0)
    {
        fscanf(in_file, "%s", &weekday_name);
    }
    else
    {   
        for (int i = 0; i < weekday; ++i)
        {
            fscanf(in_file, "%s", &weekday_name);
        }
    }
    
    fclose(in_file);

    printf("Ivesta diena yra: %s \n", weekday_name);
    
    return 0;
}