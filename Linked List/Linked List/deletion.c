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

struct node *delFromBegin(struct node *ptr)
{
    struct node *p = ptr;
    ptr = ptr->next;
    free(p);
    return ptr;
}

void delFromEnd(struct node *ptr)
{
    struct node *p = ptr;
    struct node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
}

void delFromMiddle(struct node *ptr, int index)
{
    struct node *p = ptr;
    struct node *q = p->next;
    for (int i = 1; i < index; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
}

int main()
{
    struct node *head, *second, *third, *fourth, *fifth, *sixth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));

    head->data = 45;
    head->next = second;

    second->data = 50;
    second->next = third;

    third->data = 55;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = fifth;

    fifth->data = 70;
    fifth->next = sixth;

    sixth->data = 77;
    sixth->next = NULL;

    printf("Original Linkedlist : \n");
    traverseList(head);
    printf("\n");

    struct node *begin = delFromBegin(head);
    printf("After delete from the beggining of Linkedlist : \n");
    traverseList(begin);
    printf("\n");

    int index = 2;

    delFromMiddle(begin, index);
    printf("After delete element from the index %d of Linkedlist : \n", index);
    traverseList(begin);
    printf("\n");

    delFromEnd(begin);
    printf("After delete from the end of Linkedlist : \n");
    traverseList(begin);
    printf("\n");

    return 0;
}