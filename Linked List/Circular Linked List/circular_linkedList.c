#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void listTraverse(struct node *ptr)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = ptr;
    printf("%d ", temp->data);
    temp = temp->next;

    while (temp != ptr)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *head, *second, *third, *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 45;
    head->next = second;

    second->data = 50;
    second->next = third;

    third->data = 55;
    third->next = fourth;

    fourth->data = 60;
    fourth->next = head;

    listTraverse(head);

    

    return 0;
}