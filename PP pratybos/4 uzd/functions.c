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

struct Node * insertAfter(struct Node **head)
{
    int num;
    int previous;

    printf("\nIveskite elementa kuri norite iterpti: ");
    scanf("%d", &num);
    printf("Iveskite elementa po kurio bus iterpiama: ");
    scanf("%d", &previous);


    struct Node *currentNode = *head;
    struct Node *newNode;

    while (currentNode->data != previous) 
    {
        currentNode = currentNode->next;     
        if(currentNode == NULL)
        {
            break;
        }
    } 

    if(currentNode != NULL)
    {
        newNode = (struct Node *) malloc(sizeof(struct Node));

        newNode->data = num;
        newNode->next= currentNode->next;
        currentNode->next = newNode;
    }
    else 
    {
        printf("\nNepavyko sarase rasti ivesto skaiciaus.\n");
        *head = insertAfter(head);
    }

    return *head;
}

void actions(int choice, struct Node** head)
{
    if(choice == 0)
    {
        *head = NULL;
        createList(head);

        if (*head == NULL)
        {
        printf("Klaida! Tuscias sarasas.\n");
        }
    }
    else if(choice == 1)
    {
        printList(head);
    }
    else if(choice == 2)
    {
        if(*head != NULL)
        {
            *head = insertAfter(head);
        }
        else 
            printf("\nKlaida! Sarasas tuscias.\n");   
    }
    else
        exit(0);
}
