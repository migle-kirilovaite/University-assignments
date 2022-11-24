#include <stdio.h>
#include <stdlib.h>

void generateArray(int data[], int size, int low, int high)
{
    for (int i = 0; i < size; ++i)
    {
        data[i] = (rand() % (high - low + 1)) + low;
    }

}

int main()
{
    int size = 3, low = 1, high = 9;
    int data[] = {};
    generateArray(data, size, low, high);
    return 0;
}