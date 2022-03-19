#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};
// ======================================== function for printing all the elements of the linkedlist
void transversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// ======================================= enqueue function for insertion of the element to the queue
void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is Full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
// =======================================dequeue function for deletion of the element from the queue
int dequeue()
{
    if (f == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        struct node *ptr = f;
        f = f->next;
        int val = ptr->data;
        free(ptr);
        return val;
    }
}
int main()
{
    enqueue(45);
    enqueue(5);
    enqueue(12);
    enqueue(87);
    transversal(f);
    printf("Dequeued element is :%d\n",dequeue());
    printf("Dequeued element is :%d\n",dequeue());
    transversal(f);
    return 0;
}