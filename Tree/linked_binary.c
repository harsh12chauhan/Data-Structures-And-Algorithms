#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void traversingtoleft(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("=> %d ", ptr->data);
        ptr = ptr->left;
    }
}
void traversingtoright(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("=> %d ", ptr->data);
        ptr = ptr->right;
    }
}
struct node *createnode( int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int main()
{
    // ==========================================method 1 for tree (not recommanded)
    // struct node *p ;
    // p = (struct node *)malloc(sizeof(struct node));
    // p->data = 2;
    // p->left = NULL;
    // p->right = NULL;

    // struct node *p1;
    // p1 = (struct node *)malloc(sizeof(struct node));
    // p1->data = 1;
    // p1->left = NULL;
    // p1->right = NULL;

    // struct node *p2;
    // p2 = (struct node *)malloc(sizeof(struct node));
    // p2->data = 4;
    // p2->left = NULL;
    // p2->right = NULL;
// =========================================method 2 for tree(recommamded)
    struct node *p =  createnode(3);
    struct node *p1 =  createnode(4);
    struct node *p2 =  createnode(2);


    p->left = p1;
    p->right = p2;
    
    traversingtoright(p);
    traversingtoleft(p);
    return 0;
}