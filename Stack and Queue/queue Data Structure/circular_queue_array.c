#include <stdio.h>
#define N 10
int queue[N];
int front = -1, rear = -1;

void enque(int x)
{
    if ((rear + 1) % N == front)
        printf("Queue overflow\n");

    else if (front == -1 & rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void deque()
{
    if (front == -1 & rear == -1)
        printf("Queue underflow\n");

    else if (front == rear)
        front = rear = -1;

    else
    {
        printf("Dequed element = %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    int i = front;
    while (i != rear)
    {
        printf("%d\n", queue[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", queue[i]);
}

int main()
{
    deque();
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    enque(4);
    enque(4);
    enque(4);
    enque(4);
    enque(4);
    enque(4);
    enque(4);
    display();
    // peek();
    deque();
    deque();
    display();
    deque();
    display();
    
    return 0;
}