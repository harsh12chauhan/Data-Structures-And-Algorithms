#include <stdio.h>
#include <stdlib.h>

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

// ================================================== PUSH the elements to the stack
void push(struct stack *ptr, char val)
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
char pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
    printf("Stack Is Underflow ! Cannot pop from the Stack");
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
// ================================================= PEEK operations in stack
// int peek(struct stack *ptr, int i)
// {
//     int arryindex = ptr->top - i + 1;
//     if (arryindex < 0)
//     {
//         printf("Not a Valid index number");
//         return -1;
//     }
//     else
//     {
//         return ptr->arr[arryindex];
//     }
// }

int parenthesis(char*exp){
    struct stack *sp ;
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i]!= '\0'; i++)
    {
        if (exp[i]=='(')
        {
           push(sp, '(') ;
        }
        else if (exp[i] ==')')
        {
          if (isEmpty(sp))
          {
             return 0;
          }
          pop(sp);
          
        } 
    }
    if (isEmpty(sp))
    {
        return 1;
    }else
    {
        return 0;
    }
    
    
}
// ================================================= main
int main()
{
    char *exp = "((10*8))*(9)";
    if (parenthesis(exp))
    {
        printf(" The Parenthesis is matched ");
    }
    else
    {
        printf(" The Parenthesis is not  matched ");
    }
    return 0;
}