#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void listTraverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head, *second, *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 45;
    head->next = second;

    second->data = 50;
    second->next = third;

    third->data = 55;
    third->next = NULL;

    listTraverse(head);

    return 0;
}