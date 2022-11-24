#include <stdio.h>

int main()
{
    int num; 
    int most_digits;
    char character;

    printf("Iveskite skaiciu seka: \n" );

    // Ivedamas pirmasis sekos skaicius bei tikrinamas
    if((scanf("%d%c", &num, &character) != 2) || (character != '\n')) 
    {
        printf("Netinkama ivestis! Iveskite sveika skaiciu! \n");
        while(getchar() != '\n');
        scanf("%d", &num);  
    }

    most_digits= num;
    
    while (num >= 0) // Ciklas vyksta tol kol sekos nariai nemazeja
    {   
        if((scanf("%d%c", &num, &character) != 2) || (character != '\n')) 
        {
            printf("Netinkama ivestis! Iveskite sveika skaiciu! \n");
            while(getchar() != '\n');
            scanf("%d", &num);  
        }   

        if(num > most_digits)
            most_digits = num;
    }

    printf("Daugiausiai skaitmenu turintis skaicius %d \n" , most_digits);

    return 0;
}