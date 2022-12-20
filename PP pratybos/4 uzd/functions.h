#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct Node
{
    int data;
    struct Node* next;
};

void validateChoice(int *choice);
void actions(int choice, struct Node** head);
void createList(struct Node** head);
void append(struct Node** head, int newData);
struct Node * insertBefore(struct Node *head, int num, int before);

#endif