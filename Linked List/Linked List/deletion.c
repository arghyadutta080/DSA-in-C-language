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
    if (head == NULL)
        printf("List is empty");

    else
    {
        struct node *ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

struct node *delFromBegin(struct node *head)
{
    if (head == NULL)
        printf("List is empty");

    else
    {
        struct node *p = head;
        head = head->next;
        free(p);
        return head;
    }
}

void delFromEnd(struct node *head)
{
    if (head == NULL)
        printf("List is empty");

    else
    {
        struct node *p = head;
        struct node *q = p->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
    }
}

void delFromMiddle(struct node *head, int index)
{
    if (head == NULL)
        printf("List is empty");

    else
    {
        struct node *p = head;
        struct node *q = p->next;
        for (int i = 1; i < index; i++)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
    }
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
        printf("Enter 1 to delete from Head, 2 to del from desired index value, 3 to del from end, 5 to exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            head = delFromBegin(head);
            printf("After delete from the beggining of Linkedlist : \n");
            traverseList(head);
            printf("\n");
        }

        else if (choice == 2)
        {
            int index, value;
            printf("Enter index : ");
            scanf("%d", &index);

            printf("Enter 1 if you want to del from given index, 0 to del previous index, 2 to del the next index\n");
            scanf("%d", &value);

            if (value == 1)
                index = index + 0;
            else if (value == 0)
                index = index - 1;
            else if (value == 2)
                index = index + 1;

            delFromMiddle(head, index);
            printf("After delete element from the index %d of Linkedlist : \n", index);
            traverseList(head);
            printf("\n");
        }

        else if (choice == 3)
        {
            delFromEnd(head);
            printf("After delete from the end of Linkedlist : \n");
            traverseList(head);
            printf("\n");
        }

        else if (choice == 5)
            break;
    }

    return 0;
}