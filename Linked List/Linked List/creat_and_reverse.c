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

struct node *reverseNode(struct node *head){
    struct node *prev, *current, *next;
    prev = NULL;
    current = head;
    next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void display(struct node *head)
{
    struct node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("\n");
    printf("No. of elements in Linkedlist = %d\n", count);
}

int main()
{
    struct node *head = NULL;

    int choice;
    do
    {
        printf("Enter 1 to add nodes in Linkedlist, 0 to display and count elements, 2 to reverse list and 5 to exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            printf("Enter number : ");
            scanf("%d", &data);
            head = creatNode(head, data);
        }

        else if (choice == 0)
        {
            display(head);
        }

        else if (choice  == 2)
        {
            head = reverseNode(head);
        }

        else if (choice == 5)
            break;

    } while (1);

    return 0;
}