#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void TraverseList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void ReverseTraverseList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}

int main()
{
    struct node *head, *second, *third, *tail;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));

    head->prev = NULL;
    head->data = 10;
    head->next = second;

    second->prev = head;
    second->data = 20;
    second->next = third;

    third->prev = second;
    third->data = 30;
    third->next = tail;

    tail->prev = third;
    tail->data = 40;
    tail->next = NULL;

    printf("Linked list : \n");
    TraverseList(head);
    printf("\n");

    printf("Linked list in reverse order : \n");
    ReverseTraverseList(tail);
    printf("\n");
}