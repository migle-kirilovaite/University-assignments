#include <stdio.h>
#include <assert.h>
#include "functions.h"

int countSame(struct Node* head1, struct Node* head2)
{
    struct Node* currentNode1 = head1;
    struct Node* currentNode2 = head2;
    int counter = 0;

    while(currentNode1 != NULL && currentNode2 != NULL)
    {
        if(currentNode1->data == currentNode2->data)
            ++counter;

        currentNode1 = currentNode1->next;
        currentNode2 = currentNode2->next;
    }

    return counter;
}

int main()
{
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* head3 = NULL;
    struct Node* head4 = NULL;
    struct Node* temp;
    
    append(&head1, 1);
    append(&head1, 2);
    append(&head1, 3);
    assert(head1 != NULL);
    printf("Append funkcijos testas ivykdytas sekmingai.");

    createList(&head2);
    assert(head2 != NULL);
    append(&head4, 10);
    append(&head4, 20);
    append(&head4, 30);
    append(&head4, 15);
    assert(countSame(head4, head2) == 4);

    append(&head3, 1);
    append(&head3, 2);
    append(&head3, 3);
    assert(countSame(head1, head3) == 3);

    temp = head1;
    assert(countSame(head1, temp) == 3);
    printf("\nSutampantys sarasai palyginti bei funcija createList patikrinta sekmingai.");

    assert(countSame(insertBefore(head1, 2, 1), temp) == 0);
    assert(countSame(insertBefore(head1, 2, 1),insertBefore(temp, 2, 1)) == 4);
    printf("\nPo insertBefore funkcijos sarasai palyginti sekmingai.");

    printf("\nVisi testai buvo ivykdyti.");
    
    return 0;
}