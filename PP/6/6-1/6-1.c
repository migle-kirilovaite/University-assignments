#include <stdio.h>
#include <stdlib.h>

int validation (int num)
{   
    char character;

    if((scanf("%d%c", &num, &character) != 2) || (character != '\n')) 
    {
        printf("Ivestos raides, iveskite tik sveika skaiciu! \n");
        while(getchar() != '\n'); 
        num = validation(num);
    }

    if(num <= 0) 
    {
        printf("Ivestas nulis arba neigiamas skaicius, iveskite tik sveika skaiciu! \n");
        while(getchar() != '\n'); 
        num = validation(num);
    }

    return num;
}

int factorial_fuction(int num, int factorial)
{
    
    while(num > 0)
    {
        factorial = factorial * num;
        --num;
    }

    return factorial;
}

void output_into_file(int factorial)
{
    FILE *out_file = fopen("out.txt", "w");

    if (out_file == NULL) 
            {   
              printf("Error! Failas nerastas\n"); 
              exit(-1); 
            } 

    fprintf(out_file, "Ivesto skaiciaus faktorialas: %d", factorial);  
    fclose(out_file);

    printf("Isvestis i faila ivykdyta sekmingai. Failas uzdarytas\n");
}

int main()
{
    int num;
    int factorial = 1;

    printf("Programa apskaiciuoja ivesto skaiciaus faktoriala \n");
    printf("Iveskite viena teigiama skaiciu: ");

    num = validation(num);

    printf("Duomenys sekmingai nuskaityti! \n");

    factorial = factorial_fuction(num, factorial);

    printf("Ivesto skaiciaus faktorialas: %d \n", factorial);

    output_into_file(factorial);

    return 0;
}