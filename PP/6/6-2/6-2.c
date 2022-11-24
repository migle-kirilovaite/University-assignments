#include <stdio.h>
#include <stdlib.h>

void new_file(char new_name[])
{
    printf("Iveskite naujo failo varda, kuriame pateikti tinkami duomenys: ");
    scanf("%s", new_name);
}

void validation (int *num, int *decimals_after_comma, char new_name[], FILE *in_file)
{   
    
    char character;
    int num1,decimals_after_comma1;
    fscanf(in_file, "%d%c%d", &num1, &character, &decimals_after_comma1);

    if(num1 < 10 || num1 > 1000) 
    {
        printf("Faile ivestas permazas arba perdidelis skaicius (arba nieko), skaicius turi buti bet koks realusis nuo 10 iki 1000 \n");
        fclose(in_file);
        new_file(new_name);
        in_file = fopen(new_name, "r");
        validation(num1, decimals_after_comma1, new_name, in_file);
    }
    else if(decimals_after_comma1 >= 999)
    {
        printf("Faile ivestas skaicius turi daugiau negu trys skaitmenis po kablelio \n");
        fclose(in_file);
        new_file(new_name);
        in_file = fopen(new_name, "r");
        validation(num1, decimals_after_comma1, new_name, in_file);
    }
    else 
    {
        printf("Skaicius nuskaitytas sekmingai!\n");
        *num = num1;
        *decimals_after_comma = decimals_after_comma1;
    }     
}

void input(int *num, int *decimals_after_comma)
{   
    char new_name[20];
    int num1, decimals_after_comma1;
    FILE *in_file = fopen("in.txt", "r");
    while(in_file == NULL)
    {   
        printf("Failas nerastas.\n"); 
        fclose(in_file);
        new_file(new_name);
        in_file = fopen(new_name, "r");
    } 

    printf("Failas sekmingai nuskaitytas!\n"); 

    validation(&num1, &decimals_after_comma1, new_name, in_file);
    fclose(in_file);

    *num = num1;
    *decimals_after_comma = decimals_after_comma1;

}

int count_digits(int num)
{
    int count = 0;
    do {
    num /= 10;
    ++count;
    } while (num != 0);

    return count;
}

int main()
{
    int num, decimals_after_comma;

    input(&num, &decimals_after_comma);

    printf("Faile ivesto skaiciaus ilgis: %d", count_digits(num)+count_digits(decimals_after_comma));

    return 0;
}