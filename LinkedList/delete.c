#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void printnodes(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("=> %d ", ptr->data);
        ptr = ptr->next;
    }
}
// ==================================================  Deleting the first Node
struct node *deletefirstnode(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
};

// =================================================  Deleting the node at the given index
struct node *deletenodeatindex(struct node *head, int index)
{
    struct node *p = head;
    int i = 0;
    for (int i = 0; i != index - 1; i++)
    {
        p = p->next;
    }
    struct node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
};

// ==================================================  Deleting the node at the end
struct node *deleteatend(struct node *head)
{
    struct node *ptr = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
};

//===================================================  Deleting te node of given value
struct node *deletebyvalue(struct node *head, int value)
{
    struct node *ptr = head;
    struct node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    if (q->data == value)
    {
        ptr->next = q->next;
        free(q);
    }
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

    fourth->data = 67;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;
    printf("Before deletion");
    printnodes(head);
    // head = deletefirstnode(head);
    // head = deletenodeatindex(head, 2);
    // head = deleteatend(head);
    head = deletebyvalue(head, 67);
    printf("\nAfter deletion");
    printnodes(head);

    return 0;
}