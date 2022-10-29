#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enque(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL & rear == NULL)
        front = rear = newnode;

    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void deque()
{
    if(front == NULL && rear == NULL)
        printf("Queue underflow\n");

    else{
        printf("Dequed element is %d\n", front->data);
        front = front->next;
    }    
}

void peek()
{
    printf("Top element is %d\n", front->data);
}

void display()
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }       
}

int main()
{
    deque();
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    display();
    peek();
    deque();
    display();
    deque();
    display();
    
    return 0;
}