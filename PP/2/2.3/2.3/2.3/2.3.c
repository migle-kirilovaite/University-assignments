#include <stdio.h>

int main()
{
    int num;
    char even[] = "Lyginis";
    char odd[] = "Nelyginis";

    scanf("%d", &num);

    printf("%s",(num % 2 == 0 ? even : odd));

    return 0;
}
