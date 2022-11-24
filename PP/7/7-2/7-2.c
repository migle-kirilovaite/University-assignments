#include <stdio.h>

int getFactorial(int number)
{
    if (number > 0)
    {
        int factorial = 1;
        while (number > 0)
        {
            factorial = factorial * number;
            --number;
        }
        return factorial;
    }
    else 
        return 0;
}

int main()
{
    int number;
    scanf("%d", &number);
    printf("%d", getFactorial(number));
    
    return 0;
}