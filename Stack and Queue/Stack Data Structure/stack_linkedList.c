#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL; // here 'top' is nothing but the 'head' of the Linked List

void push(int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == NULL)
        printf("Stack Underflow");
    else
    {
        printf("Popped data = %d\n", top->data);
        top = top->next;
    }
}

void display()
{
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop();
    display();

    // we can use a while loop with switch-case statement to call functions instead of this direct function call

    return 0;
}