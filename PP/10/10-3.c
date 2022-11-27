#include <stdio.h>
#include <assert.h>

int strncmp( const char * s1, const char * s2, size_t n )
{
    while ( n && *s1 && ( *s1 == *s2 ) )
    {
        ++s1;
        ++s2;
        --n;
    }
    if ( n == 0 )
    {
        return 0;
    }
    else
    {
        return ( *(unsigned char *)s1 - *(unsigned char *)s2 );
    }
}

int main()
{
    assert(strncmp("str","Str", 2) != 0);
    assert(strncmp("str","stR", 2) == 0);
    assert(strncmp("str","Str", 2) > 0);
    assert(strncmp("Str","str", 2) < 0);
    
    return 0;
}