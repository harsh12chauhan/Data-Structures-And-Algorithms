#include <stdio.h>
#include <stdlib.h>
struct circilarQueue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct circilarQueue *q)
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
int isFull(struct circilarQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct circilarQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Is Overflow");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqued Element is %d\n", val);
    }
}

int dqueue(struct circilarQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Is Empty");
    }
    else
    {
        int a = -1;
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        return a;
    }
}
int main()
{
    struct circilarQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 54);
    enqueue(&q, 12);
    enqueue(&q, 42);
    printf("The Dqueue Element is %d\n", dqueue(&q));
    printf("The Dqueue Element is %d\n", dqueue(&q));
    printf("The Dqueue Element is %d\n", dqueue(&q));
    enqueue(&q, 24);
    enqueue(&q, 25);

    return 0;
}