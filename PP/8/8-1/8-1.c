#include <stdio.h>
#include <stdlib.h> 

void generateArray(int * ptr, int size, int low, int high)
{
    for (int i = 0; i < size; ++i)
    {
        *(ptr + i)= (rand() % (high - low + 1)) + low;
    }
}

void createArray(int size, int low, int high)
{
    int *ptr = (int*) malloc(size * sizeof(int));

    generateArray(ptr, size, low, high); 
    
}

int main()
{
    createArray(size, low, high);

    return 0;
}