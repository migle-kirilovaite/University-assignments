#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int size;

} Stack;

void initStack(Stack *stack)
{
    for(int i = 0; i < stack->size; ++i)
    {
       stack->arr[i] = 0; 
    }
}

void printStack(Stack *stack)
{
    for(int i = 0; i < stack->size; ++i)
    {
       printf("%d", stack->arr[i]); 
    }

}

int getStack(Stack *stack)
{
    return sizeof(Stack);
}

void push(Stack *stack, int value)
{
    Stack *stack2;
    stack2 = realloc(stack, sizeof(Stack) + value);
    if(stack2)
    {   
        stack = stack2;
    }
}

int top(Stack *stack)
{
    return stack->arr[sizeof(Stack)];
}

int pop(Stack *stack)
{
    Stack *stack2;
    stack2 = realloc(stack, sizeof(Stack) - 1);
    if(stack2)
    {   
        stack = stack2;
        return top(stack);
    }
}

void destroyStack(Stack *stack)
{
    free(stack);
}


int main()
{

    Stack *stack = (Stack*)malloc(sizeof(Stack));

    initStack(stack);
    printStack(stack);
    getStack(stack);
    push(stack, 1);
    destroyStack(stack);

    return 0;
}