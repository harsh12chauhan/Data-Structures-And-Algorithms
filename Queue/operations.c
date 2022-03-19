#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Is Overflow");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dqueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Is Empty");
    }
    else
    {
        int a = -1;
        q->f++;
        a = q->arr[q->f];
        return a;
    }
}
int main()
{
    struct queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 54);
    enqueue(&q, 12);
    printf("The Dqueue Element is %d\n", dqueue(&q));
    if (isEmpty(&q))
    {
        printf("Queue is empty");
    }
    else if (isFull(&q))
    {
        printf("Queue is Full");
    }
    else
    {
        printf("Elements are there !");
    }

    return 0;
}