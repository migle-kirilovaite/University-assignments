#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    double x;
    double y;
} Point;

typedef struct Stack
{
    Point *arr;
    int size;

} Stack;

void initStack(Stack *stack)
{
    stack->size = 5;
    for(int i = 0; i < stack->size; ++i)
    {
       stack->arr[i].x = i + 1; 
       stack->arr[i].y = i + 1; 
    }
}

void printStack(Stack *stack)
{
    for(int i = 0; i < stack->size; ++i)
    {
       printf("(%.1lf,%.1lf)", stack->arr[i].x, stack->arr[i].y); 
       printf("%.1lf \n", sqrt(pow((stack->arr[i].x- 0), 2) + pow ((stack->arr[i].y - 0), 2)));
    }

}

int getStack(Stack *stack)
{
    return sizeof(*stack->arr);
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

Point top(Stack *stack)
{
    return stack->arr[sizeof(Stack)];
}

Point pop(Stack *stack)
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
    stack->arr = (Point*)malloc(sizeof(Point));

    initStack(stack);
    printStack(stack);
    getStack(stack);
    push(stack, 1);
    destroyStack(stack);

    return 0;
}