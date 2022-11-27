#include <stdio.h>
#include <assert.h>

char *strchr(char *str, int ch)
{
    do
    {
        if (*str == ch) 
            return str;
    } 
    while (*str++);

    return NULL;
}

int main()
{
    assert(strchr("str", 'p') == NULL);
    assert(strchr("str", 's') != NULL);
    
    return 0;
}