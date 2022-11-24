#include <stdio.h>

void biggestFileSize(int *max, int argc, char *argv[])
{
    int sz;

    for(int i = argc - 1; i > 0; --i)
    {
        FILE * fp = fopen(argv[i], "r");

        fseek(fp, 0L, SEEK_END);
        sz = ftell(fp);

        if (sz > *max)
            *max = sz;

        fclose(fp);
    }
}

int main(int argc, char *argv[])
{
    int max = 0, sz;

    biggestFileSize(&max, argc, argv);

    return 0;
}