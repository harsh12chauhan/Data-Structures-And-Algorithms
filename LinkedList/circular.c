#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// =================================== transversal
void printnodes(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("=>%d", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// ===============================================  inserting at the Begining of the node
struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head->next;
    do
    {
        p = p->next;
    } while (p->next != head);
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
};

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = head;

    printf("Before insertion\n");
    printnodes(head);
    head = insertatfirst(head, 54);
    printf("\nAfter insertion\n");
    printnodes(head);

    return 0;
}