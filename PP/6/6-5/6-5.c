#include <stdio.h>

int main()
{   
    int c = 0;
    char name[50], mail[20], domain_name[10];

    printf("Iveskite el.pasta: \n");

    while((scanf("%[^@]@%[^.].%s", &name, &mail, &domain_name) != 3))
    {
        printf("Netinkama ivestis\n");
        do 
        { 
            c = getchar(); 
        } while (c != '\n' && c != EOF);
    }

    printf("@%s.%s \n", mail, domain_name);

    FILE *in_file;
    in_file = fopen("emails.txt", "a");

    if (in_file == NULL)
    {
        printf("Failas negali buti atidarytas \n");
        return 1;
    }

    printf("Failas atidarytas sekmingai \n");

    fprintf(in_file, "\n %s@%s.%s", name, mail, domain_name);
    fclose(in_file);

    printf("Pastas ivestas i faila. \n");

    return 0;
}