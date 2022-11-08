#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *creatNode(struct node *head, int data)
{
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        temp = newNode;
    }
    else
    {
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

void traverseList(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insersionAtBegin(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;            // returns updated head of linked list
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
    struct node *head = NULL;
    int select, choice;
    
    printf("First creat a Linkedlist ...\n");

    do
    {
        printf("Enter 1 to add nodes in Linkedlist and 0 to stop creating list\n");
        scanf("%d", &select);

        if (select == 1)
        {
            int data;
            printf("Enter number : ");
            scanf("%d", &data);
            head = creatNode(head, data);
        }

        else if (select == 0)
        {
            printf("Created Linkedlist : \n");
            traverseList(head);
            printf("\n");
            break;
        }

    } while (1);

    while (1)
    {
        printf("Enter 1 to insert at Head, 2 to desired index value, 3 to end, 5 to exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            printf("Enter number : ");
            scanf("%d", &data);
            head = insersionAtBegin(head, data);            // insert_begin variable stores the new head
            printf("After insersion at begin : \n");
            traverseList(head);
            printf("\n");
        }

        else if (choice == 2)
        {
            int data, index, value;
            printf("Enter index : ");
            scanf("%d", &index);

            printf("Enter number : ");
            scanf("%d", &data);
            
            printf("Enter 1 if you want to add at given index, 0 to add before the index, 2 to add after the index\n");
            scanf("%d", &value);
            
            if(value == 1)
                index = index + 0;
            else if (value == 0)
                index = index - 1;
            else if (value == 2)
                index = index + 1;
                
            insersionAtIndex(head, data, index);
            printf("After insersion at index %d : \n", index);
            traverseList(head);
            printf("\n");
        }

        else if (choice == 3)
        {
            int data;
            printf("Enter number : ");
            scanf("%d", &data);
            insersionAtEnd(head, data);
            printf("After insersion at end : \n");
            traverseList(head);
            printf("\n");
        }

        else if (choice == 5)
            break;
    }

    return 0;
}