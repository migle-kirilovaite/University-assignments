#include <stdio.h>

int main()
{
    int num, num1;

    printf ("Iveskite sveikaji skaiciu: \n");
    scanf("%lld", &num);

    for (int digit=0; digit<10; digit++)
        for (int temp=num; temp>0; temp/=10)
            if (temp%10 == digit) printf("%d", digit);

    printf(" \n");

    return 0;
}