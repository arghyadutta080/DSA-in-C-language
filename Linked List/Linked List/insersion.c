#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverseList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insersionAtBegin(struct node *ptr, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = ptr;
    ptr = new;
    return ptr; // returns updated head of linked list
}

void insersionAtEnd(struct node *ptr, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    struct node *p = ptr;
    while (p->next != NULL)
        p = p->next;
    p->next = new;
    new->next = NULL;
}

void insersionAtIndex(struct node *ptr, int data, int index)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    struct node *p = ptr;
    for (int i = 1; i < index; i++)
        p = p->next;
    new->next = p->next;
    p->next = new;
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

    printf("Original Linkedlist : \n");
    traverseList(head);
    printf("\n");

    int new_begin_data = 40;

    head = insersionAtBegin(head, new_begin_data); // insert_begin variable stores the new head
    printf("After insersion at begin : \n");
    traverseList(head);
    printf("\n");

    int new_end_data = 60;

    insersionAtEnd(head, new_end_data);
    printf("After insersion at end : \n");
    traverseList(head);
    // traverseList(head);
    printf("\n");

    int new_middle_data = 80;
    int index = 2;
    
    insersionAtIndex(head, new_middle_data, index);
    printf("After insersion at index %d : \n", index);
    traverseList(head);
    // traverseList(head);
    printf("\n");

    return 0;
}