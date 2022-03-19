#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createnode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = (key);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}


int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getbalancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getheight(x->right), getheight(x->left) + 1);
    y->height = max(getheight(y->right), getheight(y->left) + 1);
    return x;
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getheight(x->right), getheight(x->left))+1;
    y->height = max(getheight(y->right), getheight(y->left))+1;

    return y;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return createnode(key);
    }
    if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = insert(node->right, key);
    }
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int bf = getbalancefactor(node);

    //  left left case
    if (bf > 1 && key < node->left->data)
    {
        return rightrotate(node);
    }
    // right right case
    if (bf < -1 && key > node->right->data)
    {
        return leftrotate(node);
    }
    // left right case
    if (bf > 1 && key > node->left->data)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    // right left case
    if (bf < -1 && key < node->right->data)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preorder(root);

    return 0;
}