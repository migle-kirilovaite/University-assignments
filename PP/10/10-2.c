#include <stdio.h>
#include <assert.h>

int strcmp (char * s1, char * s2)
{
    for(; *s1 == *s2; ++s1, ++s2)
        if(*s1 == 0)
            return 0;
    return *s1 < *s2 ? -1 : 1;
}

int main()
{
    assert(strcmp("str","Str") != 0);
    assert(strcmp("str","str") == 0);
    assert(strcmp("str","Str") > 0);
    assert(strcmp("Str","str") < 0);
    
    return 0;
}