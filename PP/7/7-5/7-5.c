#include <stdio.h>

long getFileSize(char *fileName)
{
    fileName = "input.txt";
    long size;
    FILE *in_file = fopen(fileName, "r");
    if (fileName != NULL)
    {
        fseek(in_file, 0, SEEK_END);
        size = ftell(in_file);
        fclose(in_file);
        return size;
    }
    else 
        return -1;
}

int main()
{
    char fileName;
    long size;
    size = getFileSize(&fileName);

    printf("%d", size);

    return 0;
}