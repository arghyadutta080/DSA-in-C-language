#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void listTraverse(struct node *ptr)
{
    struct node *temp = ptr;
    printf("%d ", temp->data);
    temp = temp->next;

    while (temp != ptr)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct node *insertAtBegin(struct node *ptr, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    struct node *temp = ptr;
    while (temp->next != ptr)
        temp = temp->next;
    temp->next = new;
    new->next = ptr;
    return new;
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

    printf("Old linkedList : \n");
    listTraverse(head);
    printf("\n");

    int new_begin_data = 40;
    head = insertAtBegin(head, new_begin_data);
    printf("Insersion after begining in linkedList : \n");
    listTraverse(head);
    printf("\n");

    new_begin_data = 35;
    head = insertAtBegin(head, new_begin_data);
    printf("Insersion after begining in linkedList : \n");
    listTraverse(head);

    return 0;
}