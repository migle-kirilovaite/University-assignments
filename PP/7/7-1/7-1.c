#include <stdio.h>

int isInRange(int number, int low, int high)
{
    int true = 1;
    int false = 0;
    if (low < high && number >= low && number <= high )
        return true;
    else 
        return false;
}

int main()
{
    int number, low, high, result;
    scanf("%d%d%d", &number, &low, &high);
    result = isInRange(number, low, high);
    return 0;
}