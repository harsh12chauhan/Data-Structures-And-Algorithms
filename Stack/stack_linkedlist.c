#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// ======================================to print all the elements of stack
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// ==================================== to check that if the stack is empty
int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// ==================================== to check that if the stack is full
int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//  ========================================== Push method for pushing the elements in stack
struct node *push(struct node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack is Overflow");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
//  ========================================== Pop method for poping the elements from stack
int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}
// ========================================== Peek method for printing the value at the given index
int peek(struct node *top, int pos)
{
    struct node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
           return ptr->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    struct node *top = NULL;
    top = push(top, 125);
    top = push(top, 134);
    top = push(top, 56);
    top = push(top, 76);
    top = push(top, 12);
    top = push(top, 68);
    traversal(top);
    int element = pop(&top);
    printf("\nthe poped element is : %d\n",element);
    traversal(top);
    printf("The Element in Position 3 is : %d\n", peek(top, 3));
    return 0;
}