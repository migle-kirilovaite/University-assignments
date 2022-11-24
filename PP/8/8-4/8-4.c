#include <stdio.h>
#include <stdlib.h>

void splitData(int array[], int size, int firstPartSize, int *firstPartArr, int *secondPartArr)
{
    if(size > firstPartSize)
    {
        int *firstPart = (int*) malloc(firstPartSize * sizeof(int));
        int *secondPart = (int*) malloc((size - firstPartSize) * sizeof(int));

        for (int i = 0; i < firstPartSize; ++i)
        {
            *(firstPart + i) = array[i];
        }
        for (int i = 0; i < (size - firstPartSize); ++i)
        {
            *(secondPart + i) = array[firstPartSize+i];
        }

        firstPartArr =  firstPart;
        secondPartArr = secondPart;
}

int main()
{
    int size, firstPartSize;
    int array[];
    int firstPartArr[] = {}, secondPartArr[] = {};

    splitData(array, size, firstPartSize, firstPartArr, secondPartArr);

    return 0;
}