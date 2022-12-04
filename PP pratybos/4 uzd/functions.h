#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct Node
{
    int data;
    struct Node* next;
};

void validateChoice(int *choice);
void actions(int choice, struct Node** head);

#endif