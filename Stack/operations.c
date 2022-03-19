#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// ========================================== check's that if the stack is Empty
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// ========================================== check's that if the stack is Full
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// ================================================== PUSH the elements to the stack
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Is Overflow ! Cannot push %d in the Stack ",val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// ================================================== POP the elements form the stack 
int pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
    printf("Stack Is Underflow ! Cannot pop from the Stack");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
// ================================================= PEEK operations in stack
int peek(struct stack *ptr, int i)
{
    int arryindex = ptr->top - i + 1;
    if (arryindex < 0)
    {
        printf("Not a Valid index number");
        return -1;
    }
    else
    {
        return ptr->arr[arryindex];
    }
}
// ================================================= main
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Created A Stack Successfully\n");
    printf("Empty : %d\n", isEmpty(sp));
    printf(" Full : %d\n", isFull(sp));
    push(sp, 12);// push the elements to the stack
    push(sp, 42);
    push(sp, 54);
    push(sp, 6);
    printf(" Poped %d from the Stack",pop(sp)); // pop the elements from stack
    printf("Empty : %d\n", isEmpty(sp));
    printf("Full : %d\n", isFull(sp));

    //============================================== peek all the elements of the stack
    for (int j = 0; j <= sp->top + 1; j++)
    {
        printf(" The Element At position %d is : %d\n", j, peek(sp, j));
    }
    return 0;
}