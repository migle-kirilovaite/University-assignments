#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int array[1000] = {0};
    int a, b, c;
    int counter_a;

    printf ("Iveskite 3 skaicius: \n");
    scanf ("%d%d%d", &a, &b, &c);

    counter_a = a;

    srand(time(NULL));

    while(counter_a <= c)
    {
        array[counter_a] = rand() % (b + 1 - a) + a;
        ++counter_a;
    }

    while(a <= c)
    {
        printf("%d ", array[a]);
        ++a;
    }

    return 0;
}