//Programa skirta pasitikrinimui 2.2a ats.

#include <stdio.h>

int main()
{
    int num, decimalnum=0, exp=1, num1;; //Nuskaitomas skaicius, desimtainis skaicius, kelimo laipsnis, papildomas kintamasis num reiksmes issaugojimui

    printf("Iveskite dvejataines sistemos skaicius kuriuos norite paversti i desimtaine: \n");

    //a)

    for(int i=1; i<=3; i++) //ciklas veikia tris kartus kadangi 2.2a uzduotyje yra po 3 skaicius 
    {
        scanf("%d", &num);
        
        while (num>0)
        {
            num1=num%10;
            decimalnum=decimalnum+num1*exp;
            num=num/10;
            exp=exp*2;
        }

        printf("Desimtainis skaicius: %d ", decimalnum);

        exp=1;
        decimalnum=0;
    }

    //b)

    printf("Iveskite desimtaines sistemos skaicius kuriuos norite paversti i dvejetaine: \n");

    int binarynum[32]={0};

    for(int i=1; i<=3; i++)
    {
        scanf("%d", &num);

        int j=0;
        
        while (num>0)
        {
            binarynum[j++] = num % 2;
            num/=2;
        }
        printf("Dvejetainis skaicius:");

        for (int k = j-1; k >= 0; k--)
            printf("%d", binarynum[k]);
        
        printf("\n");
    }

    //c)

    printf("Iveskite sesioliktaines sistemos skaicius kuriuos norite paversti i desimtaine: \n");

    for(int i=1; i<=3; i++)
    {
        scanf("%x", &num);

        printf("Desimtainis skaicius: ");

        printf("%d \n", num);
    }
    
    //d)

    printf("Iveskite desimtainbes sistemos skaicius kuriuos norite paversti i sesioliktaine: \n");

    for(int i=1; i<=3; i++)
    {
        scanf("%d", &num);

        printf("Sesioliktainis skaicius: ");

        printf("0x%x \n", num);
    }

    return 0;
}