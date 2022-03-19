#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

//=============================================================== Transverse or linked list
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//================================================================ insertion at Begining
struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
};

//================================================================ insertion at given Index
struct node *insertatindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

//================================================================ insertion at End
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
};

//================================================================ insertion at after the given node
struct node *insertafternode(struct node *head, struct node *prevnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
};

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = forth;

    forth->data = 12;
    forth->next = NULL;

    printf("Before Inserting\n");
    traversal(head);
    // head = insertatfirst(head , 56);
    // head = insertatindex(head, 25, 2);
    // head = insertatend(head, 25);
    printf("After Inserting\n");
    head = insertafternode(head, third, 25);
    traversal(head);
    return 0;
}