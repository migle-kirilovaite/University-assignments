/* 
   LSP: 2213745 
   Email: migle.kirilovaite@mif.stud.vu.lt
   Uzd. Nr.: 2
   Variantas: 1 (Įvesti sveiką skaičių N. Užpildyti matricą N*N sveikais skaičiais 1, 2, 3, ..., surašytais spirale.)
*/ 

#include <stdio.h>

int validation ()
{   
    int n;
    char character;

    if((scanf("%d%c", &n, &character) != 2 ) || (character != '\n')) 
    {
        printf("Netinkama ivestis! Iveskite sveika teigiama skaiciu! \n");
        while(getchar() != '\n'); 
        n = validation();
    }
    else if (n <= 0)
    {
        printf("Netinkama ivestis! Iveskite sveika teigiama skaiciu! \n");
        n = validation();
    }

    return n;
}

void input(int *n)
{
    printf("Iveskite sveika skaiciu N: \n" );
    *n = validation (); 
}

void forming_spiral_matrix(int n, int matrix[n][n])
{
    int number = 1; 
    int top = 0, 
        bottom = n - 1, 
        left = 0, 
        right = n - 1;
    
    while (number <= n * n)
    {
        for (int i = left; i <= right; ++i)
        {
            matrix[top][i] = number;
            ++number;
        }
        ++top;

        for (int i = top; i <= bottom; ++i)
        {
            matrix[i][right] = number;
            ++number;
        }
        --right;

        for (int i = right; i >= left; --i)
        {
            matrix[bottom][i] = number;
            ++number;
        }
        --bottom;

        for (int i = bottom; i >= top; --i)
        {
            matrix[i][left] = number;
            ++number;
        }
        ++left;
   }
}

void output(int n, int matrix[n][n])
{
    for (int i = 0; i < n; ++i)
   {
        for(int j = 0; j < n; ++j)
        {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
   }
}

int main()
{
    int n;  
    input(&n);
    int matrix[n][n];
    forming_spiral_matrix(n, matrix);
    output(n, matrix);
    
    return 0;
}