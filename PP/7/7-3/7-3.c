#include <stdio.h>

int getPositiveNumber(char *msg)
{
    int number;

    msg = "Iveskite teigiama skaiciu: ";
    printf("%s", msg);
    
    if ((scanf("%d", &number)) != 1)
    {
        while(getchar() != '\n'); 
        getPositiveNumber(msg);
    }
    else 
        return number;
}

int main()
{
    char msg;
    int number;
    number = getPositiveNumber(&msg);
    printf("%d", number);
    return 0;
}

