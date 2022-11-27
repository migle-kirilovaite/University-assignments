#include <stdio.h>
#include <assert.h>

int strlen(char* string)
{
    int lenght = 0;

    while(*(string + lenght) != 0)
    {
        ++lenght;
    }

    return lenght;
}

int main()
{
    //assert(strlen("str") == 0); failed test
    assert(strlen("") == 0);
    assert(strlen("str") == 3);
    assert(strlen("string") > 0);

    return 0;
}