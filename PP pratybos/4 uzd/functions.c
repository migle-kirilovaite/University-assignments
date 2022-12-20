#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


void validateChoice(int *choice)
{
    if(*choice != 0 && *choice != 1 && *choice != 2 && *choice != 3)
    {
        while(getchar() != '\n');
        printf("\nIvestas skaicius neatitinka jokio pasirinkimo.\n");
        printf("Iveskite skaiciu kuris atitinka pasirinkima: ");
        scanf("%d", choice);
        validateChoice(choice);
    }
}

void append(struct Node** head, int newData)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head;

    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL)
    {
       *head = newNode;
       return;
    }
    
    while (last->next != NULL)
    {
        last = last->next;
    }
        
    last->next = newNode;
    return;
}

void createList(struct Node** head)
{
    FILE *inFile;
    char *inFileName = (char*)malloc(255);
    int element;

    printf("\nIveskite failo pavadinima kuriame yra reikalingi duomenys:");
    scanf("%s", inFileName);

    if ((inFile = fopen(inFileName, "r")) == NULL)
    {
        printf("\nNepavyko atidaryti skaitymo failo. Bandykite dar karta.\n");
        fclose(inFile);
        createList(head);
    }
    else
        printf("\nSkaitymo failas atidarytas sekmingai!\n");

    while(fscanf(inFile,"%d", &element) != EOF)
    {
        append(head, element);
    }

    free(inFileName);
    fclose(inFile);
}

void printList(struct Node** head)
{
    if (*head == NULL)
    {
        printf("\nKlaida! Tuscias sarasas.\n");
    }
    else 
        printf("\nJusu vienpusis sarasas: \n");

    struct Node* temp;
    temp = *head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node * insertBefore(struct Node *head, int num, int before)
{
    struct Node *currentNode = head;
    struct Node *newNode;

    if (currentNode->data != before)
    {
        while ( currentNode->next->data != before) 
        {
            currentNode = currentNode->next;
            if(currentNode->next == NULL)
            {
                while(getchar() != '\n');
                printf("Ivestas elementas nebuvo rastas. Iveskite kita:");
                scanf("%d", &before);
                return head = insertBefore(head, num, before);
            }
        }
        
        newNode = (struct Node *) malloc(sizeof(struct Node));

        newNode->data = num;
        newNode->next= currentNode->next;
        currentNode->next = newNode;
    }
    else 
    {
        newNode = (struct Node*) malloc(sizeof(struct Node));

        newNode->data = num;
        newNode->next = head;
        head= newNode;
    }

    return head;
}
    
void actions(int choice, struct Node** head)
{
    if(choice == 0) //0 sukuria sarasa (is duoto duomenu failo)
    {
        *head = NULL;
        createList(head);
    }
    else if(choice == 1) //1 isspausdina sarasa
        printList(head);
    else if(choice == 2) //2 iterpia pries reiksme nurodyta elementa nauja elementa.
    {
        if(*head != NULL)
        {
            int num;
            int before;

            printf("\nIveskite elementa kuri norite iterpti: ");
            scanf("%d", &num);
            printf("Iveskite elementa pries kuri bus iterpiama: ");
            scanf("%d", &before);

            *head = insertBefore(*head, num, before);
        }
        else 
            printf("\nKlaida! Sarasas tuscias.\n");   
    }
    else //3 iseina is programos
        exit(0);
}
