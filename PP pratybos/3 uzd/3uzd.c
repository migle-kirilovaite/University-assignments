/* 
   LSP: 2213745 
   Email: migle.kirilovaite@mif.stud.vu.lt
   Uzd. Nr.: 3
   Variantas: 1 (Parašyti funkciją, kuri iš duoto teksto išmeta žodžius, 
   kurie prasideda ir baigiasi ta pačia raide (tarpų skaičius turi likti nepakitęs))
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ValidateOpenFiles(FILE** in_file, FILE** out_file, long *size, char **arr)
{
    char *infilename = (char*)malloc(255);
    char *outfilename = (char*)malloc(255);

    printf("Iveskite skaitymo failo pavadinima:");
    scanf("%s", infilename);
    printf("Iveskite rasymo failo pavadinima:");
    scanf("%s", outfilename);

    if ((*in_file = fopen(infilename, "r")) == NULL)
    {
        printf("Nepavyko atidaryti skaitymo failo \n");
        exit(1);
    }
    else
        printf("Skaitymo failas atidarytas sekmingai!\n");

    if((*out_file = fopen(outfilename, "w+")) == NULL)
    {
        printf("Nepavyko nei sukurti, nei atidaryti irasymo failo");
        exit(2);
    }
    else 
        printf("Irasymo failas atidarytas/sukurtas sekmingai!\n");

    free(infilename);
    free(outfilename);
    
    fseek (*in_file , 0 , SEEK_END); 
    *size = ftell (*in_file);
    rewind (*in_file);

    *arr = (char*) malloc (sizeof(char)*(*size)); 
    if (*arr == NULL)
    {
        printf("Ivyko atminties klaida.");
        exit(3);
    }
}

void PrintLine(FILE* in_file, FILE* out_file, char *arr)
{
    char *token;
    char s[2] = " ";
    char line[255] = {0};
    int j = 0;
    int wordsize;

    for(int i = 0; i < 255; ++i) 
    {
        line[i]=*(arr + i);
    }
    token = strtok(line, s);

    while(j < 255 && token != NULL) 
    {   
        while(line[j] == ' ')
        {
            fprintf(out_file, " ");
            j++;
        }
        
        if(token[0] != token[strlen(token) - 1])
        {
            fprintf(out_file, "%s ", token);
        }
        j += strlen(token); 
        token = strtok(NULL, s);
        j++;

    }
    fprintf(out_file, "\n");
}

int main()
{
    FILE *in_file;
    FILE *out_file;
    long size;
    char *arr;

    ValidateOpenFiles(&in_file, &out_file, &size, &arr);
    
    while(!feof(in_file) && !ferror(in_file))
    {
        fgets(arr, size, in_file); 
        PrintLine(in_file, out_file, arr);
    }

    free(arr);
    fclose(in_file);
    fclose(out_file);

    return 0;
}