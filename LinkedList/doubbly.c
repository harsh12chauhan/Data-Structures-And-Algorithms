#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*prev;
    struct node*next;
};
// ========================================= traversing the node in previous node
void traversingtoprev(struct node*head){
    struct node*ptr = head;
    while (ptr!= NULL)
    {
        printf("=> %d ",ptr->data);
        ptr = ptr->prev;
    }
}
// ========================================= traversing the node in next node
void traversingtonext(struct node*head){
    struct node*ptr = head;
    while (ptr!= NULL)
    {
        printf("=> %d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
struct node*head;
struct node*second;
struct node*third;
struct node*fourth;
struct node*fifth;

head = (struct node*)malloc(sizeof(struct node));
second = (struct node*)malloc(sizeof(struct node));
third = (struct node*)malloc(sizeof(struct node));
fourth = (struct node*)malloc(sizeof(struct node));
fifth = (struct node*)malloc(sizeof(struct node));

head->prev = NULL;
head ->data = 12;
head->next = second;

second->prev = head;
second ->data = 15;
second->next = third;

third->prev = second;
third ->data = 16;
third->next = fourth;

fourth->prev = third;
fourth ->data = 22;
fourth->next = fifth;

fifth->prev = fourth;
fifth ->data = 32;
fifth->next = NULL;
printf("Transversing to next node:-\n");
traversingtonext(head);
printf("\nTransversing to prevous node:-\n");
traversingtoprev(fifth);

return 0;
}