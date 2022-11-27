#include <stdio.h>
#include <assert.h>

int memcmp(char *str1, char *str2, size_t n)
{
  size_t i;  
  char * cstr1 = (char*) str1;
  char * cstr2 = (char*) str2;

  for (i = 0; i < n; i++, cstr1++, cstr2++)
  {
    if (*cstr1 < *cstr2)
    {
      return -1;
    }
    else if (*cstr1 > *cstr2)
    {
      return 1;
    }
  }
  return 0;
} 

int main()
{
    assert(memcmp("str", "str", 3) == 0);
    assert(memcmp("str1", "str", 4) > 0);
    assert(memcmp("str", "str2", 4) < 0);
    
    return 0;
}