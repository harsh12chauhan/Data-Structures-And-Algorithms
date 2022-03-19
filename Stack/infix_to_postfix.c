#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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
// ============================================== to see the top most element of stack
int stacktop(struct stack *sp)
{
    return sp->arr[sp->top];
}

// ================================================== PUSH the elements to the stack
void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Is Overflow ! Cannot push %d in the Stack ", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// ================================================== POP the elements form the stack
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Is Underflow ! Cannot pop from the Stack");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
// =================================================== checking th precedence of the operators
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
//  ============================================= checking that if the character is  operator or operent
int isoperater(char ch)
{
    if (ch == '*' || ch == '/' | ch == '+' | ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// ======================================= function to convert infix expression to postfix expression
char *infixtopostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isoperater(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stacktop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

// ============================================================== main
int main()
{
    char *infix = "a+b-c";
    printf(" Postfix is %s", infixtopostfix(infix));

    return 0;
}