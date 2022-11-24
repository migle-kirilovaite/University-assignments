/* 
   LSP: 2213745 
   Email: migle.kirilovaite@mif.stud.vu.lt
   Uzd. Nr.: 1
   Variantas: 1 (Įvedinėti sveikų skaičių seką tol, kol ji nemažėja. Išvesti sekos narių skaičių ir jų aritmetinį vidurkį.)
*/ 

#include <stdio.h>
#include <limits.h>

int validation (int num)
{   
    char character;

    if((scanf("%d%c", &num, &character) != 2) || (character != '\n')) 
    {
        printf("Netinkama ivestis! Iveskite sveika skaiciu! \n");
        while(getchar() != '\n'); 
        num = validation(num);
    }

    return num;
}

int main()
{
    int num; 
    int previous_num = INT_MIN; 
    int sequence_num_amount = 0; 
    double sum = 0; 
    
    printf("Iveskite skaiciu seka: \n" );

    // Ivedamas pirmasis sekos skaicius bei tikrinamas
    num = validation (num);
    
    while (num >= previous_num) // Ciklas vyksta tol kol sekos nariai nemazeja
    {   
        sum = sum + num; 
        sequence_num_amount ++; 
        previous_num = num; 

        num = validation (num); 
    }

    sum = sum + num; 
    sequence_num_amount ++; 

    printf("Ivestas mazesnis skaicius, pereinama prie skaiciavimu... \n" );

    //Isvedimas
    printf("Skaiciu sekos nariu skaicius: %d \n" , sequence_num_amount);
    printf("Aritmetinis vidurkis: %f \n" , sum/sequence_num_amount);

    return 0;
}